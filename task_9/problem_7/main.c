#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* push(Node *top, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = top;
    return newNode;
}

Node* pop(Node *top) {
    if (top == NULL) {
        printf("Stack is empty!\n");
        return NULL;
    }

    printf("Popped value: %d\n", top->data);

    Node *temp = top;
    top = top->next;
    free(temp);

    return top;
}

void printStack(Node *top) {
    while (top != NULL) {
        printf("%d\n", top->data);
        top = top->next;
    }
}

int main() {
    Node *top = NULL;
    top = push(top, 10);
    top = push(top, 20);
    top = push(top, 30);
    printStack(top);
    top = pop(top);
    printStack(top);
    while (top != NULL) {
        top = pop(top);
    }

    return 0;
}
