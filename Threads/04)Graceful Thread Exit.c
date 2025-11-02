#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

// 🎯 Worker thread function
void* worker_thread(void* arg) {
    int thread_id = *(int*)arg;
    
    printf("🧵 Thread %d: Starting my work...\n", thread_id);
    
    // Simulate some work
    for(int i = 1; i <= 3; i++) {
        printf("🧵 Thread %d: Working... step %d\n", thread_id, i);
        sleep(1);
    }
    
    printf("🧵 Thread %d: Work complete! Exiting gracefully...\n", thread_id);
    
    // 🚪 Graceful exit - only this thread dies
    pthread_exit(NULL);
    
    // This code will NEVER run! ❌
    printf("This message will never appear!\n");
}

int main() {
    pthread_t thread1, thread2;
    int id1 = 1, id2 = 2;
    
    printf("👑 Main: Creating worker threads...\n");
    
    // Create two worker threads
    pthread_create(&thread1, NULL, worker_thread, &id1);
    pthread_create(&thread2, NULL, worker_thread, &id2);
    
    printf("👑 Main: Threads created! Main thread continues working...\n");
    
    // Main thread does its own work
    for(int i = 1; i <= 2; i++) {
        printf("👑 Main: Doing main work... step %d\n", i);
        sleep(1);
    }
    
    printf("👑 Main: All done! Program exiting normally.\n");
    
    // Note: We're NOT calling exit() here
    return 0;
}