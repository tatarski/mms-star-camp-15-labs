#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
double sumAll = 0;
pthread_mutex_t lock;
typedef struct sum_info {
    int N, K, startIndex;
    double sum_res;
} sum_info;
int factoriel(int N) {
    int res = 1;
    for(int i = 1; i <= N; i++) {
        res *= i;
    }
    return res;
}
void* sum_partial(void *p) {
    // Return val 
    // use argument pointer
    // use retval
    // use global variable + mutex
    sum_info* info = (sum_info*)p;

    printf("START THREAD K=%d\n", info->startIndex);
    double sum = 0;
    for(int i = info->startIndex; i < info->N; i+=info->K) {
        sum+=1./(double)factoriel(i);
    }
    info->sum_res = sum;
    
    pthread_mutex_lock(&lock);
    sumAll += sum;
    pthread_mutex_unlock(&lock);

    printf("END THREAD K=%d\n", info->startIndex);
}
int main() {
    pthread_mutex_init(&lock, NULL);
    int N = 10, K = 4;
    pthread_t threadArr[K];
    sum_info *infoArr[K];
    for(int i = 0; i < K; i++) {
        infoArr[i] = malloc(sizeof(sum_info));
        infoArr[i]->K = K;
        infoArr[i]->N = N;
        infoArr[i]->startIndex = i;
        pthread_create(&threadArr[i], NULL, sum_partial, (void*)infoArr[i]);
    }
    double res = 0;
    for(int i = 0; i < K; i++) {
        double* retval;
        pthread_join(threadArr[i], (void**)&retval);
        res += infoArr[i]->sum_res;
        free(infoArr[i]);
    }
    pthread_mutex_destroy(&lock);
    printf("%f\n", res);
    printf("%f\n", res);
}