#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2];
    char buffer[50];
    pipe(fd);

    if (fork() == 0) {  // Child
        close(fd[0]);   // Close read end
        char msg[] = "Message from Child!";
        write(fd[1], msg, strlen(msg)+1);
        close(fd[1]);
    } else {            // Parent
        close(fd[1]);   // Close write end
        read(fd[0], buffer, sizeof(buffer));
        printf("👨 Parent received: %s\n", buffer);
        close(fd[0]);
    }
    return 0;
}
