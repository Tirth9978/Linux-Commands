#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* work(void* arg) {
    for (int i = 1; i <= 10; i++) {
        printf("Thread: Running %d\n", i);
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t tid;

    pthread_create(&tid, NULL, work, NULL);
    sleep(3);  // Let thread run for 3 seconds
    
    pthread_cancel(tid);  // Cancel the thread
    printf("Main: Thread cancelled\n");

    pthread_join(tid, NULL);
    printf("Main: Thread finished\n");

    return 0;
}