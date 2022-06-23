#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main() {
    char str[100] = "Hello world";
    int pid1 = fork();  // Parent      Child1
    // int pid2 = fork();  //Parent Child2  Child1 Child3
    if(pid1 == -1) {
        perror("Fork failed\n");
    } else if(pid1 == 0) {
        printf("Child process: %s\n", str);
        return 0;
    } else {
        sleep(3);
        if(wait(NULL) != -1) {
            printf("Child process has not terminated - waiting for it");
        } else {
            printf("Child process has terminated - no waiting");
        }
        if (wait(NULL) != -1)
        {
            printf("Child process has not terminated - waiting for it");
        }
        else
        {
            printf("Child process has terminated - no waiting");
        }
        printf("Parent process: %s\n", str);
    }
    return 0;
}