#include<stdio.h>
int main() {
    unsigned int row, col, rown, coln;
    scanf("%u %u %u %u", &row, &col, &rown, &coln);
    unsigned int N = row*coln + col;
    printf("%u\n", N);
    return 0;
}