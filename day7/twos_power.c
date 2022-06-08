#include<stdio.h>
int is_twos_power(unsigned int N) {
    return !(N & (N-1));
}
int multiply_by_seven(unsigned int N) {
    return (N<<3) - N; // N*8 - N = N*7
}
int main() {
    unsigned int N, set_bit_count = 0;
    scanf("%u", &N);
    // printf("\n");
    if(is_twos_power(N)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}

/// N = 1110110
///              &
///N-1= 1110101

/// N = 1000000
///           &
///N-1=  111111
///           0

/// N = 1000001
///           &
///N-1= 1000000
///     1000000