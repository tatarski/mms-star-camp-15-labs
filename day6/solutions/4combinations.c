#include<stdio.h>
void count_combinations(int n, int k, int* combination_count) {
    if(n == k || k == 0) {
        *combination_count = *combination_count + 1;
        // *combination_count++; OPAAAA
        return;
    }
    count_combinations(n-1, k-1, combination_count);
    count_combinations(n-1, k, combination_count);
}
int main() {
    int result = 0;
    count_combinations(10, 6, &result);
    printf("%d", result);
}