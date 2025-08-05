# Linux Process Management

## (1) Check Running Processes

- `ps aux` → Show all running processes  
- `top` → Basic real-time process viewer  
- `htop` → Advanced real-time viewer (if installed)  
- `ps aux | grep <name>` → Search for a specific process  
- `pgrep <name>` → Show only the PIDs of a specific program  
- `pstree` → Display processes in a tree structure (shows parent/child relations)

---

## (2) Kill a Process

- `kill <PID>` → Kill a specific process  
- `kill -9 <PID>` → Force kill a process  
- `pkill <program_name>` → Kill all processes by name  
- `killall <program_name>` → Kill all processes with the given name (similar to `pkill`)  

---

## (3) Manage Process Priority

- `nice -n <value> <command>` → Start a process with a specific priority  
- `renice <priority> -p <PID>` → Change the priority of a running process  

> Priority ranges: `-20` (highest priority) to `19` (lowest priority)

---

## (4) Background & Foreground Jobs

- `jobs` → List background jobs in the current shell  
- `fg %<job_id>` → Bring a job to the foreground  
- `bg %<job_id>` → Resume a job in the background  

---

## (5) Monitor Resource Usage

- `vmstat` → Show memory, CPU, and I/O usage stats  
- `iostat` → Show CPU and disk I/O usage  
- `dstat` → General system resource statistics  

