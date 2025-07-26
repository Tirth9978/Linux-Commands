## 🔎 Nmap Command Cheatsheet

- **1. Basic Scan**  
  `nmap <IP>`  
  → Scan a host for open ports using default settings.

- **2. Scan All Ports**  
  `nmap -p 1-65535 <IP>`  
  → Scan all 65,535 TCP ports.

- **3. Detect Operating System**  
  `nmap -O <IP>`  
  → Attempt to detect the OS of the target.

- **4. Detect Services & Versions**  
  `nmap -sV <IP>`  
  → Identify running services and their versions.

- **5. Scan a Network Range**  
  `nmap <IP>/24`  
  → Scan all 256 IPs in a subnet (Class C network).

- **6. Scan a Website**  
  `nmap <website.com>`  
  → Scan a domain for open ports.
