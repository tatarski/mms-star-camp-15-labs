#include<stdio.h>
void test() {
    int b=10, c=10;
    b = c+b;
    test2();
}
void test2() {
    int c = 900;c = c + 10
}
int main() {
    int a = 10;
    printf("%d", a);
    printf("%p", &a);
    test();
    return 0;
}
call stack:
