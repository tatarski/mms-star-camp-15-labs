// 0000 0000
// -17
// 1110 1111
//  18
// 0001 0010
// ^
// 1111 1101 - otricatelno

// 18
// 0001 0010
// 19
// 0001 0011
// ^
// 0000 0001 - polojitelno

// -20
// 1110 1100
// -5
// 1111 1011
// ^
// 0001 0111 - polojitelno
#include<stdio.h>
int main() {
    int A,B, res;
    scanf("%d", &A);
    scanf("%d", &B);

    res = (A^B) < 0;
    printf("%d\n", res);
    return 0;
}