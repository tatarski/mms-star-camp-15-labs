#include<stdio.h>
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void store_nth_letter(int n, char* res) {
    *res = 'A' + n;
}
int main() {
    int a = 100, b = 23;
    swap(&a,&b);
    printf("a=%d b=%d\n", a, b);
}