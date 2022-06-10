#include<stdio.h>
int fold(int init, int (*op)(int, int), int (*i_step)(int), int* arr, int n) {
    int res = init;
    for(int i = 0; i < n; i=i_step(i)) {
        res = op(res, arr[i]);
    }
    return res;
}
int sum(int a, int b) {
    return a + b;
}
int product(int a, int b) {
    return a*b;
}
int min(int a, int b) {
    return a<b?a:b;
}
int max(int a, int b) {
    return a>b?a:b;
}
int add_1(int i) {
    return i+1;
}
int add_2(int i) {
    return i+2;
}
int main() {
    int arr[] = {1,2,3,4,5};
    int sum_arr = fold(0, sum, add_1, arr, 5),
        product_arr = fold(1, product, add_1, arr, 5),
        min_arr = fold(arr[0], min, add_1, arr, 5),
        max_arr = fold(arr[0], max, add_1, arr, 5);
    printf("sum %d\n product %d\n min %d\n max%d", sum_arr, product_arr, min_arr, max_arr);
}