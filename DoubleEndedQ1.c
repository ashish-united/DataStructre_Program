#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};
struct Node* front = NULL;
struct Node* rear = NULL;

void insertFront(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = front;
    if (front == NULL) rear = newNode;
    else front->prev = newNode;
    front = newNode;
}

void insertRear(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = rear;
    if (rear == NULL) front = newNode;
    else rear->next = newNode;
    rear = newNode;
}

void deleteFront() {
    if (front == NULL) {
        printf("Deque Underflow\n");
        return;
    }
    printf("Deleted front: %d\n", front->data);
    struct Node* temp = front;
    front = front->next;
    if (front != NULL) front->prev = NULL;
    else rear = NULL;
    free(temp);
}

void deleteRear() {
    if (rear == NULL) {
        printf("Deque Underflow\n");
        return;
    }
    printf("Deleted rear: %d\n", rear->data);
    struct Node* temp = rear;
    rear = rear->prev;
    if (rear != NULL) rear->next = NULL;
    else front = NULL;
    free(temp);
}

void display() {
    struct Node* temp = front;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    insertRear(10);
    insertRear(20);
    insertFront(5);
    display();
    deleteFront();
    deleteRear();
    display();
    return 0;
}