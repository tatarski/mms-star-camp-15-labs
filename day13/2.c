#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc, char **argp) {
    umask(0000);
    int N = atoi(argp[1]);
    FILE *fp = fopen(argp[2], "w");
    if(fp == NULL) {
        perror("Error opening file\n");
        return -1;
    }
    for(int i = 0; i < N; i++) {
        fprintf(fp, "%d ", i);
        if((i+1)%12 == 0) {
            fprintf(fp, "\n");
        }
    }
    fclose(fp);
    return 0;
}