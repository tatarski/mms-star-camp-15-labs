#include<stdio.h>
#include<sys/time.h>
#include<unistd.h>
#include<wait.h>
#include<sys/types.h>
#include<stdlib.h>
#include<fcntl.h>
int childPid;
void on_timer_send_signal(int signal) {
    kill(childPid, SIGKILL);
    printf("KILLED CHILD\n");
    alarm(0);
    exit(-1);
}
int main(int argc, char *argv[]) {
    int pid = fork();
    struct timeval t1;
    gettimeofday(&t1, NULL);
    if(pid == 0) {
        close(1);
        execvp(argv[1], argv+1);
        printf("ERROR");
        return -1;
    }
    childPid = pid;
    signal(SIGALRM, on_timer_send_signal);
    alarm(1);
    wait(NULL);
    struct timeval t2;
    gettimeofday(&t2, NULL);
    printf("ELAPSED MICROSECONDS: %lu\n", t2.tv_sec*1000000 - t1.tv_sec*1000000 + t2.tv_usec - t1.tv_usec);
}