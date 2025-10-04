#include <stdio.h>
#include <dirent.h>

int main() {
    DIR *folder = opendir(".");
    struct dirent *entry;
    
    if (folder == NULL) {
        printf("❌ Cannot open directory!\n");
        return 1;
    }
    
    printf("📁 Directory Contents:\n");
    while ((entry = readdir(folder)) != NULL) {
        printf("📄 %s (inode: %lu)\n", entry->d_name, entry->d_ino);
    }
    
    closedir(folder);
    return 0;
}