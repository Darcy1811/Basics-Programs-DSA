#include <stdio.h>
#include <stdlib.h>

// Node structure to represent elements in the stack
struct Node {
    int data;
    struct Node* next;
};

// Stack structure
struct Stack {
    struct Node* top;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize an empty stack
struct Stack* initializeStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    if (stack == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }
    stack->top = NULL;
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }

    struct Node* temp = stack->top;
    int poppedValue = temp->data;
    stack->top = temp->next;
    free(temp);
    return poppedValue;
}

// Function to free the memory allocated for the stack
void freeStack(struct Stack* stack) {
    while (stack->top != NULL) {
        struct Node* temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
    }
    free(stack);
}

int main() {
    struct Stack* stack = initializeStack();

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    while (!isEmpty(stack)) {
        printf("%d ", pop(stack));
    }

    freeStack(stack);

    return 0;
}
