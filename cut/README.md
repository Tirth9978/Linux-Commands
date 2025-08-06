# ✂️ `cut` Command in Linux  
---
## What is this ? 
- The `cut` command is used to **extract specific sections** (columns or fields) from lines of text.  
-  Works best with structured text (like CSV, logs, tabular data).  
- Reads input line by line, cuts out parts of each line, and prints them.

**Analogy:**  
Think of `cut` as a **pair of scissors** for text — it slices out only the columns or characters you want.

---

## Syntax : 
```bash 
cut <OPTION> <FILE NAME>
```


## Cutting by Character Position :

```bash 
cut -c 1-5 tile.txt
```
- Prints characters 1 through 5 of each line.

## Cutting by Fields (columns) : 
Fields = text separated by a delimiter (default = TAB).

```bash 
cut -f2 file.txt
```
- Extracts the 2nd field (assuming TAB-delimited).

With a custom delimiter (e.g., , for CSV):
```bash 
cut -d"," -f1 file.csv
```
- Extracts the first column from a CSV file.

## Multiple Fields : 
```bash
cut -d"," -f1,3 file.txt
```
- Extracts first and third fields from a TXT.
- It could be the CSV File :)

## Cutting by Byte Position : 
```bash 
cut -b 1-3 file.txt
```
- Prints bytes 1 through 3 of each line.
(Useful for fixed-width binary/text files.)

