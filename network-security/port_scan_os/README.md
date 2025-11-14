Port and Service Scanner with OS Detection

This project is a C++ application capable of estimating the operating system of a remote machine based on its IP address, scanning both TCP and UDP ports, identifying the services running on them, and recording all results with timestamps. It is built directly on top of the Winsock API in Windows and is designed as a practical exercise in low-level network programming rather than a theoretical study.

1. Purpose and Scope

The application begins by resolving the target IP or domain name, then attempts connections across selected TCP and UDP ports. Whenever possible, it retrieves service banners and uses this information to infer the remote system’s OS. All findings are printed to the console and simultaneously written to a log file. The overall goal is to understand the mechanics behind port scanning, banner grabbing, parallel scanning, and basic OS fingerprinting—concepts that form the foundation of many security tools.

The project is organized into several functional components: an input and resolution unit, TCP and UDP scanning routines, banner analysis, OS estimation, a logging system, and a multithreaded execution structure that allows scans to run in parallel. This design keeps the workflow efficient even when scanning larger port ranges.

2. Technologies and Environment

The program is written in C++ and uses the Winsock API on Windows. Visual Studio is recommended as the development environment. Although the tool runs on Windows, it can scan targets on any operating system, including Linux machines set up via virtual environments.

To run the application comfortably, a modern x86-64 processor, at least 8 GB RAM, and a few gigabytes of free storage are sufficient. The project was primarily developed and tested on Windows 10/11.

3. Algorithm Overview

The program starts by resolving the provided host name or IP. It then attempts TCP connections to selected ports and, when available, retrieves banner information returned by the remote service. These banners form the basis of the OS estimation process. On the UDP side, the tool sends lightweight probe packets and determines port status based on the responses received—or the lack thereof.

All scanning operations happen concurrently through multiple threads, improving performance significantly. The results are displayed in the terminal and saved to a file named sonuclar_windows.txt with accurate timestamps to preserve the traceability of each step.

4. Why This Project Matters

This tool serves as a compact, hands-on introduction to how real-world scanners—such as Nmap—operate under the hood. Features like banner grabbing, concurrent TCP/UDP scanning, and OS inference reflect concepts widely used in penetration testing, network auditing, and cybersecurity research. Understanding these mechanisms strengthens one’s grasp of low-level socket communication and network behavior.

5. Example Output

Below is a sample output from scanning portquiz.net:

<img width="562" height="494" alt="image" src="https://github.com/user-attachments/assets/2c633a93-c4b3-4e34-bf53-7d18f08e14b5" />
