#include <stdio.h>
#include <pthread.h>

void* work(void* arg) {
    int val = *(int*)arg;
    printf("Thread: Got %d\n", val);
    return (void*)(val * val);
}

int main() {
    pthread_t tid;
    int x = 5;
    void* res;

    pthread_create(&tid, NULL, work, &x);
    pthread_join(tid, &res);

    printf("Main: Result = %ld\n", (long)res);
    return 0;
}