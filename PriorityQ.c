#include <stdio.h>
#define MAX 10

struct Item {
    int data;
    int priority;
};

struct Item pq[MAX];
int size = 0;

void enqueue(int d, int p) {
    if (size == MAX) {
        printf("Queue Overflow\n");
        return;
    }
    pq[size].data = d;
    pq[size].priority = p;
    size++;
}

void dequeue() {
    if (size == 0) {
        printf("Queue Underflow\n");
        return;
    }
    int highest = 0;
    for (int i = 1; i < size; i++) {
        if (pq[i].priority > pq[highest].priority)
            highest = i;
    }
    printf("Dequeued: %d (priority %d)\n", pq[highest].data, pq[highest].priority);
    for (int i = highest; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }
    size--;
}

void display() {
    for (int i = 0; i < size; i++) {
        printf("%d(p=%d) ", pq[i].data, pq[i].priority);
    }
    printf("\n");
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