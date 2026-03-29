#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* top = NULL;

void push(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = top;
    top = newNode;
    printf("%d pushed\n", x);
}

void pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }
    printf("%d popped\n", top->data);
    struct Node* temp = top;
    top = top->next;
    free(temp);
}

void peek() {
    if (top == NULL) printf("Stack Empty\n");
    else printf("Top element: %d\n", top->data);
}

int main() {
    push(10);
    push(20);
    push(30);
    peek();
    pop();
    peek();
    return 0;
}