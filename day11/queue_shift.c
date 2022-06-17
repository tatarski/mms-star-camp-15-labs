#include<stdio.h>
#include<stdlib.h>
// short arr[100];
// int max_elem_count;
// int elem_count;
typedef struct Queue {
    short *arr;
    int max_elem_count;
    int elem_count;
} Queue;
// 0 - sucess
// -1 - error
int create_queue(int max_elem_count, Queue *res) {
    res->arr = malloc(sizeof(short)*max_elem_count);
    if(res->arr == NULL) {
        perror("Create queue error");
        return -1;
    }
    res->max_elem_count = max_elem_count;
    res->elem_count = 0;
    return 0;
}
int delete_queue(Queue* q) {
    free(q->arr);
}
void print_queue(Queue *q) {
    for(int i = 0; i < q->max_elem_count; i++) {
        printf("%hi ", q->arr[i]);
    }
    printf("\n");
}
int push(Queue *q, short new_elem) {
    printf("PUSH ");
    if(q->elem_count == q->max_elem_count) {
        perror("Push: queue is full\n");
        return -1;
    }
    q->arr[q->elem_count] = new_elem;
    q->elem_count++;
    print_queue(q);
    return 0;
}

// 0 - success
// -1 - error
int pop(Queue *q, short *res) {
    printf("POP  ");
    if(q->elem_count == 0) {
        perror("Pop: Queue is empty\n");
        return -1;
    }
    if(res != NULL) {
        *res = q->arr[0];
    }
    for(int i = 0; i < q->elem_count - 1; i++) {
        q->arr[i] = q->arr[i+1];
    }
    q->elem_count--;
    q->arr[q->elem_count] = 0;
    print_queue(q);
    return 0;
}

int main() {
    Queue q1;
    create_queue(16, &q1);
    push(&q1, 5);
    push(&q1, 6);
    push(&q1, 7);
    push(&q1, 8);
    pop(&q1, NULL);
    push(&q1, 1);
    pop(&q1, NULL);
    pop(&q1, NULL);
    pop(&q1, NULL);
}
