#include<stdio.h>
void printSymbols() {
    for (char i = 0; i < 255; i++)
    {
        printf("%c %d \n", i, (int)i);
    }
}
char capitalize(char sym) {
    if(sym >= 'a' && sym <= 'z') {
        return sym - 'a' + 'A';
    }
    return 0;
}
int factoriel(int n) {
    if(n < 0) {
        return -1;
    } else if(n == 0) {
        return 1;
    } else {
        return factoriel(n-1)*n;
    }
}
int main() {
    // What is going on?
    // for(char i = 0; i < 255; i++) {
    //     printf("%c %d \n", i, (int)i);
    // }
    return 0;
}