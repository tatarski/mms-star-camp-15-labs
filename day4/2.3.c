#include<stdio.h>
int main() {
    unsigned int a,b,minAB, temp;
    scanf("%u", &a);
    scanf("%u", &b);
    while(b!=0 && a!=0) 
    {
        if(a < b) {
            temp = a;
            a = b;
            b = temp;
        }
        printf("%u %u\n", a, b);
        a = a%b;
    }
    printf("%d\n", b);
    return 0;
}