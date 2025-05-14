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

Node* createNodeBeginning(int data, Node *head) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = head;
    return node;
}

 Node* createNodeEnd(Node *head, int data) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;

    if (head == NULL) {
        return node;
    }

    Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = node;
    return head;
}

Node* deleteNode(Node *head, int value){
    if (head == NULL) return NULL;

    Node *current = head;
    Node *prev = NULL;

    while (current != NULL) {
        if (current->data == value) {
            if (prev == NULL) {
                Node *temp = head;
                head = head->next;
                free(temp);
                return head;
            } else {
                prev->next = current->next;
                free(current);
                return head;
            }
        }
        prev = current;
        current = current->next;
    }

    printf("Value %d not found.\n", value);
    return head;
}

void print(Node *head) {
    int counter = 0;
    while (head != NULL) {
        printf("%d\n", head->data);
        counter++;
        head = head->next;
    }
    printf("No. of elements in linked list: %d\n", counter);
}

int main(void) {
    Node *head = NULL;

    head = createNode(1);
    head = createNodeEnd(head, 2);
    head = createNodeEnd(head, 3);
    head = createNodeBeginning(0, head);

    print(head);

    head = deleteNode(head, 2);
    print(head);

    while (head != NULL) {
        Node *temp = head;
        head = head->next;
        free(temp);
    }
}
