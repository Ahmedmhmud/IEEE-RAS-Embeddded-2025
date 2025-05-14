#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

Node* insertAtBeginning(Node *head, int data) {
    Node *newNode = createNode(data);

    if (head != NULL) {
        newNode->next = head;
        head->prev = newNode;
    }

    return newNode;
}

void printList(Node *head) {
    while (head != NULL) {
        printf("%d\n", head->data);
        head = head->next;
    }
}

int main(void) {
    Node *head = NULL;
    head = insertAtBeginning(head, 3);
    head = insertAtBeginning(head, 2);
    head = insertAtBeginning(head, 1);
    printList(head);
    while (head != NULL) {
        Node *temp = head;
        head = head->next;
        free(temp);
    }
}
