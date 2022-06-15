#include<stdio.h>
typedef struct Stack {
    char *arr;
    int elem_count;
    int max_elem_count;
} Stack;
// 0 - success
// -1 - error
int push(Stack *s_p, char new_el) {
    if (s_p->elem_count == (*s_p).max_elem_count)
    {
        perror("PUSH: Stack is full\n");
        return -1;
    }
    s_p->arr[s_p->elem_count] = new_el;
    s_p->elem_count++;
    return 0;

}
int pop(Stack *s_p, char *res) {
    if(s_p->elem_count == 0) {
        perror("POP: Stack is empty\n");
        return -1;
    }
    s_p->elem_count--;
    if(res != NULL) {
        *res = s_p->arr[s_p->elem_count]; // Store popped element in *res
    }
    return 0;
}
void print_stack(Stack *s_p) {
    for(int i = 0; i < s_p->max_elem_count; i++) {
        printf("%c ", s_p->arr[i]);
    }
    printf("\n elem_count=%d\n\n", s_p->elem_count);
}
int main() {
    char stack_arr[20];
    Stack s1;
    s1.arr = stack_arr;
    s1.elem_count = 0;
    s1.max_elem_count = 20;
    push(&s1, 'a');
    print_stack(&s1);

    push(&s1, 'b');
    print_stack(&s1);

    push(&s1, 'c');
    print_stack(&s1);

    push(&s1, 'c');
    print_stack(&s1);

    pop(&s1, NULL);
    print_stack(&s1);

    pop(&s1, NULL);
    print_stack(&s1);

    pop(&s1, NULL);
    print_stack(&s1);

    push(&s1, 'X');
    print_stack(&s1);

    push(&s1, 'Y');
    print_stack(&s1);
}

