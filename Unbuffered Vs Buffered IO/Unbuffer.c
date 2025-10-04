#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("data.txt", O_RDONLY);
    char buffer[1];  // One byte at a time! 😫
    
    // Reading 100 bytes = 100 system calls!
    for (int i = 0; i < 100; i++) {
        read(fd, buffer, 1);
        // Process each byte...
    }
    close(fd);
    return 0;
}