#include<stdio.h>
unsigned int sum_digits(unsigned int N) {
    unsigned int sum = 0;
    for(;N>0;N/=10) {
        sum+=N%10;
    }
    return sum;
}

unsigned int sum_digits_rec(unsigned int N) {
    if(N==0) {
        return 0;
    }
    return sum_digits_rec(N/10) + N%10;
}
/// sum_digits_rec(12345) = sum_digits_rec(1234) + 5
/// sum_digits_rec(1234) = sum_digits_rec(123) + 4
/// sum_digits_rec(123) = sum_digits_rec(12) + 3
/// sum_digits_rec(12) = sum_digits_rec(1) + 2
/// sum_digits_rec(1) = sum_digits_rec(0) + 1
/// sum_digits_rec(0) = 0
int main() {
    printf("%u\n", sum_digits_rec(92347898));
}