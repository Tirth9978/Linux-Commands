# Pipes in Linux 

Remember the plumbing analogy:
- Each command is a faucet.
- Normally, the faucet’s water (output) flows into the sink (screen).
- With a pipe |, instead of going to the sink, the water flows directly into another faucet (another command’s input).

## Basic Example 

```bash
ls | sort 
```
- `ls` → lists files.
- `sort` → sorts text alphabetically.
- The pipe `|` connects them.

You get a sorted list of files on your screen.

## Multiple Pipes (chain)

```bash
ls | sort | head -10
```
- `ls` → list of all commands.
- `sort` → sorts them alphabetically.
- `head -10` → shows only the first 10.

 You see the first 10 lines

