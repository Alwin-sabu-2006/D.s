#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coeff;
    int exp;
    struct Node* next;
} Node;


Node* createNode(int coeff, int exp) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->coeff = coeff;
    node->exp = exp;
    node->next = NULL;
    return node;
}


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


void printPoly(Node* poly) {
    while (poly) {
        printf("%dx^%d", poly->coeff, poly->exp);
        poly = poly->next;
        if (poly) printf(" + ");
    }
    printf("\n");
}


Node* createPoly(int coeffs[], int exps[], int n) {
    Node* poly = NULL;
    Node** lastPtr = &poly;
    for (int i = 0; i < n; i++) {
        *lastPtr = createNode(coeffs[i], exps[i]);
        lastPtr = &((*lastPtr)->next);
    }
    return poly;
}

int main() {
    int coeffs1[] = {5, 4, 2};
    int exps1[] = {3, 1, 0};
    Node* poly1 = createPoly(coeffs1, exps1, 3);

    int coeffs2[] = {3, 2, 1};
    int exps2[] = {3, 2, 0};
    Node* poly2 = createPoly(coeffs2, exps2, 3);

    printf("Polynomial 1: ");
    printPoly(poly1);

    printf("Polynomial 2: ");
    printPoly(poly2);

    Node* sum = addPoly(poly1, poly2);

    printf("Sum: ");
    printPoly(sum);

    return 0;
}
