# Linux `rm` Command Cheat Sheet

The `rm` command is used to delete files and directories in Linux.

## Basic Usage

`rm <file-name>`  
→ Removes the specified file.

`rm -r <folder-name>`  
→ Removes the specified folder and its contents recursively.

## Common Options

`rm -f <file-name>`  
→ Forcefully removes a file without prompting for confirmation.

`rm -rf <folder-name> ` 
→ Recursively and forcefully removes a folder and all its contents (USE WITH CAUTION).

`rm -i <file-name>` 
→ Prompts for confirmation before removing each file.

`rm -ri <folder-name>`  
→ Prompts before deleting each file in the folder recursively.

## Examples

`rm notes.txt`  
→ Deletes the file named `notes.txt`.

`rm -r my_folder`  
→ Deletes the folder `my_folder` and everything inside it.

`rm -rf /tmp/test`  
→ Forcefully deletes `/tmp/test` folder without any prompt.

## Warning

- `rm -rf /` will delete everything on your system — **never run this**.
- Always double-check the folder or file name before using `rm -rf`.

## Safer Deletion (Trash)

If you prefer to move files to trash instead of permanent deletion, use:

gio trash <file-or-folder>

→ Moves the file or folder to the trash (if supported by desktop environment).

## Pro Tip

To prevent accidental deletion, make `rm` interactive by default:

```bash
alias rm='rm -i'
```

→ Add this to your `~/.bashrc` or `~/.zshrc` to always confirm before deleting.

