#include<stdio.h>
void change_letters(char* str) {
    for(int i = 0; str[i] != '\0' ;i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] - 'A' + 'a';
        }
        else if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - 'a' + 'A';
        }
    }
}
int main() {
    char str1[100];
    scanf("%s", str1);
    change_letters(str1);
    printf("%s\n", str1);
}