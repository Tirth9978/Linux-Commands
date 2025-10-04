#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2];
    pid_t pid;
    char msg[] = "Hello from Child!";
    char buffer[100];

    pipe(fd);              // create pipe
    pid = fork();          // create child

    if (pid == 0) { // Child process
        close(fd[0]);      // close read end
        write(fd[1], msg, strlen(msg)+1);
        close(fd[1]);
    } else { // Parent process
        close(fd[1]);      // close write end
        read(fd[0], buffer, sizeof(buffer));
        printf("Parent received: %s\n", buffer);
        close(fd[0]);
    }
    return 0;
}
