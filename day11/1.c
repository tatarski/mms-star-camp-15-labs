#include<stdio.h>
int main() {
    int mask;
    scanf("%d", &mask);
    switch (mask)
    {
    case 1:
        printf("a");
        break;
    case 2:
        printf("b");
        break;
    case 3:
        printf("ab");
        break;
    case 4:
        printf("c");
        break;
    case 5:
        printf("ac");
    default:
        break;
    }
    printf("\n");
    return 0;
}