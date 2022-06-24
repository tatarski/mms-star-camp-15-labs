#include<stdio.h>
#include<pthread.h>
int SUM_ALL = 0;
pthread_mutex_t lock1;
void* sum_n(void* argp) {
    printf("Thread started\n");
    int SUM = 0;
    int N = *((int*)(argp));
    for(int i = 0; i < N; i++) {
        SUM += i;
    }
    pthread_mutex_lock(&lock1);
    SUM_ALL += SUM; // critical section
    pthread_mutex_unlock(&lock1);

    // SUM_ALL += SUM;
    printf("Thread ended %d\n", 3*SUM);
}
int main() {
    pthread_t tid1, tid2, tid3;
    // mutex - mutual exclusion
    pthread_mutex_init(&lock1, NULL);
    int N = 10000000;
    // scanf("%d", &N);
    pthread_create(&tid1, NULL, sum_n, (void*)(&N));
    pthread_create(&tid2, NULL, sum_n, (void*)(&N));
    pthread_create(&tid3, NULL, sum_n, (void*)(&N));

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    pthread_join(tid3, NULL);
    printf("SUMALL: %d\n", SUM_ALL);
    pthread_mutex_destroy(&lock1);
}