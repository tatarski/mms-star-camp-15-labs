#include<stdio.h>
#define MAX_ITER 30 
int isInside(double x0, double y0) {
    double x= 0, y = 0, iter = 0;
    while(x*x+ y*y<= 2.*2. && iter < MAX_ITER) {
        double xtemp = x*x - y*y + x0;
        y =  2*x*y + y0;
        x = xtemp;
        iter++;
    }
    if(iter == MAX_ITER) {
        return 1;
    } else {
        return 0;
    }
}
void printPGMFile(int w) {
    printf("P1\n%d %d\n", w, w);
    for(int i = 0; i < w; i++) {
        for(int j = 0; j < w; j++) {
            if(isInside((double)i*2./w - 1, (double)j*2./w - 1)) {
                printf("1 ");
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}
int main() {
    printPGMFile(1000);
    return 0;
}