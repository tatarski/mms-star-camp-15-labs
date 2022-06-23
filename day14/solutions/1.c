#include<stdio.h>
int isPrime(unsigned int N) {
    for(int i = 2; i < N; i++) {
        if(N%i == 0) {
            return 0;
        }
    }
    return 1;
}
unsigned int getIthPrime(unsigned int i) {
    unsigned int curN = 1;
    while(i > 0) {
        curN += 1;
        if(isPrime(curN)) {
            i--;
        }
    }
    return curN;
}
int main() {
    printf("%u\n", getIthPrime(1));
    printf("%u\n", getIthPrime(2));
    printf("%u\n", getIthPrime(3));
    printf("%u\n", getIthPrime(4));
    printf("%u\n", getIthPrime(5));
    return 0;
}