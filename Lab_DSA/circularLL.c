#include <stdio.h>
#include <stdlib.h>

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

struct Node* insertAtBeginning(struct Node* head, int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    } else {
        newNode->next = head->next;
        head->next = newNode;
        return head;
    }
}

struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    } else {
        newNode->next = head->next;
        head->next = newNode;
        return newNode;
    }
}

struct Node* deleteNode(struct Node* head, int value) {
    if (head == NULL) {
        printf("List is empty. Deletion failed.\n");
        return NULL;
    }

    struct Node* current = head;
    struct Node* prev = NULL;

    while (current->data != value && current->next != head) {
        prev = current;
        current = current->next;
    }

    if (current->data == value) {
        
        if (current->next == head) {
            free(current);
            return NULL;
        }

        
        if (current == head) {
            prev = head;
            while (prev->next != head) {
                prev = prev->next;
            }
            head = head->next;
            prev->next = head;
            free(current);
        } else {
            prev->next = current->next;
            free(current);
        }

        printf("deleted successfully.\n", value);
        return head;
    } else {
        printf("Deletion failed.\n", value);
        return head;
    }
}

void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        struct Node* current = head;
        do {
            printf("%d -> ", current->data);
            current = current->next;
        } while (current != head);
        printf("(head)\n");
    }
}


void freeList(struct Node* head) {
    if (head == NULL) {
        return;
    }

    struct Node* current = head;
    struct Node* temp;

    do {
        temp = current;
        current = current->next;
        free(temp);
    } while (current != head);
}

int main() {
    struct Node* head = NULL;

   
    head = insertAtBeginning(head, 30);
    head = insertAtBeginning(head, 20);
    head = insertAtBeginning(head, 10);

    printf("Circular Linked List after insertion at the beginning:\n");
    displayList(head);

   
    head = insertAtEnd(head, 40);
    head = insertAtEnd(head, 50);

    printf("Circular Linked List after insertion at the end:\n");
    displayList(head);

    
    head = deleteNode(head, 20);

    printf("Circular Linked List after deletion:\n");
    displayList(head);

    freeList(head);

    return 0;
}
