#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

int delay;  // Global variable - the time limit

// The "Worker Finished" Handler
void childHandler() {
    int childPid, childStatus;
    childPid = wait(&childStatus);  // Clean up the finished worker
    printf("✅ Child %d terminated within %d seconds \n", childPid, delay);
    exit(0);  // Manager's job is done
}

int main(int argc, char *argv[]) {
    int pid;
    
    // Install the worker completion notification
    signal(SIGCHLD, childHandler);
    
    // Hire a worker (fork)
    pid = fork();
    
    if (pid == 0) {
        // Worker process - do the assigned task
        execvp(argv[2], &argv[2]);  // Execute the command
        perror("exec failed");      // Only runs if command fails
        exit(1);
    } else {
        // Manager process
        sscanf(argv[1], "%d", &delay);  // Read the time limit
        
        // Wait for the specified time
        sleep(delay);
        
        // If we get here, worker is STILL RUNNING (too slow!)
        printf("⏰ Child %d exceeded limit and is being killed\n", pid);
        kill(pid, SIGINT);  // Fire the slow worker!
        
        // Manager waits to hear back from worker
        pause();  // Wait for SIGCHLD signal
    }
    
    return 0;
}