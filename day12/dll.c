#include<stdio.h>
#include<stdlib.h>

typedef struct Point {
    double x, y;
} Point;

typedef struct Node {
    Point data;
    struct Node *next, *prev;
} Node;


void push_front(Point data, Node **head, Node **tail) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->data = data;
    if (*head == NULL && *tail == NULL)
    {
        // DLL is empty
        *head = newNode;
        *tail = newNode;
    } else {
        // DLL is not empty
        (*head)->prev = newNode;
        newNode->next = *head;
        *head = newNode;
    }
}
void pop_back(Node** head, Node **tail) {
    Node *deletedAddr = *tail;
    if(*tail == NULL && *head == NULL) {
        perror("POP_BACK: DLL is empty");
        exit(-1);
    }
    if((*tail)->prev != NULL) {
        *tail = (*tail)->prev;
        (*tail)->next = NULL;
    } else {
        *tail = NULL;
        *head = NULL;
    }
    free(deletedAddr);

}
void print_dll(Node *head, Node* tail) {
    for(Node *curNode = head; curNode != NULL;curNode=curNode->next) {
        printf("P: %f %f PREV: %p  CUR: %p  NEXT: %p\n", 
        curNode->data.x, curNode->data.y, curNode->prev, curNode, curNode->next);
    }
    printf("\n");
}

int main() {
    printf("%lu %lu\n", sizeof(Point), sizeof(Node));
    Node *head1 = NULL, *tail1 = NULL;
    Point p1 = {1., 2.},p2 = {1., 5.},p3 = {16., 20.},p4 = {100., 100.};
    p1.x = 500.;
    push_front(p1, &head1, &tail1);
    push_front(p2, &head1, &tail1);
    push_front(p3, &head1, &tail1);
    push_front(p4, &head1, &tail1);
    print_dll(head1, tail1);
    pop_back(&head1, &tail1);
    print_dll(head1, tail1);
    return 0;
}