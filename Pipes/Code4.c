#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main() {
    int fd[2];
    pipe(fd);
    pid_t p = fork();

    if (p > 0) { // Parent
        close(fd[0]);
        char *msg1 = "Hello";
        char *msg2 = "World";
        write(fd[1], msg1, strlen(msg1));
        sleep(2);
        write(fd[1], msg2, strlen(msg2));
        close(fd[1]);
        wait(NULL);
    } 
    else { // Child
        close(fd[1]);
        char buf[20];
        sleep(1);
        int n;
        while ((n = read(fd[0], buf, 10)) > 0) {
            buf[n] = '\0';
            printf("Read: %s\n", buf);
        }
        close(fd[0]);
    }
    return 0;
}