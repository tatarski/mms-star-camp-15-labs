#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<fcntl.h>
#include<wait.h>
void onalarm(int pid) {
    // if(child is still running) {
    //     kill(childPid, SIGKILL);
    // }
}
int main(int argc, char* argv[]) {
    int pid;
    if((pid=fork())==-1) {
        perror("Fork faileed\n");
    } else if(pid == 0) {
        // CHILD PROCESS
        int fdIn = open(argv[1], O_RDONLY);
        int fdOut = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0777);
        if (fdIn < 0)
        {
            perror("Open inFile failed");
            return -1;
        }
        if (fdOut < 0)
        {
            perror("Open outFile failed");
            return -1;
        }
        // 1(stdout) ---> file with name argv[2]
        dup2(fdOut, 1);
        // close(1)
        // dup(fdOut)

        // 0(stdin) ---> file with name argv[1]
        dup2(fdIn, 0);
        execvp(argv[3], argv + 3);
        perror("EXEC FAILED");
        return -1;
    } else {
        signal(SIGALRM, onalarm);
        alarm(1);
        int statusCode;
        wait(&statusCode);
        alarm(0);
        if(WIFEXITED(statusCode)) {
            printf("CHILD TERMINATTED SUCCESSFULLY\n");
        } else {
            printf("CHILD TERMINATED UNSUCCESSFULLY\n");
        }
    }
}