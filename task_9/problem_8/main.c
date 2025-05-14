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

void printStack(Node *top) {
    printf("Stack (top to bottom): ");
    while (top != NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}

void swapTopTwo(Node *top) {
    if (top == NULL || top->next == NULL) {
        printf("Not enough elements to swap!\n");
        return;
    }
    int temp = top->data;
    top->data = top->next->data;
    top->next->data = temp;
}

int main() {
    Node *top = NULL;
    top = push(top, 10);
    top = push(top, 20);
    top = push(top, 30);
    printf("Before swap:\n");
    printStack(top);
    swapTopTwo(top);
    printf("After swap:\n");
    printStack(top);
    while (top != NULL) {
        Node *temp = top;
        top = top->next;
        free(temp);
    }
    return 0;
}
