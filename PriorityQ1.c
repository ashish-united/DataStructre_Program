#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int priority;
    struct Node* next;
};
struct Node* front = NULL;

void enqueue(int d, int p) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = d;
    newNode->priority = p;
    newNode->next = NULL;

    if (front == NULL || p > front->priority) {
        newNode->next = front;
        front = newNode;
    } else {
        struct Node* temp = front;
        while (temp->next != NULL && temp->next->priority >= p) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    printf("%d enqueued with priority %d\n", d, p);
}

void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow\n");
        return;
    }
    printf("Dequeued: %d (priority %d)\n", front->data, front->priority);
    struct Node* temp = front;
    front = front->next;
    free(temp);
}

void display() {
    struct Node* temp = front;
    while (temp != NULL) {
        printf("%d(p=%d) -> ", temp->data, temp->priority);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    enqueue(10, 2);
    enqueue(20, 5);
    enqueue(30, 1);
    display();
    dequeue();
    display();
    return 0;
}