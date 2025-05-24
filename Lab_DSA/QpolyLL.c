#include <stdio.h>
#include <stdlib.h>


struct Node {
    int coefficient;
    int exponent;
    struct Node* next;
};


struct Node* createNode(int coefficient, int exponent) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;
    return newNode;
}


void insertTerm(struct Node** poly, int coefficient, int exponent) {
    struct Node* newNode = createNode(coefficient, exponent);
    if (*poly == NULL) {
        *poly = newNode;
    } else {
        struct Node* current = *poly;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;

    while (poly1 != NULL || poly2 != NULL) {
        int coef1 = (poly1 != NULL) ? poly1->coefficient : 0;
        int exp1 = (poly1 != NULL) ? poly1->exponent : 0;

        int coef2 = (poly2 != NULL) ? poly2->coefficient : 0;
        int exp2 = (poly2 != NULL) ? poly2->exponent : 0;

        int sumCoefficient = coef1 + coef2;

        insertTerm(&result, sumCoefficient, exp1);

        if (poly1 != NULL) {
            poly1 = poly1->next;
        }
        if (poly2 != NULL) {
            poly2 = poly2->next;
        }
    }

    return result;
}

void displayPolynomial(struct Node* poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coefficient, poly->exponent);
        poly = poly->next;

        if (poly != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

void freePolynomial(struct Node* poly) {
    while (poly != NULL) {
        struct Node* temp = poly;
        poly = poly->next;
        free(temp);
    }
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;

   
    insertTerm(&poly1, 3, 2);
    insertTerm(&poly1, 2, 1);
    insertTerm(&poly1, 5, 0);

    insertTerm(&poly2, 4, 3);
    insertTerm(&poly2, 1, 0);

  
    printf("First Polynomial: ");
    displayPolynomial(poly1);

   
    printf("Second Polynomial: ");
    displayPolynomial(poly2);

   
    struct Node* result = addPolynomials(poly1, poly2);

    printf("Resultant Polynomial: ");
    displayPolynomial(result);

    
    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(result);

    return 0;
}
