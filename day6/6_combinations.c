#include<stdio.h>
int combinations(int N, int K) {
    // Base case
    // Remove this === recursion will never end 
    // === stack overflow
    if(N == K || K == 0) {
        return 1;
    }
    // General case
    return combinations(N-1, K-1) +
        combinations(N-1, K);
}
void combinations2(int N, int K, int* count) {
    int a;
    if(N == K || K == 0) {
        printf("%p ", count);
        (*count)++;
        // Next 2 lines do the same thing
        // *count++;
        // *(count++);
        printf("%p\n", count);
        return;
    }
    combinations2(N-1, K-1, count);
    combinations2(N-1, K, count);
    return;
}
int main() {
    printf("%d\n", combinations(49, 6));
    int res = 0;
    combinations2(49, 6, &res);
    printf("%d\n", res);
    return 0;
}