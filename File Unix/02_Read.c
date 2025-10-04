#include <fcntl.h>
#include <unistd.h> // Contains read() and close()

int main() {
    int fd = open("example.txt", O_RDONLY); // Open for reading
    if (fd == -1) { 
        perror("Error opening file"); 
        return 1; 
    }

    char buffer[100]; // Our "notebook" - a place to store what we read
    ssize_t bytes_read = read(fd, buffer, sizeof(buffer) - 1); // Read up to 99 bytes

    if (bytes_read == -1) {
        perror("Error reading file");
        close(fd);
        return 1;
    }

    buffer[bytes_read] = '\0'; // Null-terminate the string to print it safely
    printf("I read %zd bytes: %s\n", bytes_read, buffer);

    close(fd);
    return 0;
}