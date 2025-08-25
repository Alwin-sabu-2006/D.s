
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coeff;
    int exp;
    struct Node* next;
} Node;

// Create a new node
Node* createNode(int coeff, int exp) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->coeff = coeff;
    node->exp = exp;
    node->next = NULL;
    return node;
}

// Insert node at the end (assuming user will enter in descending order)
void appendNode(Node** poly, int coeff, int exp) {
    Node* newNode = createNode(coeff, exp);
    if (*poly == NULL) {
        *poly = newNode;
    } else {
        Node* temp = *poly;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Add two polynomials and return the sum polynomial
Node* addPoly(Node* poly1, Node* poly2) {
    Node* result = NULL;
    Node** lastPtr = &result;

    while (poly1 && poly2) {
        if (poly1->exp == poly2->exp) {
            int sum = poly1->coeff + poly2->coeff;
            if (sum != 0) {
                *lastPtr = createNode(sum, poly1->exp);
                lastPtr = &((*lastPtr)->next);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        } else if (poly1->exp > poly2->exp) {
            *lastPtr = createNode(poly1->coeff, poly1->exp);
            lastPtr = &((*lastPtr)->next);
            poly1 = poly1->next;
        } else {
            *lastPtr = createNode(poly2->coeff, poly2->exp);
            lastPtr = &((*lastPtr)->next);
            poly2 = poly2->next;
        }
    }

    while (poly1) {
        *lastPtr = createNode(poly1->coeff, poly1->exp);
        lastPtr = &((*lastPtr)->next);
        poly1 = poly1->next;
    }

    while (poly2) {
        *lastPtr = createNode(poly2->coeff, poly2->exp);
        lastPtr = &((*lastPtr)->next);
        poly2 = poly2->next;
    }

    return result;
}

// Print polynomial
void printPoly(Node* poly) {
    if (!poly) {
        printf("0\n");
        return;
    }
    while (poly) {
        printf("%dx^%d", poly->coeff, poly->exp);
        poly = poly->next;
        if (poly) printf(" + ");
    }
    printf("\n");
}

// Free polynomial linked list memory
void freePoly(Node* poly) {
    Node* temp;
    while (poly) {
        temp = poly;
        poly = poly->next;
        free(temp);
    }
}

// Read polynomial from user
Node* inputPoly() {
    int n;
    printf("Enter number of terms: ");
    scanf("%d", &n);

    Node* poly = NULL;

    printf("Enter terms in descending order of exponent:\n");
    for (int i = 0; i < n; i++) {
        int coeff, exp;
        printf("Coefficient of term %d: ", i+1);
        scanf("%d", &coeff);
        printf("Exponent of term %d: ", i+1);
        scanf("%d", &exp);
        appendNode(&poly, coeff, exp);
    }

    return poly;
}

int main() {
    printf("Enter first polynomial:\n");
    Node* poly1 = inputPoly();

    printf("\nEnter second polynomial:\n");
    Node* poly2 = inputPoly();

    printf("\nPolynomial 1: ");
    printPoly(poly1);

    printf("Polynomial 2: ");
    printPoly(poly2);

    Node* sum = addPoly(poly1, poly2);

    printf("Sum: ");
    printPoly(sum);

    // Free allocated memory
    freePoly(poly1);
    freePoly(poly2);
    freePoly(sum);

    return 0;
}
