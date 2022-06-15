#include<stdio.h>
int main() {
    unsigned int N, nrows, ncols;
    scanf("%u %u %u", &N, &nrows, &ncols);
    unsigned int col, row;
    row = N/ncols;
    col = N%ncols;
    printf("row=%u col=%u\n", row, col);
    return 0;
}