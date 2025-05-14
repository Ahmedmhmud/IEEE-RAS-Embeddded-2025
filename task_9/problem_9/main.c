#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node *next;
} Node;

Node* enqueue(Node *rear, char data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (rear != NULL)
        rear->next = newNode;

    return newNode;
}

Node* dequeue(Node *front) {
    if (front == NULL) {
        printf("Queue is empty!\n");
        return NULL;
    }

    printf("Dequeued value: %c\n", front->data);

    Node *temp = front;
    front = front->next;
    free(temp);

    return front;
}

void printQueue(Node *front) {
    while (front != NULL) {
        printf("%c\n", front->data);
        front = front->next;
    }
}

int main() {
    Node *front = NULL;
    Node *rear = NULL;
    front = rear = enqueue(NULL, 'A');
    rear = enqueue(rear, 'B');
    rear = enqueue(rear, 'C');
    printQueue(front);
    front = dequeue(front);
    printQueue(front);
    while (front != NULL) {
        front = dequeue(front);
    }

    return 0;
}
