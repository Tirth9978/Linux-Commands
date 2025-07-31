# 🔐 File Permissions with `chmod`

The `chmod` command in Linux is used to **change file permissions**.  
Permissions are represented by numbers:

- `4` → Read (r)  
- `2` → Write (w)  
- `1` → Execute (x)  

Add them together to assign multiple permissions.  
Example: `7 = 4+2+1 = rwx`

---

## ✨ Common Examples

- **Make a file executable**
```bash
chmod +x <file_name>
```
Adds execute permission to the file.

---

- **Give full permissions to the owner only**
```bash
chmod 700 <file_name>
```
- `7` → Owner: Read (4) + Write (2) + Execute (1) = **rwx**  
- `0` → Group: No permission  
- `0` → Others: No permission  

---

- **Give read & write permission to everyone**
```bash
chmod 666 <file_name>
```
- `6` → Owner: Read (4) + Write (2) = **rw-**  
- `6` → Group: Read (4) + Write (2) = **rw-**  
- `6` → Others: Read (4) + Write (2) = **rw-**

---

- **Give full permissions to everyone**
```bash
chmod 777 <file_name>
```
- `7` → Owner: **rwx**  
- `7` → Group: **rwx**  
- `7` → Others: **rwx**  

⚠️ **Warning:** Avoid `777` on sensitive files for security reasons.

---

## 📝 Notes

- Use `ls -l` to check file permissions.  
- Numeric (e.g., `755`) and symbolic (e.g., `u+x`, `g-w`) modes are both supported.  
- Example of symbolic:
```bash
chmod u+x file.sh   # Add execute for user
chmod g-w file.txt  # Remove write for group
chmod o+r file.txt  # Add read for others
```
