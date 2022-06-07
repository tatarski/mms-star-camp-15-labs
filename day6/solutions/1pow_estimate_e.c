#include<stdio.h>
#include<math.h>
int main() {
    int N = 100;
    double e_pow = pow(1.+1./N, N);
    // printf("%d", factoriel_result);
    printf("%f", e_pow);
}