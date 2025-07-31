# ⚙️ Linux Job Control (Foreground & Background Processes)

(1) Run a Process in the Background  
```bash
<program_name> &
```
→ Runs a process in the background. The process keeps running, but you cannot interact with it directly.

---

(2) Bring a Background Process to the Foreground  
```bash
fg
```
→ Brings the most recent job to the foreground.  
Use `fg %<job_id>` to bring a specific job.

---

(3) See All Background Jobs  
```bash
jobs
```
→ Lists all jobs started in the current shell with their job IDs.

---

(4) Move a Running Process to the Background  
- Press `Ctrl + Z` → Suspends the process.  
- Then run:
```bash
bg
```
→ Resumes the process in the background.  
Use `bg %<job_id>` for a specific job.

---

(5) Kill a Background Job  
```bash
kill %<job_id>
```
→ Kills a job using its job ID from `jobs`.

---

(6) Check Process IDs (PID)  
```bash
ps
```
→ Shows the PIDs of processes in the current shell. You can kill them with:  
```bash
kill <PID>
```

---

(7) Run a Process Immune to Terminal Close  
```bash
nohup <program_name> &
```
→ Runs a command that keeps running even after the terminal is closed.

---

## 📝 Notes
- `%<job_id>` = Job number from the `jobs` command.  
- Jobs are **shell-specific** → They only exist in the terminal where you started them.  
- To see **all processes** in the system:  
```bash
ps aux
```
