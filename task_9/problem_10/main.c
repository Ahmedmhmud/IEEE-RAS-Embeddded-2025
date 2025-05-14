#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

typedef struct {
    int front;
    int rear;
    char arr[SIZE];
} Queue;

void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue *q) {
    return (q->front == -1);
}

int isFull(Queue *q) {
    return (q->rear == SIZE - 1);
}

void enqueue(Queue *q, char value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }

    if (isEmpty(q))
        q->front = 0;

    q->rear++;
    q->arr[q->rear] = value;
}

void dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Dequeued value: %c\n", q->arr[q->front]);

    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
}

char getFront(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return '-';
    }
    return q->arr[q->front];
}

char getRear(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return '-';
    }
    return q->arr[q->rear];
}

void printQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue (front to rear): ");
    for (int i = q->front; i <= q->rear; i++)
        printf("%c ", q->arr[i]);
    printf("\n");
}

int main() {
    Queue q;
    initQueue(&q);
    enqueue(&q, 'A');
    enqueue(&q, 'B');
    enqueue(&q, 'C');
    printQueue(&q);
    printf("Front: %c\n", getFront(&q));
    printf("Rear: %c\n", getRear(&q));
    dequeue(&q);
    printQueue(&q);
    printf("Front: %c\n", getFront(&q));
    printf("Rear: %c\n", getRear(&q));
    return 0;
}
