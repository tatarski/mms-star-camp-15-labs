#include<stdio.h>
#include<string.h>
int main() {
    char str1[100], str2[100];
    scanf("%s", str1);
    str1[5] = 'd';
    printf("%s\n", str1);
    printf("%d\n", (int)str1[6]);
    // scanf("%s", str2);
    // printf("%s %s\n", str1, str2);
    // printf("%ld\n", strlen(str1));
    // printf("%d\n", strcmp(str1, str2));
    // strcpy(str2, str1);

    // printf("%s %s\n", str1, str2);
}