#include<stdio.h>
int main() {
    unsigned int a,b,minAB;
    scanf("%u", &a);
    scanf("%u", &b);
    if(a > b) {
        minAB = b;
    } else {
        minAB = a;
    }
    for(int i = minAB; i > 0; i--) {
        if(a%i == 0 && b%i == 0) {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}
/*
 a   b
150 100
 50 100
 50 50
 50 0
*/

/*
a  b
48 64
48 16
32 16
16 16
16 0
*/