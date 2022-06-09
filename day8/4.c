#include<stdio.h>
int isBalanced(char* str) {
    int n_open = 0;
    for(; *str != '\0'; str++) {

        printf("%c %p", *str, str);
        // if(*str == '(') {
        //     n_open++;
        // }
        // if(*str == ')') {
        //     if(n_open == 0) {
        //         return 0;
        //     } else {
        //         n_open--;
        //     }
        // }
    }
    if(n_open == 0) {
        return 1;
    }
    return 0;
}
int main() {
    char str[100];
    scanf("%s", str);
    printf("%d\n",isBalanced(str));
    return 0;
}

// ((()))
//      ^
// nOpen = 0 -- YES

// ((())
//     ^
// nOpen = 1 -- NO

// ())(()
//   ^
// nOpen = 0 -- NO