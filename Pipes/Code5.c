#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int fd1[2], fd2[2];
    pipe(fd1);
    pipe(fd2);
    
    if (fork() == 0) {
        // Child 1
        close(fd1[0]);
        close(fd2[0]);
        close(fd2[1]);
        dup2(fd1[1], STDOUT_FILENO);
        execlp("ls", "ls", "/etc", NULL);
    }
    
    if (fork() == 0) {
        // Child 2
        close(fd1[1]);
        close(fd2[0]);
        dup2(fd1[0], STDIN_FILENO);
        dup2(fd2[1], STDOUT_FILENO);
        execlp("grep", "grep", "passwd", NULL);
    }
    
    // Parent
    close(fd1[0]);
    close(fd1[1]);
    close(fd2[1]);
    
    char buffer[1024];
    int n;
    while ((n = read(fd2[0], buffer, sizeof(buffer))) > 0) {
        write(STDOUT_FILENO, buffer, n);
    }
    
    close(fd2[0]);
    wait(NULL);
    wait(NULL);
    return 0;
}