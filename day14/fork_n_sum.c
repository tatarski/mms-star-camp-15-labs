#include<stdio.h>
#include<time.h>
#include<wait.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/time.h>
int isPrime(int j) {
    for(int i = 2; i < j/2; i++) {
        if(j%i == 0) {
            return 0;
        }
    }
    return 1;
}
int calc_prime(int i) {
    int curN = 1;
    while(i > 0) {
        curN++;
        if(isPrime(curN)) i--;
    }
    return curN;
}
int main() {
    int N;
    scanf("%d", &N);
    time_t time1 = time(NULL);
    struct timeval t1;
    gettimeofday(&t1, NULL);
    for(int i = 0; i < N; i++) {
        int Ai;
        scanf("%d", &Ai);
        int pid = fork();
        if(pid == -1) {
            perror("FORK ERROR");
        } else if(pid == 0) {

            printf("CHILD %d: %d\n\n",i, calc_prime(Ai));

            return 0;
        }
    }
    while(wait(NULL) != -1) {}
    printf("PARENT WAITED FOR ALL\n");
    time_t time2 = time(NULL);
    struct timeval t2;
    gettimeofday(&t2, NULL);
    printf("ELAPSED SECONDS: %lu\n", time2 - time1);
    printf("ELAPSED MICROSECONDS: %lu\n", t2.tv_sec*1000000 - t1.tv_sec*1000000 + t2.tv_usec - t1.tv_usec);
    return 0;
}