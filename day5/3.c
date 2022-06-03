#include<stdio.h>
int main() {
    unsigned int N, M;
    scanf("%u", &N);
    scanf("%u", &M);
    unsigned int quotient, remainder, mask;
    quotient = N >> M;
    mask = (1<<M) - 1;
    remainder = N & mask;
    printf("Q=%u R=%u\n", quotient, remainder);
}
// -17
// 10001
// 
// N=541 M=4
// 541 = 1000011101
//  16 =      10000

// Q=33=     100001
// R=13=       1101

// 541 >> 4 == 33
// 1000011101 >> 4 == 100001

// 0000001111
// 
// N=31 M=2
// 31 = 11111
// 2^M = 1<<2 = 100

// N=  11111
// 2^M=  100
// Q=7=  111
// R=     11

// 1000011101
// &
// 0000001111 == 15
// 0000001101
// 
//       1101

// N = 11111
// M=2
// 2^M = 4 = 100
// 2^M - 1 = 4-1 = 3 = 11
// 11111
// &
// 00011
// =  11