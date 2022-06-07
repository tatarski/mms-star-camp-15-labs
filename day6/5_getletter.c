#include<stdio.h>
void store_nth_letter(int N, char* res_pointer) {
    // Result is stored in variable with address === res_pointer
   *res_pointer = 'a' + N - 1;
}
int main() {
    int N;
    scanf("%d", &N);
    char res;
    store_nth_letter(N, &res);
    printf("%c\n", res);
    return 0;
}