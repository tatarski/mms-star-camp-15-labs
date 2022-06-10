#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main() {
    // int fd = open("img.pbm", O_CREAT | O_TRUNC | O_WRONLY, 0777);
    // if(fd < 0) {
    //     perror("ERROR");
    //     return 0;
    // }
    // dup2(fd, 1);
    int n = 10;
    printf("P1\n%d %d\n", n, n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i < j) {
                printf("%d", 0);
            } else {
                printf("%d", 1);
            }
            if(j != n-1) {
                printf(" ");
            }
        }
        printf("\n");
    }
    // fsync(fd);
    // close(1);
    // close(fd);
    return 0;
}