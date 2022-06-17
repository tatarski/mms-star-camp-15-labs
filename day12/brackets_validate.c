#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
    s_p->arr[s_p->elem_count] = 0;
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
char get_last(Stack *s_p) {
    if(s_p->elem_count == 0) {
        perror("GET_LAST: Stack is empty\n");
        exit(-1);
    }
    return s_p->arr[s_p->elem_count - 1];
}

// 0 - not matching
// 1 - matching
// <>, [], {}, ()
int are_brackets_matching(char left_bracket, char right_bracket) {
    return (left_bracket == '<' && right_bracket == '>') ||
           (left_bracket == '[' && right_bracket == ']') ||
           (left_bracket == '{' && right_bracket == '}') ||
           (left_bracket == '(' && right_bracket == ')');
}

// [()] - OK
// ([)] - NOT OK
//   ^
// STACK: ([ -- NOT OK
// 
// {[()[]]} - OK
//        ^
// STACK: -- OK 
// [({]}) - NOT OK

// {[()]}
//     ^
// Stack: {[
int is_balanced(char *str) {
    Stack brackets_stack = create_stack(strlen(str));

    for(char *sym_p = str; (*sym_p) != '\0'; sym_p++) {
        print_stack(&brackets_stack);
        if(*sym_p == '<' || *sym_p == '[' || *sym_p == '(' || *sym_p == '{') {
            // *sym_p is opening bracket
            push(&brackets_stack, *sym_p);
        }
        else if (brackets_stack.elem_count != 0 &&
                 are_brackets_matching(get_last(&brackets_stack), *sym_p))
        {
            // *sym_p is closing bracket
            // opening and closing brackets match
            pop(&brackets_stack, NULL);
        }
        else
        {
            // Opening and closing brackets do not match
            return 0;
        }
    }
    if(brackets_stack.elem_count == 0) {
        return 1;
    } else {
        // If stack is not empty - theere are open brackets that have no closing
        return 0;
    }
}
int main() {
    char str_1[100];
    scanf("%s", str_1);
    printf("%d\n", is_balanced(str_1));
}