#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Queue {
    struct Node* front;
    struct Node* rear;
};

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

struct Queue* initializeQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    if (queue == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }
    queue->front = queue->rear = NULL;
    return queue;
}


int isEmpty(struct Queue* queue) {
    return queue->front == NULL;
}


void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = createNode(data);
    
    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeue(struct Queue* queue) {
    int data = -1;
    if (isEmpty(queue)) {
        printf("Queue underflow\n");
        exit(EXIT_FAILURE);
    } else {
        struct Node* temp = queue->front;
        data = temp->data;
        queue->front = temp->next;

        if (queue->front == NULL) {
            queue->rear = NULL;
        }

        free(temp);
    }
    return data;
}

void freeQueue(struct Queue* queue) {
    while (queue->front != NULL) {
        struct Node* temp = queue->front;
        queue->front = queue->front->next;
        free(temp);
    }
    free(queue);
}

int main() {
    struct Queue* queue = initializeQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    while (!isEmpty(queue)) {
        printf("%d ", dequeue(queue));
    }

    freeQueue(queue);

    return 0;
}
