#include<stdio.h>
#include<stdlib.h>
typedef struct circular_buffer {
    char* arr;
    size_t head, tail, max_size;
} circular_buffer;
int create_circular_buffer(size_t max_size, circular_buffer *res) {
    res->arr = (char*)calloc(max_size, sizeof(char));
    if(res->arr == NULL) {
        perror("Malloc failed\n");
        return -1;
    }
    res->max_size = max_size;
    res->head = 0;
    res->tail = 0;
    return 0;
}
ssize_t get_next_index(ssize_t i, ssize_t size) {
    return (i+1)%size;
}
int push(circular_buffer *cb, char newElem) {
    // One element remains empty
    ssize_t nextIndex = get_next_index(cb->tail, cb->max_size);
    if(nextIndex == cb->head) {
        perror("Buffer full\n");
        return -1;
    }
    cb->arr[cb->tail] = newElem;
    cb->tail = nextIndex;
    return 0;
}
int pop(circular_buffer *cb, char *res) {
    if(cb->tail == cb->head) {
        perror("Buffer empty");
        return -1;
    }
    if(res != NULL) {
        *res = cb->arr[cb->head];
    }
    cb->head = get_next_index(cb->head, cb->max_size);
    return 0;
}
void print_buffer(circular_buffer *cb) {
    for(int i = 0; i < cb->max_size; i++) {
        printf("%c ", cb->arr[i]);
    }
    printf("\n");
    for (int i = 0; i < cb->max_size; i++)
    {
        if(i == cb->head) {
            printf("H ");
        } else {
            printf("  ");
        }
    }
    printf("\n");
    for (int i = 0; i < cb->max_size; i++)
    {
        if(i == cb->tail) {
            printf("T ");
        } else {
            printf("  ");
        }
    }
    printf("\n");
}
void delete_buffer(circular_buffer *cb) {
    free(cb->arr);
}
int main() {
    circular_buffer cb1;
    create_circular_buffer(8, &cb1);
    while(1) {
        char c;
        scanf("%c", &c);
        if(c=='\n') {
            continue;
        }
        if(c=='I') {
            push(&cb1, 'A');
        } else {
            pop(&cb1, NULL);
        }
        print_buffer(&cb1);
    }
    return 0;
}