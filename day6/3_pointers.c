#include<stdio.h>
int main() {
    int a = 20;
    int* a_addr = &a;

    char c = 'a';
    char* c_addr = &c;

    unsigned long* b_addr, b;
    b = 10;
    // !Storing address of int in
    // pointer to unsigned long!
    b_addr = &a;

    printf("%d %p\n", *a_addr, a_addr);
    printf("%c %p\n", *c_addr, c_addr);
    printf("%lu %p\n", *b_addr, b_addr);
    // printf("%p\n", addr);

}