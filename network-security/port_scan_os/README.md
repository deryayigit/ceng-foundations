# Port and Service Scanner with OS Detection

## 1. Basic Information
### 1.1 Problem Definition and Purpose

This project is a C++ application designed to identify the characteristics of a remote machine through its IP address. It performs TCP and UDP port scanning, retrieves available service banners, and attempts to estimate the operating system using the information it gathers. All collected data is printed both to the console and to a time-stamped log file, allowing the results to be reviewed at any time.

The program follows a clear workflow: it takes the target address as input, resolves it, probes a range of ports, analyzes any banner information returned by services, and uses this data for OS estimation. Its goal is to demonstrate how low-level network scanning, banner analysis, and basic fingerprinting techniques operate in practice rather than theory.

### 1.2 Project Sections

The project is structured around several functional stages. The input unit receives the IP or domain name and resolves it. The TCP scanning phase attempts direct connections and retrieves any service banners available. The UDP scanning phase sends lightweight probe packets and evaluates responses when possible. Banner analysis interprets returned data, and the OS detection step uses these clues to form an estimate of the remote system. All results are saved to a file named sonuclar_windows.txt, and parallel execution is achieved through thread usage.

### 1.3 Technologies and Tools

The application is written in C++ and developed using Microsoft Visual Studio on Windows. It relies on the Winsock API for all network operations.

### 1.4 Hardware Requirements

The program runs comfortably on a modern x86_64 processor with at least 8 GB of RAM and several gigabytes of free storage. Although developed and tested on Windows 10/11, it can scan machines running any operating system.

## 2. Technical Requirements
### 2.1 Project Algorithm

The algorithm begins by receiving and resolving the target address. It then proceeds to probe specified TCP ports and extract any banner information returned by the remote services. These banners are analyzed to help estimate the operating system. TCP and UDP scans run simultaneously using multiple threads, and all output is written to both the screen and the log file along the way.

### 2.2 Critical Components

Winsock initialization (WSAStartup) forms the foundation of all network interactions in the program. Banner retrieval is essential for OS estimation, as it provides the raw textual clues needed for analysis. Multi-threaded scanning significantly reduces total execution time by allowing multiple ports to be processed concurrently.

## 3. Overview

This project serves as a focused demonstration of the fundamental techniques used in widely known tools such as Nmap. By combining TCP and UDP scanning, banner retrieval, OS estimation, and parallel execution, it presents a compact but realistic example of how network-scanning utilities function internally.

Output: Scanning portquiz.net
<img width="562" height="494" alt="image" src="https://github.com/user-attachments/assets/2c633a93-c4b3-4e34-bf53-7d18f08e14b5" />
