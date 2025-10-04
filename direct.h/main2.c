#include <stdio.h>
#include <dirent.h>

int main() {
    DIR *folder = opendir(".");
    struct dirent *entry;
    
    if (folder == NULL) {
        printf("❌ Cannot open directory!\n");
        return 1;
    }
    
    printf("📖 Reading directory like a book:\n");
    
    // Read first file and save position
    entry = readdir(folder);
    printf("1. %s\n", entry->d_name);
    
    long bookmark = telldir(folder);  // 📍 Save our spot!
    printf("📍 Saved position: %ld\n", bookmark);
    
    // Read a few more files
    for (int i = 0; i < 3; i++) {
        entry = readdir(folder);
        if (entry) printf("%d. %s\n", i+2, entry->d_name);
    }
    
    // 🔄 Jump back to our saved position!
    printf("\n🔄 Jumping back to saved position...\n");
    seekdir(folder, bookmark);
    
    // Now continue reading from the saved spot
    printf("📖 Continuing from saved position:\n");
    while ((entry = readdir(folder)) != NULL) {
        printf("→ %s\n", entry->d_name);
    }
    
    closedir(folder);
    return 0;
}