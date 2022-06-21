#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
double distance(double x1, double y1,
                double x2, double y2)
{
    double xD = x1-x2, yD = y1-y2;
    return sqrt(xD*xD + yD*yD);
}
int isInCircle(double cX, double cY, double r,
        double x, double y) {
    return distance(cX, cY, x, y) < r;
    // if(distance(cX, cY, x, y) < r) {
    //     return 1;
    // } else {
    //     return 0;
    // }
}

int main() {
    char n_str[100],
        filename[100];
    int n_len = 0, filename_len = 0;
    char curSymbol = 0;
    while(curSymbol != ' ' && curSymbol != '\n') {
        read(0, &curSymbol, 1);
        n_str[n_len] = curSymbol;
        n_len++;
    }
    n_str[n_len-1] = '\0';

    curSymbol = 0;
    while (curSymbol != ' ' && curSymbol != '\n')
    {
        read(0, &curSymbol, 1);
        filename[filename_len] = curSymbol;
        filename_len++;
    }
    filename[filename_len-1] = '\0';
    // printf("%s\n%s\n", n_str, filename);
    int N = atoi(n_str);
    int fd = open(filename, O_WRONLY | O_CREAT | O_EXCL, 0777);
    if(fd == -1) {
        char err_msg[] = "COULD NOT OPEN FILE\n";
        write(2, err_msg, strlen(err_msg));
        return -1;
    }
    if(write(fd, "P1\n", 3) != 3) {
        write(2, "WRITE ERROR\n", 12);
        close(fd);
        return -1;
    }
    write(fd, n_str, strlen(n_str));
    write(fd, " ", 1);
    write(fd, n_str, strlen(n_str));
    write(fd, "\n", 1);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(isInCircle(N/2., N/2., 10., i, j)) {
                write(fd, "1 ", 2);
            } else {
                write(fd, "0 ", 2);
            }
        }
        write(fd, "\n", 1);
    }
    close(fd);
}