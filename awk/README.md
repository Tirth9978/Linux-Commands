# What awk really is 
Think of `awk` as a tiny language living inside your terminal, designed to read lines of text, break them into pieces, and do something clever with those pieces.

If your terminal was a kitchen, then:
- Your file or command output = a pile of raw vegetables
- `awk` = the skilled chef who slices each vegetable into neat pieces and serves them up in the style you want — seasoned, rearranged, counted, or transformed.



## Basic Example : 
```bash
echo "Tirth Patel" | awk '{print $1}'
echo "Tirth Patel" | awk '{print $2}'
```

`$1` -> "Tirth"
`$2` -> "Patel"

---

## The basic syntax
```bash 
awk 'pattern { action }' file.txt
```
- pattern → which lines you care about (like a filter).
- action → what to do with them (like “print this” or “add numbers”).

If you skip the pattern, `awk` applies the action to every line.<br>
If you skip the action, it just prints matching lines.


##  Common examples

Print the second and third column:
```bash
awk '{print $2, $3}' file.txt
```

Only lines where the second column is greater than 100:
```bash 
awk '$2 > 100 {print $0}' file.txt
```
