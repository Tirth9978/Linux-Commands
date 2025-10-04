#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) { 
        perror("Error opening file"); 
        return 1; 
    }

    char *message = "Hello, World!\n";
    ssize_t bytes_written = write(fd, message, strlen(message)); // Don't write the null terminator!

    if (bytes_written == -1) {
        perror("Error writing file");
    } else {
        printf("Successfully wrote %zd bytes.\n", bytes_written);
    }

    close(fd);
    return 0;
}