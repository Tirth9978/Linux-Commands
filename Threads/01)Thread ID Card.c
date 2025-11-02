#include <pthread.h>
#include <stdio.h>

int main() {
    // Every program has at least ONE thread (main thread)
    pthread_t my_id = pthread_self();
    
    printf("🎫 My Thread ID: %lu\n", (unsigned long)my_id);
    printf("👋 Hello from the main thread!\n");
    
    return 0;
}