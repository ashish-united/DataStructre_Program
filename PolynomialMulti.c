#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;   // coefficient
    int pow;     // power
    struct Node* next;
};

// Create a new node
struct Node* createNode(int coeff, int pow) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = NULL;
    return newNode;
}

// Insert term into polynomial
void insertTerm(struct Node** poly, int coeff, int pow) {
    struct Node* newNode = createNode(coeff, pow);
    if (*poly == NULL) {
        *poly = newNode;
    } else {
        struct Node* temp = *poly;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Display polynomial
void display(struct Node* poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->pow);
        if (poly->next != NULL)
            printf(" + ");
        poly = poly->next;
    }
    printf("\n");
}

// Multiply two polynomials
struct Node* multiplyPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;

    for (struct Node* p1 = poly1; p1 != NULL; p1 = p1->next) {
        for (struct Node* p2 = poly2; p2 != NULL; p2 = p2->next) {
            insertTerm(&result, p1->coeff * p2->coeff, p1->pow + p2->pow);
        }
    }

    // Combine like terms (same powers)
    struct Node* ptr1 = result;
    while (ptr1 != NULL) {
        struct Node* ptr2 = ptr1->next;
        struct Node* prev = ptr1;
        while (ptr2 != NULL) {
            if (ptr1->pow == ptr2->pow) {
                ptr1->coeff += ptr2->coeff;
                prev->next = ptr2->next;
                free(ptr2);
                ptr2 = prev->next;
            } else {
                prev = ptr2;
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
    }

    return result;
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* product = NULL;

    int n1, n2, coeff, pow;

    // Input polynomial 1
    printf("Enter number of terms in Polynomial 1: ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        printf("Enter coefficient and power: ");
        scanf("%d %d", &coeff, &pow);
        insertTerm(&poly1, coeff, pow);
    }

    // Input polynomial 2
    printf("Enter number of terms in Polynomial 2: ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        printf("Enter coefficient and power: ");
        scanf("%d %d", &coeff, &pow);
        insertTerm(&poly2, coeff, pow);
    }

    printf("\nPolynomial 1: ");
    display(poly1);

    printf("Polynomial 2: ");
    display(poly2);

    product = multiplyPolynomials(poly1, poly2);
    printf("Product: ");
    display(product);

    return 0;
}