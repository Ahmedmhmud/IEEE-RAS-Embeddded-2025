#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
} Node;

Node* createNode(int data){
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
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


int main(void){
    Node *head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    print(head);
}
