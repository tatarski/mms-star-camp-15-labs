#include<stdio.h>
#include<string.h>

int s_to_uint(char* str, unsigned int* res_p) {
    unsigned int pow_10 = 1, sum = 0, digit_value;
    for (int i = strlen(str) - 1; i >= 0; i--)
    {
        if(!(str[i] >= '0' && str[i] <= '9')) {
            return -1;
        }
        printf("proccessing str[%d] = %c\n", i, str[i]);
        digit_value = str[i] - '0';
        sum += pow_10 * digit_value;
        pow_10 *= 10;
    }
    *res_p = sum;
    return 0;
}
int main() {
    char str[100];
    unsigned int res;
    scanf("%s", str);
    if(s_to_uint(str, &res) == 0) {
        printf("VALID NUMBER %u\n", res);
    } else {
        printf("INVALID NUMBER\n");
    }
}