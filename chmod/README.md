## 🔐 File Permissions with `chmod`

- `chmod <file_name>`  
  → Make a file executable (used with a permission code)

- `chmod 700 <file_name>`  
  → Full permissions to **owner** only  
  - `7` → Owner: Read (4), Write (2), Execute (1)  
  - `0` → Group: No permission  
  - `0` → Others: No permission

- `chmod 666 <file_name>`  
  → **Read & write** permission to **everyone**
  - `6` → Owner: Read + Write  
  - `6` → Group: Read + Write  
  - `6` → Others: Read + Write
