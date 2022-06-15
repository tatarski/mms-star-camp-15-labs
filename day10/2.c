#include<stdio.h>
int main() {
    int arr[32];
    for(int i = 0; i < 32; i++) {
        arr[i] = 0;
    }
    unsigned int N, i = 31;
    printf("%lu", sizeof(int));
    scanf("%u", &N);
    while(N != 0) {
        // printf("%d", N&1);
        arr[i] = N&1;
        N >>= 1;
        i--;
    }
    for(int i = 0; i < 32; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");
}