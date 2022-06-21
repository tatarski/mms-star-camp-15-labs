#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
void int_to_string(int N, char *str) {
    if(N == 0) {
        str[0] = '0';
        str[1] = '\0';
        return;
    }
    int len = 0;
    while(N>0) {
        str[len] = N%10 + '0';
        N/=10;
        len++;
    }
    char temp;
    for(int i = 0; i < len/2; i++) {
        temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
    str[len] = '\0';
}
int main(int argc, char **argp) {
    int N = atoi(argp[1]);
    char buf[30];
    // 0 - stdin
    // 1 - stdout
    // 2 - stderr
    // write(1, "TEST", 4);
    int fd = open(argp[2], O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if(fd == -1) {/*Error*/}
    for(int i = 0; i < N; i++) {
        int_to_string(i, buf);
        write(fd, buf, strlen(buf));
        write(fd, " ", 1);
        if((i+1)%12 == 0) {
            write(fd, "\n", 1);
        }
    }
    close(fd);
}