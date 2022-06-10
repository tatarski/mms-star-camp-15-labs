#include<stdio.h>
#include<fcntl.h>
#include<stdarg.h>
// ~ template place
void print_template(char* format_str, ...) {
    va_list varg_ptr;
    va_start(varg_ptr, format_str);

    for(int i = 0; *format_str != '\0'; format_str++) {
        switch (*format_str)
        {
        case '~':
            printf("%s", va_arg(varg_ptr, char*));
            break;
        default:
            printf("%c", format_str[i]);
        }
    }
    va_end(varg_ptr);
}
int main() {
    print_template("HELLO I AM ~", "IVAN");
    return 0;
}