#include<stdio.h>
/// precision - 8
// 0 < n < 1000
// 0 < res < 10
double my_cbrt(double n) {
    double epsilon = 0.00000001;
    for(double i = 0; i < 10; i+=epsilon) {
        if(n - i*i*i < epsilon) {
            return i;
        }
    }
    return -1;
}
int main() {
    printf("cbrt(10) %lf\n", my_cbrt(10)); // 2.1544
    printf("cbrt(8) %lf\n", my_cbrt(8)); // 2
    printf("cbrt(100) %lf\n", my_cbrt(100)); // 4.6415
}