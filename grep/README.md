# 🔎 `grep` in Linux — Complete Study Notes

---
## What is the `grep` : 
- `grep` = **Global Regular Expression Print**  
- It searches for patterns (words, numbers, regex) in text.  
- Reads input **line by line** and prints only lines that match the pattern.
---

**Analogy :**
Think of `grep` as a **mail sorter**: you give it a big stack of letters (a file or command output), and it gives you back only the letters containing your keyword.  

## Syntax : 
```bash 
grep "Pattern" <File Name>
```

---
## Common Options

### Ignore Case 
```bash 
grep -i "hello" file.txt
```
- Matches hello, Hello, HELLO, etc.

### Show Line Numbers
```bash 
grep -n "hello" file.txt
```
- Prints matching lines with their line number 

### count Match 
```bash 
grep -c "hello" file.txt
```
- Shows how many lines matched (not the lines themselves).

### 🚫 Invert Match (exclude pattern)
```bash
grep -v "Hello" file.txt
```
- Shows all lines except those containing error.

### 📂 Recursive Search 
```bash
grep -r "main" /path/to/code
```
- Searches all files under a directory.
---
## Grep with Pipes
grep can filter the output of another command.
```bash
ls | grep ".txt"
```
- It will filter all files which file type is `.txt`