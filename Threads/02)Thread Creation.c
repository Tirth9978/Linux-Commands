#include <pthread.h>
#include <stdio.h>
#include <unistd.h>  // For sleep()

// 🎯 The function our new thread will run
void* thread_job(void* arg) {
    printf("🧵 New Thread: I'm alive! My job is starting...\n");
    
    // Simulate some work
    sleep(2);
    
    printf("🧵 New Thread: Job completed! Going home...\n");
    return NULL;
}

int main() {
    pthread_t thread_id;  // 🆔 Will store our new thread's ID
    
    printf("👑 Main Thread: I'm about to create a worker thread!\n");
    
    // 🎪 Create the new thread!
    int result = pthread_create(&thread_id,   // Store thread ID here
                               NULL,          // Default attributes
                               thread_job,    // Function to run
                               NULL);         // No arguments needed
    
    if (result != 0) {
        printf("❌ Oops! Failed to create thread. Error: %d\n", result);
        return 1;
    }
    
    printf("👑 Main Thread: Worker thread created successfully!\n");
    printf("👑 Main Thread: Thread ID: %lu\n", (unsigned long)thread_id);
    
    // ⏳ Give the worker thread time to finish
    sleep(3);
    
    printf("👑 Main Thread: All done! Program exiting.\n");
    return 0;
}