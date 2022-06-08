#include<stdio.h>
void print_arr(int* arr, int N) {
    printf("%ld\n", sizeof(arr));

    for(int* i=arr; i<arr+N; i++) {
        printf("%d ", *i);
    }
}
int main() {
    int arr[] = {1,2,3,4,5,6};// 24byte == br*4byte
    printf("%ld\n", sizeof(arr));
    printf("%ld\n", sizeof(int));
    int a = 10;

    printf("%ld\n", sizeof(arr)/sizeof(int));
    print_arr(arr, 8);
    return 0;
}