#include<stdio.h>
#include<time.h>
#include<sys/time.h>

int main() {
    time_t t1 = time(NULL);
    struct timeval tv1, tv2;
    gettimeofday(&tv1, NULL);
    int sum = 0;
    for(int i = 0; i < 1000000000; i++) {
        sum += i;
    }
    printf("%d\n", sum);
    time_t t2 = time(NULL);
    gettimeofday(&tv2, NULL);
    printf("SECONDS ELAPSED: %ld\n", t2-t1);
    printf("TIME ELAPSED MICROSECONDS: %ld\n", tv2.tv_sec*1000000 - tv1.tv_sec*1000000 
        + tv2.tv_usec - tv1.tv_usec);
    return 0;
}