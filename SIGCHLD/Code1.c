#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

int delay;

// The "Worker Finished" Handler
void childHandler(int sig) {
    int status;
    pid_t child_pid = wait(&status);
    printf("✅ Manager: Worker %d finished and cleaned up!\n", child_pid);
}

int main(int argc, char *argv[]) {
    int pid;
    
    if (argc < 3) {
        printf("Usage: %s <delay> <command>\n", argv[0]);
        exit(1);
    }
    
    // Step 1: Install the worker notification system
    signal(SIGCHLD, childHandler);
    
    // Step 2: Hire a worker (fork)
    pid = fork();
    
    if (pid == 0) {
        // Worker process
        printf("👷 Worker %d: Starting job '%s'\n", getpid(), argv[2]);
        execvp(argv[2], &argv[2]);  // Worker does the actual job
        perror("execvp failed");    // This only runs if execvp fails
        exit(1);
    } else {
        // Manager process
        sscanf(argv[1], "%d", &delay);  // Read timeout from command line
        
        printf("👨‍💼 Manager: Worker %d hired. I'll wait %d seconds max.\n", pid, delay);
        sleep(delay);  // Manager waits for reasonable time
        
        // If worker is still running after delay, fire them!
        printf("⏰ Manager: Time's up! Worker %d taking too long - FIRING!\n", pid);
        kill(pid, SIGINT);  // Send termination signal
        
        // Manager continues other work...
        printf("👨‍💼 Manager: Back to other important work...\n");
        sleep(10);
    }
    
    return 0;
}