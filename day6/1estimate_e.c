#include<stdio.h>
#include<math.h>
unsigned long factoriel(int n) {
    unsigned long product = 1;
    for(int i = 1; i<=n; i++) {
        product *= i;
    }
    return product;
}
// factoriel(0) == 1
// factoriel(n) = factoriel(n-1)*n
unsigned long factoriel_recursive(int n) {
    if(n == 0) {
        return 1;
    }
    return factoriel_recursive(n-1)*n;
}
int main() {
    double e_sum = 0;
    for(int i = 0; i < 20; i++) {
        e_sum += 1./factoriel(i);
    }
    printf("%f\n", e_sum);

    printf("%f\n", pow(1 + 1./300, 300));
    return 0;
}