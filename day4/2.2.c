#include<stdio.h>
int main() {
    unsigned int a,b,minAB, temp;
    scanf("%u", &a);
    scanf("%u", &b);
    while(b!=0) 
    {
        if(a < b) {
            temp = a;
            a = b;
            b = temp;
        }
        a = a-b;
    }
    printf("%d", a);
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


a   b
100 99
99  1
98  1
97  1
96  1
95  1


10000000000 9999999999
9999999999  1
9999999998  1
9999999997  1
9999999998  
*/