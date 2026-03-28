#include <stdio.h>
#define N 5

void traverse(int *A);

int main() {
    int A[N] = {10, 20, 30, 40, 50};
    traverse(A);
    return 0;
}

void traverse(int *A) {
    int START = 0;
    while (START < N) {
        printf("%d\n", A[START]);
        START = START + 1;
    }
}