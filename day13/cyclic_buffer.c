#include<stdio.h>
#include<stdlib.h>
// arr[???], tail, head, max_elem_count
typedef struct CyclicBuffer {
    char *arr;
    size_t head, tail, max_elem_count;
} CyclicBuffer;

int create_buffer(CyclicBuffer *cb, size_t max_elem_count) {
    cb->arr = (char*)calloc(max_elem_count, sizeof(char));
    if(cb->arr == NULL) {
        perror("Create_buffer: Malloc failed!\n");
        return -1;
    }
    cb->max_elem_count = max_elem_count;
    cb->head = 0;
    cb->tail = 0;
    return 0;
}
// -1 - error
// 0 - success
int push_back(CyclicBuffer *cb, char newElem) {
    size_t next_tail = (cb->tail+1)%cb->max_elem_count;
    if(next_tail == cb->head) {
        perror("Push_back: Buffer is full\n");
        return -1;
    }
    cb->arr[cb->tail] = newElem;
    // cb->tail++;
    // if(cb->tail >= cb->max_elem_count) {
    //     cb->tail = 0;
    // }
    cb->tail = next_tail;
    return 0;
}
int pop_front(CyclicBuffer *cb, char *res) {
    if(cb->head == cb->tail) {
        perror("Pop_front: Buffer is empty\n");
        return -1;
    }
    *res = cb->arr[cb->head];
    cb->head = (cb->head+1)%cb->max_elem_count;
    return 0;
}
void print_buffer(CyclicBuffer *cb) {
    for(int i = 0; i < cb->max_elem_count; i++) {
        printf("%c ", cb->arr[i]);
    }
    printf("\n");
    for(int i = 0; i < cb->max_elem_count; i++) {
        if(i == cb->head) {
            printf("H ");
        } else {
            printf("  ");
        }
    }
    printf("\n");
    for(int i = 0; i < cb->max_elem_count; i++) {
        if(i == cb->tail) {
            printf("T ");
        } else {
            printf("  ");
        }
    }
    printf("\n");
}
int main() {
    CyclicBuffer cb1;
    create_buffer(&cb1, 8);
    char pop_result;
    while(1) {
        char i;
        scanf("%c", &i);
        if(i == 'A') { // ADD
            push_back(&cb1, 'Q');
            print_buffer(&cb1);
        } else if(i == 'R') { // Remove
            pop_front(&cb1, &pop_result);
            print_buffer(&cb1);
        } else if(i == 'E') {
            break;
        }
    }
    free(cb1.arr);
}