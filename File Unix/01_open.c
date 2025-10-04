#include <fcntl.h> // Contains the open() function
#include <stdio.h>

int main() {
    // Try to get the key (file descriptor) for "example.txt"
    // We want to Open for Writing, and Create the file if it doesn't exist.
    int file_descriptor = open("example.txt", O_WRONLY | O_CREAT, 0644);

    if (file_descriptor == -1) {
        perror("Error opening file"); // Prints a descriptive error if open failed
        return 1;
    }

    printf("Success! File descriptor number is: %d\n", file_descriptor);

    // We will use file_descriptor with write() and close() later...
    // For now, just remember we have the key.
    
    close(file_descriptor); // Always return the key when done!
    return 0;
}