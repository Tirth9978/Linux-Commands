#include <stdio.h>

int main() {
    FILE *file = fopen("data.txt", "r");
    char buffer[1024];  // 1KB buffer 🎉
    
    // Reading 100 bytes = maybe 1 system call!
    fread(buffer, 1, 100, file);
    // Process all bytes at once...
    
    fclose(file);
    return 0;
}