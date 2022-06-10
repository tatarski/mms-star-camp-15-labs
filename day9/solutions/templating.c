#include<stdio.h>
#include<stdarg.h>
void print_template(char* template_str, ...) {
    va_list varg_ptr;
    va_start(varg_ptr, template_str);
    for(char* i = template_str; *i != '\0'; i++) {
        if(*i == '~') {
            printf("%s", va_arg(varg_ptr, char*));
        } else {
            printf("%c", *i);
        }
        // printf("adress: %p, value: %c\n", i, *i);
    }
    va_end(varg_ptr);
}
void store_template(char* template_str, char* destination_str, ...) {

}
int main() {
    char str[] = "Hello i am ~\n";
    print_template(str, "Ivan", NULL);
    // Hello i am Ivan

    print_template("Hello ~, my name is ~\n", "Ivan", "Georgi", NULL);
    // Hello Ivan, my name is Georgi

    print_template("~ ~ ~ ~\n", "A", "B", "C", NULL);
    // A B C D

    // print_template(NULL);
    char replaced_str[1000];
    store_template("HELO ~, I AM ~", replaced_str, "IVAN", "PESHO");
}