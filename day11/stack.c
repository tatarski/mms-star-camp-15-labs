#include<stdio.h>
#include<stdlib.h>
typedef struct Stack {
    char *arr;
    int elem_count;
    int max_elem_count;
} Stack;
Stack create_stack(int max_elem_count) {
    Stack res;
    res.arr = (char *)malloc(sizeof(char)*max_elem_count);
    if(res.arr == NULL) {
        perror("Malloc error\n");
        exit(-1);
    }
    res.elem_count = 0;
    res.max_elem_count = max_elem_count;
    return res;
}
void delete_stack(Stack s) {
    free(s.arr);
}
// 0 -sucess
// -1 - error
int create_stack_2(int max_elem_count, Stack *res_p) {
    res_p->arr = (char*)malloc(sizeof(char)*max_elem_count);
    if(res_p->arr == NULL) {
        return -1;
    }
    res_p->elem_count = 0;
    res_p->max_elem_count = max_elem_count;
    return 0;
}
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
    Stack s1;
    create_stack_2(1<<(5), &s1);
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

    delete_stack(s1);
    return 0;
}

