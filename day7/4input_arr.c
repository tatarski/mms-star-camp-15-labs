#include<stdio.h>
void print_arr(int* arr, int N) {
    // printf("%ld\n", sizeof(arr));

    for(int* i=arr; i<arr+N; i++) {
        printf("%d ", *i);
    }
}
void input_array(int* arr, int N) {
    for (int *i = arr; i < arr + N; i++)
    {
        printf("BEFORE SCANF\n");
        scanf("%d", i);
        printf("AFTER SCANF\n");
    }
}
int main() {
    int arr[10];
    input_array(arr, sizeof(arr)/sizeof(arr[0]));
    print_arr(arr, sizeof(arr)/sizeof(arr[0]));
    return 0;
}