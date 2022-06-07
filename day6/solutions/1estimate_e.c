#include<stdio.h>
int main() {
    long factoriel_result = 1;
    double e_sum = 1;
    int N = 20;
    for(int i = 1; i <= N; i++) {
        factoriel_result *= i;
        e_sum += 1./factoriel_result;

    printf("%li\n", factoriel_result);
    }
    // printf("%d", factoriel_result);
    printf("%f", e_sum);
}