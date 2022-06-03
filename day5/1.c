#include<stdio.h>
int main() {
    unsigned int N, P;
    scanf("%u", &N);
    scanf("%u", &P);
    unsigned int mask = 1 << (P-1);
    unsigned int result = !!(N & mask);
    unsigned int result2 = (N & mask)>>(P-1);
    printf("%u\n", result);
    printf("%u\n", result2);

    return 0;
}