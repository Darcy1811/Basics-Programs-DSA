#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

struct Node* sequentialSearchProbability(struct Node* head, int key) {
    struct Node* current = head;
    struct Node* prev = NULL;
    struct Node* temp;

    while (current != NULL && current->data != key) {
        prev = current;
        current = current->next;
    }

    if (current != NULL) {
       
        if (prev != NULL) {
           
            prev->next = current->next;
            current->next = head;
            head = current;
        }
        return head;
    } else {
        printf("Element %d not found in the list.\n", key);
        return head;
    }
}


void displayList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}


void freeList(struct Node* head) {
    struct Node* current = head;
    struct Node* temp;
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    
    struct Node* head = NULL;
    srand(time(NULL));

    for (int i = 0; i < 10; ++i) {
        int randomValue = rand() % 10 + 1; 
        struct Node* newNode = createNode(randomValue);
        newNode->next = head;
        head = newNode;
    }

    printf("Original Linked List:\n");
    displayList(head);

   
    int searchKey;
    printf("Enter the element to search: ");
    scanf("%d", &searchKey);

    head = sequentialSearchProbability(head, searchKey);

    printf("Linked List after Sequential Search with Probability:\n");
    displayList(head);

   
    freeList(head);

    return 0;
}
