#include<stdio.h>
void print_arr(int* arr, int N) {
    for(int* i=arr; i<arr+N; i++) {
        printf("%d ", *i);
    }
}
void input_array(int* arr, int N) {
    for (int *i = arr; i < arr + N; i++)
    {
        scanf("%d", i);
    }
}
void sort_array(int* arr, int N) {
    /// N*N
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            printf("COMPARING arr[%d]=%d and arr[%d]=%d\n", i, arr[i], j, arr[j]);
            if(i < j && arr[i] > arr[j]) {
                printf("SWAP\n\n");
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}
int main() {
    int arr[10];
    input_array(arr, 10);
    sort_array(arr, 10);
    print_arr(arr, 10);
}