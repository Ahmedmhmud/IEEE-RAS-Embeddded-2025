#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* createNode(int data) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

Node* insert(Node *head, int pos, int data) {
    Node *newNode = createNode(data);

    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    if (pos == 0) {
        Node *last = head;
        while (last->next != head)
            last = last->next;

        newNode->next = head;
        last->next = newNode;
        return newNode;
    }

    Node *current = head;
    for (int i = 0; i < pos - 1; i++) {
        current = current->next;
        if (current == head) {
            printf("Position out of bounds!\n");
            free(newNode);
            return head;
        }
    }

    newNode->next = current->next;
    current->next = newNode;

    return head;
}

void printList(Node *head) {
    if (head == NULL) return;

    Node *current = head;
    do {
        printf("%d\n", current->data);
        current = current->next;
    } while (current != head);

}

int main() {
    Node *head = NULL;

    head = insert(head, 0, 3);
    head = insert(head, 0, 2);
    head = insert(head, 0, 1);
    head = insert(head, 2, 99);

    printList(head);

    return 0;
}
