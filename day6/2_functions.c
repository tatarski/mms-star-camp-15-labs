#include<stdio.h>
// Return type == void
// E.G. We cannot write print_symbols() + 5
void print_symbols() {
    for(char c = -128; c < 127; c++) {
        printf("%c %d\n", c, c);
    }
}
char capitalize(char c) {
    if(!(c >= 'a' && c <= 'z')) {
        return 0;
    }
    // printf("%c\n", c + ('A' - 'a'));
    return c + ('A' - 'a');
}
int main() {
    printf("%c\n", capitalize('a'));
    printf("%c\n", capitalize('p'));
    printf("%c\n", capitalize('1'));
    printf("%c\n", capitalize('.'));

}