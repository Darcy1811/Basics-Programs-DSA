#include <stdio.h>
#include <stdlib.h>

int orderedSequentialSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == key) {
            return i; // Record found
        } else if (arr[i] > key) {
            return -1; // Record not present
        }
    }
    return -1; // Record not present
}

int unorderedSequentialSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == key) {
            return i; // Record found
        }
    }
    return -1; // Record not present
}

int main() {
    int n;
    printf("Enter the size of the table: ");
    scanf("%d", &n);

    int* orderedTable = (int*)malloc(n * sizeof(int));
    int* unorderedTable = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i) {
        orderedTable[i] = i * 2; // Assuming ordered values
        unorderedTable[i] = rand() % (n * 2); // Random unordered values
    }

    int mykey;
    printf("Enter the key to search: ");
    scanf("%d", &mykey);

    int result = orderedSequentialSearch(orderedTable, n, mykey);
    printf("Ordered Table - No record with key %d: %s\n", mykey, (result == -1) ? "Not found" : "Found");

    result = unorderedSequentialSearch(unorderedTable, n, mykey);
    printf("Unordered Table - No record with key %d: %s\n", mykey, (result == -1) ? "Not found" : "Found");

    result = orderedSequentialSearch(orderedTable, n, orderedTable[n / 2]);
    printf("Ordered Table - One record with key %d: %s\n", orderedTable[n / 2], (result == -1) ? "Not found" : "Found");

    result = unorderedSequentialSearch(unorderedTable, n, unorderedTable[n / 2]);
    printf("Unordered Table - One record with key %d: %s\n", unorderedTable[n / 2], (result == -1) ? "Not found" : "Found");

    result = orderedSequentialSearch(orderedTable, n, mykey);
    printf("Ordered Table - First record with key %d: %s\n", mykey, (result == -1) ? "Not found" : "Found");

    result = unorderedSequentialSearch(unorderedTable, n, mykey);
    printf("Unordered Table - First record with key %d: %s\n", mykey, (result == -1) ? "Not found" : "Found");

    printf("Records with key %d in Ordered Table: ", mykey);
    for (int i = 0; i < n; ++i) {
        if (orderedTable[i] == mykey) {
            printf("%d ", i);
        }
    }
    printf("\n");

    printf("Records with key %d in Unordered Table: ", mykey);
    for (int i = 0; i < n; ++i) {
        if (unorderedTable[i] == mykey) {
            printf("%d ", i);
        }
    }
    printf("\n");

    free(orderedTable);
    free(unorderedTable);

    return 0;
}
