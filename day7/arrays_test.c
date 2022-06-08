#include<stdio.h>
int arr_global[2];
void print_second_element(int* arr) {
    printf("%d\n", arr[2]);
}
void print_second_element2(int arr[]) {
    printf("%d\n", arr[2]);
}
int* create_arr() {
    int arr[10];
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    return arr;
}
int main() {
    int *arr_begin_address;
    arr_begin_address = create_arr();
    printf("%d", arr_begin_address[3]);
    // int arr[100];
    // arr[0] = 200;
    // arr[1] = 300;
    // arr[2] = 212400;
    // ///...
    // arr[99] = 99;

    // printf("%d\n", *(arr+1));
    // printf("%d\n", *(arr+2));
    // printf("%d\n", *(arr + 3));
    // printf("%d\n", arr[99]);
    // printf("%d\n", arr_global[0]);
    // printf("%d\n", arr_global[1]);

    // print_second_element(arr);
    // print_second_element2(arr);
    // return 0;
}