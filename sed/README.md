# 📝 `sed` Command

---

## 1. What is `sed`?
- `sed` = **Stream EDitor**  
- It edits text **as it flows through a stream** (line by line).  
- Common uses: **find & replace, delete lines, print specific lines, insert text**.  

**Analogy:**  
Think of `sed` as a **robot editor**:
- You give it editing rules.
- It automatically applies those edits to every line of text passing through.

---

## Syntax : 

```bash
sed <Option> "command" file.txt
```

- Reads the file line by line.
- Applies the 'command'.
- Prints result to stdout (screen) by default (does not change file unless told).

## Find and Replace

### Replace First Occurrences in a Line
```bash 
sed "s/<Old>/<New>/" file.txt
```

- `s` = substitute.
- Replaces first occurrence of `<old>` with `<new>` in each line.

### Replace All Occurrences in a Line

```bash 
sed "s/<Old>/<New>/g" file.txt
```

### Case-Insensitive Replace

```bash 
sed "s/<Old>/<New>/g" file.txt
```
- `i` : ignore case.
---
## Editing In-Place : 

By default, sed just prints changes.
To edit the file itself:
```bash
sed -i "s/<Old>/<New>/g" file.txt
```
>⚠️ Use carefully — it overwrites the file.

## Deleting Lines:
#### Deleting Lines
```bash
sed '3d' file.txt
```

#### Delete lines 2 to 5:
```bash
sed '2,5d' file.txt
```

#### Delete all blank lines:
```bash
sed '/^$/d' file.txt
```
## Printing Lines : 

#### Print only line 5:
```bash
sed -n '5p' file.txt
```

#### Print lines 2–4:

```bash
sed -n '2,4p' file.txt
```
(-n stops sed from printing everything by default.)

##  Insert and Append : 
#### Insert a line before line 3:

```bash
sed '3i This is a new line' file.txt
```

#### Append a line after line 3:
```bash 
sed '3a This line comes after' file.txt
```

## multi‑substitution :
```bash
sed -e 's/Junior/Jr/g' -e 's/Senior/Sr/g' students.txt
```
