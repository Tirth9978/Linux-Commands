#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

// 🎯 Worker thread function
void* worker_job(void* arg) {
    int work_time = *(int*)arg;
    
    printf("🧵 Worker: Starting my %d-second job...\n", work_time);
    sleep(work_time);  // Simulate work
    printf("🧵 Worker: Job completed after %d seconds!\n", work_time);
    
    pthread_exit(NULL);
}

int main() {
    pthread_t worker;
    int work_duration = 3;
    
    printf("👑 Manager: Hiring a worker for %d seconds...\n", work_duration);
    
    // Create worker thread
    pthread_create(&worker, NULL, worker_job, &work_duration);
    
    printf("👑 Manager: Worker is busy. I'll wait patiently...\n");
    
    // ⏳ WAIT for worker to finish
    pthread_join(worker, NULL);
    
    printf("👑 Manager: Worker finished! Now I can continue...\n");
    printf("👑 Manager: All tasks completed!\n");
    
    return 0;
}