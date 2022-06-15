#include<stdio.h>
// 0 - success
// -1 - error
int push(char *arr, int *elem_count, int max_elem_count, char new_el) {
    if(*elem_count == max_elem_count) {
        perror("PUSH: Stack is full\n");
        return -1;
    }
    arr[*elem_count] = new_el;
    (*elem_count)++;
    return 0;
}
int pop(char *arr, int *elem_count, int max_elem_count, char *res) {
    if(*elem_count == 0) {
        perror("POP: Stack is empty\n");
        return -1;
    }
    (*elem_count)--;
    if(res != NULL) {
        *res = arr[*elem_count]; // Store popped element in *res
    }
    return 0;
}
void print_stack(char *arr, int elem_count) {
    for(int i = 0; i < 10; i++) {
        printf("%c ", arr[i]);
    }
    printf("\n elem_count=%d\n\n", elem_count);
}
int main() {
    char stack_arr[10];
    int elem_count = 0, max_elem_count = 10;
    push(stack_arr, &elem_count, max_elem_count, 'a');
    print_stack(stack_arr, elem_count);

    push(stack_arr, &elem_count, max_elem_count, 'b');
    print_stack(stack_arr, elem_count);

    push(stack_arr, &elem_count, max_elem_count, 'c');
    print_stack(stack_arr, elem_count);

    push(stack_arr, &elem_count, max_elem_count, 'c');
    print_stack(stack_arr, elem_count);

    pop(stack_arr, &elem_count, max_elem_count, NULL);
    print_stack(stack_arr, elem_count);

    pop(stack_arr, &elem_count, max_elem_count, NULL);
    print_stack(stack_arr, elem_count);

    pop(stack_arr, &elem_count, max_elem_count, NULL);
    print_stack(stack_arr, elem_count);

    push(stack_arr, &elem_count, max_elem_count, 'X');
    print_stack(stack_arr, elem_count);

    push(stack_arr, &elem_count, max_elem_count, 'Y');
    print_stack(stack_arr, elem_count);
}
