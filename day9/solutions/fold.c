#include<stdio.h>
int sum2(int a, int b) {
    return a+b;
}
int product2(int a, int b) {
    return a*b;
}
int min2(int a, int b) {
    return a<b?a:b;
}
int max2(int a, int b) {
    return a>b?a:b;
}
int square_sum(int cur_res, int b) {
    return cur_res + b*b;
}
int fold(int* arr, int n, int init_value, int (*op)(int, int)) {
    int res = init_value;
    for(int i = 0; i < n; i++) {
        // printf("%d\n", res);
        res = op(res,arr[i]);
    }
    return res;
}
int main() {
    int arr[] = {4,2,5,1,3}, arrLen = 5;
    // max(max(max(max(1, 2), 3), 4), 5)
    printf("average = %f\n", fold(arr, arrLen, 0, sum2)/(double)arrLen);
    // (((((0 + 1) + 2) + 3) + 4) + 5)
    printf("product= %d\n",fold(arr, arrLen, 1, product2));
    // (((((1*1) * 2) * 3) * 4) * 5)
    printf("min= %d\n", fold(arr, arrLen, arr[0], min2));
    // min(min(min(min(1, 2), 3), 4), 5)
    printf("max= %d\n", fold(arr, arrLen, arr[0], max2));
    printf("sum_squared= %d\n", fold(arr, arrLen, 0, square_sum));
    // ((((0+1^2)^2 + 2^2)^2 + 3^2)^2 + 4^2)^2

    // (0+1^2)
}