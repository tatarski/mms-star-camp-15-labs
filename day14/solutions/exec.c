#include<stdio.h>
#include<unistd.h>
int main() {
    // execl("fork", "fork", NULL);
    // printf("ERROR");
    // execlp("ls", "ls", NULL);
    // printf("Error");
    char *argv[10];
    argv[0] = "ls";
    argv[1] = "-l";
    argv[2] = NULL;
    execvp("ls", argv);
    perror("Error");
    return 0;
}