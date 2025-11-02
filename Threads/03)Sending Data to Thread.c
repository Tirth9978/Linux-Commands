#include <pthread.h>
#include <stdio.h>

// 🎯 Thread function that accepts an argument
void* worker_with_data(void* arg) {
    int thread_number = *(int*)arg;  // 📦 Unpack the argument
    printf("🧵 Thread %d: Processing data...\n", thread_number);
    printf("🧵 Thread %d: Work complete!\n", thread_number);
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    int data1 = 1, data2 = 2;  // 📋 Data to send to threads
    
    printf("👑 Main: Creating thread 1...\n");
    pthread_create(&thread1, NULL, worker_with_data, &data1);
    
    printf("👑 Main: Creating thread 2...\n"); 
    pthread_create(&thread2, NULL, worker_with_data, &data2);
    
    // ⏳ Wait for threads to finish (we'll learn better ways soon!)
    sleep(1);
    
    printf("👑 Main: All workers finished!\n");
    return 0;
}