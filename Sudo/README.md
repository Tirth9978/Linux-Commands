# Sudo Commands 

Kali Linux uses APT (Advanced Package Tool) to install, update, upgrade, and manage software packages. This cheat sheet includes essential commands for efficient package management.

## 1. Update and Upgrade Kali Linux

```
sudo apt update  
sudo apt upgrade -y
```
- `apt update`: Refreshes the package index to know about the newest versions.  
- `apt upgrade`: Installs the latest versions of all installed packages.  
- `-y`: Automatically confirms prompts with "yes".

## 2. Install Software using APT

```
sudo apt install <package-name>
```
Install multiple packages at once:
```
sudo apt install <package1> <package2> <package3>
```

## 3. Search for a Package Before Installing
```
apt search <package-name>
```
- Lists packages matching the keyword.

## 4. Check Details of a Package
```
apt show <package-name>
```
- Displays details such as version, size, dependencies, and description.

## 5. Remove or Uninstall Software
```
sudo apt remove <package-name>
```
- Removes the package but retains its configuration files.

## 6. Remove Package Along with Its Configuration Files
```
sudo apt purge <package-name>
```
- Completely removes the package and its configuration files.

## 7. Remove Unused Dependencies
```
sudo apt autoremove
```
- Removes packages that were automatically installed and are no longer needed.

## 8. Download Package Without Installing
```
apt download <package-name>
```
- Downloads the .deb file without installing it.

## 9. Fix Broken or Incomplete Installations
```
sudo apt --fix-broken install
```
- Attempts to fix dependency issues or incomplete installations.

## 10. Clean Up Local Repository
```
sudo apt clean  
sudo apt autoclean
```
- `apt clean`: Clears out the local repository of retrieved package files.  
- `apt autoclean`: Removes only outdated packages from the cache.

## 11. Full System Upgrade
```
sudo apt full-upgrade -y
```
- Similar to `apt upgrade`, but can remove installed packages if needed to resolve dependencies.

## 12. Combined Weekly Maintenance (Recommended)
```
sudo apt update && sudo apt upgrade -y && sudo apt autoremove && sudo apt autoclean
```
- Updates package list, upgrades installed packages, removes unused dependencies, and clears cache.

## 13. Install a Local .deb Package
```
sudo dpkg -i <file>.deb  
sudo apt --fix-broken install
```
- Installs a downloaded .deb file and fixes any missing dependencies.
