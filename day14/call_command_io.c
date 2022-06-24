#include<stdio.h>
#include<sys/time.h>
#include<unistd.h>
#include<wait.h>
#include<sys/types.h>
#include<stdlib.h>
#include<fcntl.h>
int childPid;
int main(int argc, char *argv[]) {
    int fd_in, fd_out;
    fd_in = open("in", O_RDONLY);
    fd_out = open("out", O_WRONLY);
    dup2(fd_in, 0);
    dup2(fd_out, 1);
    execvp(argv[1], argv + 1);
    printf("ERROR");
}