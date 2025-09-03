#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

int main() {
    int fd[2];   // fd[0] = read end, fd[1] = write end
    pid_t pid;
    char buffer[50];

    // 1️⃣ Create pipe
    if (pipe(fd) == -1) {
        perror("pipe failed");
        return 1;
    }

    // 2️⃣ Fork a child process
    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    }

    if (pid == 0) {
        // 3️⃣ Child process (Reader)
        close(fd[1]);  // Close unused write end
        read(fd[0], buffer, sizeof(buffer));
        printf("👶 Child received: %s\n", buffer);
        close(fd[0]);  // Close read end
    } else {
        // 4️⃣ Parent process (Writer)
        close(fd[0]);  // Close unused read end
        char message[] = "Hello from Parent!";
        write(fd[1], message, strlen(message) + 1);
        printf("👨 Parent sent: %s\n", message);
        close(fd[1]);  // Close write end
    }

    return 0;
}
