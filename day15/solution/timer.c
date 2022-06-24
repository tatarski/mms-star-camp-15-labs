#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<wait.h>
#include<sys/time.h>
int main(int argc, char *argv[]) {
    struct timeval t1, t2, t3;
    printf("ARGC %d\n", argc);
    int pid;
    gettimeofday(&t1, NULL);
    if((pid=fork())==-1) {
        perror("Fork failed\n");
        exit(-1);
    } else if(pid == 0) {
        printf("IN CHILD PROCESS\n");
        execvp(argv[1], argv + 1);
        perror("Exec failed\n");
        return -1;
    } else {
        printf("IN PARENT PROCESS\n");

        gettimeofday(&t3, NULL);
        wait(NULL);
        gettimeofday(&t2, NULL);
        printf("CHILD IS DONE\n");
        printf("TIME ELAPSED MICROSECONDS BEFORE FORK: %ld\n", t2.tv_sec * 1000000 - t1.tv_sec * 1000000 + t2.tv_usec - t1.tv_usec);
        printf("TIME ELAPSED MICROSECONDS BEFORE WAIT: %ld\n", t2.tv_sec * 1000000 - t3.tv_sec * 1000000 + t2.tv_usec - t3.tv_usec);
    }
    // execl
}