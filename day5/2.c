#include<stdio.h>
#include<math.h>
int main() {
    unsigned int N, nBits=0;
    scanf("%u", &N);
    printf("%d\n", (int)log2(N) + 1);
    // printf("%d\n", (int)ceil(log2(N)));

    while(N != 0) {
        N = N >> 1;
        nBits++;
    }
    printf("%u\n", nBits);
}

/// 26 = 16+8+2
/// 11010
///             N
/// nBits=0 11010
/// nBits=1  1101
/// nBits=2   110
/// nBits=3    11
/// nBits=4     1
/// nBits=5     0
/// nBits=5     0