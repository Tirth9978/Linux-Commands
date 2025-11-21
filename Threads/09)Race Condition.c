#include <stdio.h>
#include <pthread.h>

int counter = 0;

void* inc(void* arg) {
    for (int i = 0; i < 100000; i++) {
        counter++;  // This is the critical section
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    pthread_create(&t1, NULL, inc, NULL);
    pthread_create(&t2, NULL, inc, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Expected: 200000\n");
    printf("Actual: %d\n", counter);
    return 0;
}