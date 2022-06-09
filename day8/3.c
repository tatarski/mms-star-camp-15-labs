#include<stdio.h>
void store_substring(char* str, int begin, int len, char* dest) {
    for(int i = begin; i < begin+len; i++, dest++) {
        *dest = str[i];
    }
    *dest = '\0';
}
int main() {
    int a =10, b = 20;
    char res[100];
    store_substring("0123456789ABCDEFGHIJ", 0, 5, res);
    printf("%s\n", res);
    return 0;
}