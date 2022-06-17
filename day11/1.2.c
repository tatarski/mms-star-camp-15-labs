#include<stdio.h>
//  1011 == 11
//  &
//  0010 == 2 == 0001 << 1 == 0010
// =============
//  0010 == 2

//  1000 == 8
//  &
//  0010
//  ============
//  0000== 0
int main() {
    int mask;
    scanf("%d", &mask);

    if(mask & (1<<0)) {
        printf("a");
    }
    if(mask & (1<<1)) {
        printf("b");
    }
    if(mask & (1<<2)) {
        printf("c");
    }
    if(mask & (1<<3)) {
        printf("d");
    }
    printf("\n");
    return 0;
}