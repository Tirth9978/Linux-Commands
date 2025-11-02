#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int fd[2];
    pipe(fd);
    
    printf("Pipe fds: %d %d\n", fd[0], fd[1]);
    
    pid_t p = fork();
    
    if (p == 0) {
        // Child
        close(fd[0]);
        close(fd[1]);
        printf("Child exiting\n");
        _exit(0);
    } else {
        // Parent
        close(fd[0]);
        int result = write(fd[1], "Hello", 5);
        printf("Write result: %d\n", result);
        perror("Write error");
        wait(NULL);
    }
    return 0;
}