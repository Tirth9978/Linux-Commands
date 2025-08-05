# Redirection Operators

## Redirect stdout (normal output) to a file
```bash
ls > file.txt
```
- Faucet water goes into the bucket (files.txt) instead of sink (screen).

## Append instead of overwrite
```bash
ls >> file.txt
```
- Add water to the same bucket without dumping the old water.

## Redirect stdin (take input from file instead of keyboard) 

```bash
sort < numbers.txt
```
- The faucet gets water from a bucket instead of the hose.

## Redirect stderr (errors)
```bash
ls /root 2> errors.txt
```

- Normal faucet water still goes to sink, but leaks (errors) get collected in a bucket.

## Redirect both stdout and stderr together 
```bash
command > alloutput.txt 2>&1
```
