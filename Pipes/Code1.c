#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd1[2], fd2[2];
    char parentMsg[] = "Hello Child!";
    char childMsg[] = "Hello Parent!";
    char buffer[100];
    pid_t pid;

    pipe(fd1); 
    pipe(fd2);  

    pid = fork();

    if (pid == 0) {  // Child process
        close(fd1[1]);  // close write end of fd1
        close(fd2[0]);  // close read end of fd2

        read(fd1[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);

        write(fd2[1], childMsg, strlen(childMsg)+1);

        close(fd1[0]); close(fd2[1]);
    } else {  // Parent process
        close(fd1[0]);  // close read end of fd1
        close(fd2[1]);  // close write end of fd2

        write(fd1[1], parentMsg, strlen(parentMsg)+1);
        read(fd2[0], buffer, sizeof(buffer));
        printf("Parent received: %s\n", buffer);

        close(fd1[1]); close(fd2[0]);
    }
    return 0;
}
