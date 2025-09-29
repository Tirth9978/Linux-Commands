#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(void) {
    int pid1, pid2;
    
    printf("🎬 Director: Starting two video players...\n");
    
    // Start Video Player 1 (First Child)
    pid1 = fork();
    if (pid1 == 0) {
        // First child - Video Player 1
        while(1) {
            printf("📺 Video 1 (PID %d): Playing...\n", getpid());
            sleep(1);
        }
    }
    
    // Start Video Player 2 (Second Child)  
    pid2 = fork();
    if (pid2 == 0) {
        // Second child - Video Player 2
        while(1) {
            printf("📺 Video 2 (PID %d): Playing...\n", getpid());
            sleep(1);
        }
    }
    
    // Director (Parent) with remote control
    printf("🎬 Director: Both videos running. PID1=%d, PID2=%d\n", pid1, pid2);
    
    sleep(3);  // Let both videos play for 3 seconds
    
    printf("⏸️  Director: Pausing Video 1...\n");
    kill(pid1, SIGSTOP);  // PAUSE Video 1
    
    sleep(3);  // Only Video 2 plays for 3 seconds
    
    printf("▶️  Director: Resuming Video 1...\n");  
    kill(pid1, SIGCONT);  // PLAY Video 1 again
    
    sleep(3);  // Both videos play for 3 more seconds
    
    printf("🛑 Director: Stopping both videos...\n");
    kill(pid1, SIGINT);  // Stop Video 1
    kill(pid2, SIGINT);  // Stop Video 2
    
    printf("🎬 Director: Show's over!\n");
    return 0;
}