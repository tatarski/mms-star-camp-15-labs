#include<stdio.h>
void print_arr(unsigned short* arr, int N) {
    for(unsigned short* i=arr; i<arr+N; i++) {
        printf("%hu ", *i);
    }
    printf("\n");
}
void input_array(unsigned short* arr, int N) {
    for (unsigned short *i = arr; i < arr + N; i++)
    {
        scanf("%hu", i);
    }
}
void sort_array(int* arr, int N) {
    /// N*N
    for(int i = 0; i < N; i++) {
        for(int j = i+1; j < N; j++) {
            // printf("COMPARING arr[%d]=%d and arr[%d]=%d\n", i, arr[i], j, arr[j]);
            if(arr[i] > arr[j]) {
                // printf("SWAP\n");
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
        printf("\n");
    }
}

void counting_sort(unsigned short* arr, int n) {
    int n_of_occurances[1 << 16];
    for(int i = 0; i < (1<<16); i++) {
        n_of_occurances[i] = 0;
    }
    for(int i = 0; i < n; i++) {
        n_of_occurances[arr[i]]++;
    }
    for(int i = 0; i < (1<<16); i++) {
        if(n_of_occurances[i] != 0) {
            printf("NUMBER: %d N_OF_OCCURANCES:%hu\n",i, n_of_occurances[i]);
            for(int j = 0; j < n_of_occurances[i]; j++) {
                *arr = i;
                arr++;
            }
        }
    }
}
int main() {
    unsigned short arr[10];
    int N;
    scanf("%d", &N);
    input_array(arr, N);
    counting_sort(arr, N);
    print_arr(arr, N);
}