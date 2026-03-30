#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;   // coefficient
    int pow;     // power
    struct Node* next;
};

// Function to create a new node
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

// Add two polynomials
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->pow > poly2->pow) {
            insertTerm(&result, poly1->coeff, poly1->pow);
            poly1 = poly1->next;
        } else if (poly1->pow < poly2->pow) {
            insertTerm(&result, poly2->coeff, poly2->pow);
            poly2 = poly2->next;
        } else {
            insertTerm(&result, poly1->coeff + poly2->coeff, poly1->pow);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    while (poly1 != NULL) {
        insertTerm(&result, poly1->coeff, poly1->pow);
        poly1 = poly1->next;
    }
    while (poly2 != NULL) {
        insertTerm(&result, poly2->coeff, poly2->pow);
        poly2 = poly2->next;
    }
    return result;
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* sum = NULL;

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

    sum = addPolynomials(poly1, poly2);
    printf("Sum: ");
    display(sum);

    return 0;
}