#include <stdio.h>
#include <stdlib.h>

#define MIN_HEAP_SIZE 100

struct MinHeap {
    int arr[MIN_HEAP_SIZE];
    int size;
};

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(struct MinHeap* heap, int index) {
    int smallest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < heap->size && heap->arr[leftChild] < heap->arr[smallest]) {
        smallest = leftChild;
    }

    if (rightChild < heap->size && heap->arr[rightChild] < heap->arr[smallest]) {
        smallest = rightChild;
    }

    if (smallest != index) {
        swap(&heap->arr[index], &heap->arr[smallest]);
        minHeapify(heap, smallest);
    }
}

void insertMinHeap(struct MinHeap* heap, int value) {
    if (heap->size == MIN_HEAP_SIZE) {
        printf("Min Heap is full. Cannot insert %d.\n", value);
        return;
    }

    heap->size++;
    int index = heap->size - 1;
    heap->arr[index] = value;

    while (index != 0 && heap->arr[(index - 1) / 2] > heap->arr[index]) {
        swap(&heap->arr[index], &heap->arr[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

int extractMin(struct MinHeap* heap) {
    if (heap->size == 0) {
        printf("Min Heap is empty. Cannot extract minimum.\n");
        return -1; // Assuming -1 as an error value
    }

    if (heap->size == 1) {
        heap->size--;
        return heap->arr[0];
    }

    int root = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;

    minHeapify(heap, 0);

    return root;
}

void displayMinHeap(struct MinHeap* heap) {
    printf("Min Heap: ");
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->arr[i]);
    }
    printf("\n");
}

int main() {
    struct MinHeap minHeap = {{}, 0};

    insertMinHeap(&minHeap, 10);
    insertMinHeap(&minHeap, 20);
    insertMinHeap(&minHeap, 15);

    displayMinHeap(&minHeap);

    printf("Extracted Min: %d\n", extractMin(&minHeap));

    displayMinHeap(&minHeap);

    return 0;
}
