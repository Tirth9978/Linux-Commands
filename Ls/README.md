# Linux `ls` Command Cheat Sheet

The `ls` command is used to list directory contents in Linux.

## Basic Usage

`ls`  
→ Lists files and directories in the current directory.

## Common Options

`ls -l ` 
→ Lists files in long format. Shows permissions, number of links, owner, group, size, and timestamp.

`ls -a`  
→ Shows all files including hidden files (those starting with a dot `.`).

`ls -la` 
→ Combines `-l` and `-a`: long listing format with hidden files included.

`ls -lh`  
→ Long format with human-readable file sizes (e.g., KB, MB).

`ls -lS`  
→ Sorts files by size (largest first).
`ls -lt`  
→ Sorts files by modification time (newest first).

`ls -ltr`  
→ Sorts files by time, oldest first.

`ls -R`  
→ Lists all subdirectories recursively.

`ls -d */`
→ Lists only directories, not files.

`ls -i` 
→ Displays the inode number of each file.

`ls --color=auto`  
→ Enables colored output for file types and permissions.

## Examples

`ls -lh`  
→ View files with readable sizes.

`ls -la /etc`  
→ View all files, including hidden ones, in the `/etc` directory.

`ls -lt /var/log`  
→ View logs sorted by time (most recent first).

`ls -R /home/user`  
→ Recursively lists all files and directories under `/home/user`.

## Pro Tip

You can create an alias for a better default experience:

`alias ll='ls -alF --color=auto'`

→ This command adds colors, shows file types, and lists all files in detail.

```bash
# To make alias permanent, add it to ~/.bashrc or ~/.zshrc
echo "alias ll='ls -alF --color=auto'" >> ~/.bashrc
source ~/.bashrc
```
