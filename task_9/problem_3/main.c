#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

int getNodeValue(Node *head, int pos) {
    int index = 0;
    while (head != NULL) {
        if (index == pos)
            return head->data;
        head = head->next;
        index++;
    }
    printf("Position %d out of bounds!\n", pos);
    return -1;
}

Node* insertNodeAtPosition(Node *head, int pos, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (pos == 0) {
        newNode->next = head;
        return newNode;
    }

    Node *current = head;
    int index = 0;

    while (current != NULL && index < pos - 1) {
        current = current->next;
        index++;
    }

    if (current == NULL) {
        printf("Position %d out of bounds!\n", pos);
        free(newNode);
        return head;
    }

    newNode->next = current->next;
    current->next = newNode;

    return head;
}

void printList(Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main(void) {
    Node *head = (Node*)malloc(sizeof(Node));
    head->data = 1;
    head->next = (Node*)malloc(sizeof(Node));
    head->next->data = 2;
    head->next->next = (Node*)malloc(sizeof(Node));
    head->next->next->data = 3;
    head->next->next->next = NULL;
    printList(head);
    int value = getNodeValue(head, 1);
    printf("Value at position 1: %d\n", value);
    head = insertNodeAtPosition(head, 2, 99);
    printList(head);
    while (head != NULL) {
        Node *temp = head;
        head = head->next;
        free(temp);
    }
}
