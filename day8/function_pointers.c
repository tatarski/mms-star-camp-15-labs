#include<stdio.h>
char change_letter(char c) {
    if (c >= 'A' && c <= 'Z')
    {
        return c - 'A' + 'a';
    }

    if (c >= 'a' && c <= 'z')
    {
        return c - 'a' + 'A';
    }
    return c;
}
char get_a(char c) {
    return 'A';
}
void change_letters(char* str) {
    for(int i = 0; str[i] != '\0' ;i++) {
        str[i] = change_letter(str[i]);
    }
}
void str_map(char* str, char (*f)(char)) {
    for(int i = 0; str[i] != '\0' ;i++) {
        str[i] = f(str[i]);
    }
}
int main() {
    char str[] = "MMS_C_camp";
    str_map(str, get_a);
    printf("%s\n", str);
    // printf("%p\n", change_letter);

    // char (*f)(char) = change_letter;

    // printf("%p\n", f);

    // printf("%c\n", f('A'));
    // printf("%c\n", change_letter('A'));
    return 0;
}