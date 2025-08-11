# What is Shell Scripting? 🐚✨ 

Imagine you have a robot friend 🤖 who lives inside your computer.
- You can tell it what to do step-by-step.
- If you write those steps down in a notebook 📜, your robot can read them and do them again anytime without you repeating yourself.

That “notebook” in Linux is called a Shell Script.
The “Shell” 🐚 is like a translator between you (human) and the computer.
- You say: “Please make a folder” 🗂️
- The shell turns that into magic words (commands) your computer understands.

## Why use Shell Scripts?  
Think of it like: 
- Automating boring stuff you do every day.
- Keeping a checklist your robot follows perfectly every time.
- Saving hours by pressing one button instead of typing 10 commands.

## How a Shell Script Works 
- Write your steps 📝 (commands) in a text file.
- Save it with a .sh at the end, e.g., myscript.sh.
- Give permission so your robot can read it:
```bash 
chmod +x myscript.sh
```
- Run it:
```bash
./myscript.sh
```

Basic Shell Script Anatomy 

```bash 
#!/bin/bash   # 🐚 This tells the computer: "Use Bash to read me!"
echo "Hello World!"  
ls                

```
---
## Key Ingredients 

### Variables  

- Assign the value in the variable 
```bash 
name="Tirth Patel"
age=18
```
> ❗ `name="Tirth Patel"` is WRONG (spaces break it).

### Use / read: 
```bash 
echo "$name"
```
- Use `$name` to get the value.
- Prefer `"$name"` (quotes!) to preserve spaces and avoid globbing.

### Arithmetic: 
```bash
n=$((3+2))
((n++)) # increment, returns exit status
```
- `(())` does arithmetic and is safe for the numeric ops . 

### Command substitution 
```bash 
files=$(ls)
now=$(date +%F)
```
- Prefer `$(...)` over backticks `...`.

### Arrays: 

```bash
arr=(apple,"Fruit Salad",banana)
echo "${arr[0]}"
echo "${arr[1]}"
echo "${arr[@]}"  # each element separately when quoted
```

- Use `"${arr[@]}"` to iterate safely over elements (handles spaces).


## If statements  : 
### Basic syntax
```bash
if Condition; then 
     commands 
elif OTHER CONDITION; then 
     more
else 
     fallback
fi
```

### Conditional Operators
- `-eq` : Equal to
- `-ne` : Not Equal to 
- `-gt` : Greater than
- `-ge` : Greater than or equal to
- `-lt` : Less than
- `-le` : Less than or equal to

Exaple : 
```bash
#!/bin/bash

a=19

if [ "$a" -ge "18" ]; then
     echo "You can Drive"
else
     echo "You can not Drive"
fi
```