#include <stdio.h>
#include <pthread.h>

// Shared resource
int counter = 0;

// Mutex declaration
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Thread function
void* increment_counter(void* arg) {
    for (int i = 0; i < 100000; i++) {
        // 🔒 LOCK the critical section
        pthread_mutex_lock(&mutex);
        
        // CRITICAL SECTION 🚧
        counter++; // Only one thread can execute this at a time
        
        // 🔓 UNLOCK
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    
    // Create two threads
    pthread_create(&thread1, NULL, increment_counter, NULL);
    pthread_create(&thread2, NULL, increment_counter, NULL);
    
    // Wait for threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    
    // Destroy mutex
    pthread_mutex_destroy(&mutex);
    
    printf("Final counter value: %d\n", counter); // ✅ Always 200000
    printf("Expected: 200000\n");
    
    return 0;
}