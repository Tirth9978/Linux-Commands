#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    int fd[2];
    pipe(fd);

    if (fork() == 0) {  // Child 1
        close(fd[0]);
        write(fd[1], "Child1\n", 7);
        close(fd[1]);
        return 0;
    }

    if (fork() == 0) {  // Child 2
        close(fd[0]);
        write(fd[1], "Child2\n", 7);
        close(fd[1]);
        return 0;
    }

    close(fd[1]); // parent reads
    char buffer[100];
    int n = read(fd[0], buffer, sizeof(buffer)-1);
    buffer[n] = '\0';
    printf("Parent received:\n%s", buffer);
    close(fd[0]);

    while (wait(NULL) > 0); // wait for children
    return 0;
}
