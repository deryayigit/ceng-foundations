#define _CRT_SECURE_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <iostream>
#include <string>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <map>
#include <thread>
#include <mutex>
#include <ctime>
#include <cctype>

#pragma comment(lib, "ws2_32.lib") 

using namespace std;

mutex io_mutex;

class Utils {
public:
    static string timestamp_now() {
        time_t now = time(0);
        tm* ltm = localtime(&now);
        char ts[64];
        strftime(ts, sizeof(ts), "%Y-%m-%d %H:%M:%S", ltm);
        return string(ts);
    }

    static string service_name(int port) {
        static map<int, string> port_map = {
            {21, "FTP"}, {22, "SSH"}, {23, "Telnet"}, {25, "SMTP"},
            {53, "DNS"}, {80, "HTTP"}, {110, "POP3"}, {143, "IMAP"},
            {443, "HTTPS"}, {3306, "MySQL"}, {3389, "RDP"},
            {853, "DoH"}, {8080, "HTTP-Alt"}, {8443, "HTTPS-Alt"}, {5900, "VNC"}
        };
        if (port_map.count(port)) return port_map[port];
        return "Unknown";
    }

    static string os_guess_from_banner(const string& banner) {
        string banner_lc = banner;
        for (char& c : banner_lc) c = static_cast<char>(tolower(static_cast<unsigned char>(c)));
        if (banner_lc.find("ubuntu") != string::npos) return "Ubuntu-based Linux";
        if (banner_lc.find("debian") != string::npos) return "Debian-based Linux";
        if (banner_lc.find("centos") != string::npos) return "CentOS-based Linux";
        if (banner_lc.find("windows") != string::npos) return "Likely Windows";
        return "";
    }
};

class Port {
private:
    int port;
    string ip;

public:
    Port(const string& ip_, int port_) : ip(ip_), port(port_) {}

    string fetch_banner() {
        SOCKET s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (s == INVALID_SOCKET) return "";

        sockaddr_in target;
        target.sin_family = AF_INET;
        target.sin_port = htons(port);
        inet_pton(AF_INET, ip.c_str(), &target.sin_addr);

        DWORD timeout = 200;
        setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout, sizeof(timeout));

        if (connect(s, (sockaddr*)&target, sizeof(target)) == SOCKET_ERROR) {
            closesocket(s);
            return "";
        }

        static map<string, string> protocol_message = {
            {"HTTP", "HEAD / HTTP/1.0\r\n\r\n"},
            {"SSH", "SSH-2.0-Scanner\r\n"},
            {"SMTP", "EHLO test\r\n"},
            {"FTP", "USER anonymous\r\n"}
        };

        string service = Utils::service_name(port);
        string request = protocol_message.count(service) ? protocol_message[service] : "\r\n";

        send(s, request.c_str(), static_cast<int>(request.size()), 0);

        char buffer[512] = { 0 };
        int bytes = recv(s, buffer, sizeof(buffer), 0);
        closesocket(s);

        return (bytes > 0) ? string(buffer, bytes) : "";
    }

    void scan_tcp() {
        SOCKET s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (s == INVALID_SOCKET) return;

        sockaddr_in target;
        target.sin_family = AF_INET;
        target.sin_port = htons(port);
        inet_pton(AF_INET, ip.c_str(), &target.sin_addr);

        DWORD timeout = 200;
        setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout, sizeof(timeout));

        if (connect(s, (sockaddr*)&target, sizeof(target)) == 0) {
            string service = Utils::service_name(port);
            string banner = fetch_banner();

            lock_guard<mutex> lock(io_mutex);
            cout << Utils::timestamp_now() << " | TCP Port: " << port << " open\n";
            if (!banner.empty())
                cout << "\t[Banner: " << banner.substr(0, 60) << "]\n";
            else
                cout << "\t[Banner not received: Port is open but service may not be responding]\n";
        }
        closesocket(s);
    }

    void scan_udp() {
        SOCKET s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
        if (s == INVALID_SOCKET) return;

        sockaddr_in target;
        target.sin_family = AF_INET;
        target.sin_port = htons(port);
        inet_pton(AF_INET, ip.c_str(), &target.sin_addr);

        const char* test_message = "Test";
        sendto(s, test_message, static_cast<int>(strlen(test_message)), 0, (sockaddr*)&target, sizeof(target));

        char buffer[256];
        sockaddr_in from;
        int fromlen = sizeof(from);
        DWORD timeout = 200;
        setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout, sizeof(timeout));

        int result = recvfrom(s, buffer, sizeof(buffer), 0, (sockaddr*)&from, &fromlen);

        lock_guard<mutex> lock(io_mutex);
        if (result >= 0)
            cout << Utils::timestamp_now() << " | UDP Port " << port << " open\n";
        else
            cout << Utils::timestamp_now() << " | UDP Port " << port << " no response - may be closed or filtered\n";

        closesocket(s);
    }
};

class PortScanner {
private:
    string ip;
    static constexpr int PORTS[15] = { 21,22,23,25,53,80,110,143,443,3306,3389,853,8080,8443,5900 };
    static const int NUM_PORTS = sizeof(PORTS) / sizeof(PORTS[0]);

public:
    PortScanner(const string& target_ip) : ip(target_ip) {}

    string detect_os() {
        string os_guess = "Not detected (No ping reply or TTL not found)";
        string cmd = "ping -n 1 " + ip;
        FILE* pipe = _popen(cmd.c_str(), "r");
        string output;
        char buffer[256];
        while (fgets(buffer, sizeof(buffer), pipe)) output += buffer;
        _pclose(pipe);

        size_t pos = output.find("TTL=");
        if (pos != string::npos) {
            int ttl = stoi(output.substr(pos + 4));
            if (ttl >= 128)       os_guess = "Likely Windows";
            else if (ttl >= 64)   os_guess = "Likely Linux";
            else if (ttl > 0)     os_guess = "Likely Embedded/Router/IoT";
        }
        return os_guess;
    }

    void scan_all() {
        thread threads[NUM_PORTS * 2];
        int idx = 0;
        for (int i = 0; i < NUM_PORTS; ++i) {
            threads[idx++] = thread([=]() {
                Port(ip, PORTS[i]).scan_tcp();
                });
        }
        for (int i = 0; i < NUM_PORTS; ++i) {
            threads[idx++] = thread([=]() {
                Port(ip, PORTS[i]).scan_udp();
                });
        }
        for (int i = 0; i < idx; ++i) threads[i].join();
    }
};

int main() {
    setlocale(LC_ALL, "C");
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        cerr << "WSA failed to initialize.\n";
        return 1;
    }

    string input;
    cout << "Enter IP or domain: ";
    getline(cin, input);

    string ip = input;
    in_addr addr;
    if (inet_pton(AF_INET, input.c_str(), &addr) != 1) {
        addrinfo hints = {}, * res;
        hints.ai_family = AF_INET;
        if (getaddrinfo(input.c_str(), nullptr, &hints, &res) != 0) {
            cerr << "Hostname/IP could not be resolved!\n";
            return 1;
        }
        sockaddr_in* ipv4 = (sockaddr_in*)res->ai_addr;
        ip = inet_ntoa(ipv4->sin_addr);
        freeaddrinfo(res);
    }

    PortScanner scanner(ip);
    cout << "\n[+] Estimated operating system: " << scanner.detect_os() << "\n";
    scanner.scan_all();

    WSACleanup();
    return 0;
}
