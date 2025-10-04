#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int p2c[2], c2p[2];
    pipe(p2c); // Parent → Child
    pipe(c2p); // Child → Parent

    pid_t pid = fork();
    char buf[100];
    int rounds = 3; // play 3 rounds

    if (pid == 0) {  // Child
        close(p2c[1]); // close write end of p2c
        close(c2p[0]); // close read end of c2p

        for (int i = 0; i < rounds; i++) {
            read(p2c[0], buf, sizeof(buf));
            printf("Child received: %s\n", buf);

            char reply[50];
            sprintf(reply, "Pong %d", i+1);
            write(c2p[1], reply, strlen(reply)+1);
        }

        close(p2c[0]);
        close(c2p[1]);
    } else {  // Parent
        close(p2c[0]); // close read end of p2c
        close(c2p[1]); // close write end of c2p

        for (int i = 0; i < rounds; i++) {
            char msg[50];
            sprintf(msg, "Ping %d", i+1);
            write(p2c[1], msg, strlen(msg)+1);

            read(c2p[0], buf, sizeof(buf));
            printf("Parent received: %s\n", buf);
        }

        close(p2c[1]);
        close(c2p[0]);
    }
    return 0;
}
