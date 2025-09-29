#include <stdio.h>
#include <signal.h>
#include <unistd.h>

// Your custom action for when SIGUSR1 arrives
void my_signal_handler(int signum) {
    if (signum == SIGUSR1) {
        printf("📻 WALKIE-TALKIE: Message on CHANNEL 1 received!\n");
        printf("   Doing special task A...\n");
    } else if (signum == SIGUSR2) {
        printf("📻 WALKIE-TALKIE: Message on CHANNEL 2 received!\n");
        printf("   Doing special task B...\n");
    }
}

int main() {
    printf("🚀 Receiver PID %d: Setting up walkie-talkie...\n", getpid());
    
    // Tune into both channels
    signal(SIGUSR1, my_signal_handler);  // Listen on Channel 1
    signal(SIGUSR2, my_signal_handler);  // Listen on Channel 2
    
    printf("📡 Receiver: Listening on Channels 1 & 2. Send me signals!\n");
    printf("   Try: kill -SIGUSR1 %d\n", getpid());
    printf("   Or:  kill -SIGUSR2 %d\n", getpid());
    
    // Wait for messages
    while(1) {
        printf("👂 Listening...\n");
        sleep(5);
    }
    
    return 0;
}