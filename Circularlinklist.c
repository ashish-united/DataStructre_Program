#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* last = NULL;

void insertEnd(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    if (last == NULL) {
        last = newNode;
        last->next = last;
    } else {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
}

void insertFront(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    if (last == NULL) {
        last = newNode;
        last->next = last;
    } else {
        newNode->next = last->next;
        last->next = newNode;
    }
}

void deleteNode(int key) {
    if (last == NULL) return;
    struct Node* temp = last->next, *prev = last;
    do {
        if (temp->data == key) {
            if (temp == last && temp->next == last) {
                last = NULL;
            } else {
                prev->next = temp->next;
                if (temp == last) last = prev;
            }
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    } while (temp != last->next);
}

void display() {
    if (last == NULL) {
        printf("List Empty\n");
        return;
    }
    struct Node* temp = last->next;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("(back to head)\n");
}

int main() {
    insertEnd(10);
    insertEnd(20);
    insertFront(5);
    display();
    deleteNode(20);
    display();
    return 0;
}