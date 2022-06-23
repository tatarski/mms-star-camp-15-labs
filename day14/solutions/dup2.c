#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main() {
    dup2(2, 1);
    printf("HELLO WORLD!\n"); // FD - 1
    return 0;
}