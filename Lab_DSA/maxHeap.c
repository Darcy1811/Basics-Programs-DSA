#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP_SIZE 100

struct MaxHeap {
    int arr[MAX_HEAP_SIZE];
    int size;
};

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(struct MaxHeap* heap, int index) {
    int largest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < heap->size && heap->arr[leftChild] > heap->arr[largest]) {
        largest = leftChild;
    }

    if (rightChild < heap->size && heap->arr[rightChild] > heap->arr[largest]) {
        largest = rightChild;
    }

    if (largest != index) {
        swap(&heap->arr[index], &heap->arr[largest]);
        maxHeapify(heap, largest);
    }
}

void insertMaxHeap(struct MaxHeap* heap, int value) {
    if (heap->size == MAX_HEAP_SIZE) {
        printf("Max Heap is full. Cannot insert %d.\n", value);
        return;
    }

    heap->size++;
    int index = heap->size - 1;
    heap->arr[index] = value;

    while (index != 0 && heap->arr[(index - 1) / 2] < heap->arr[index]) {
        swap(&heap->arr[index], &heap->arr[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

int extractMax(struct MaxHeap* heap) {
    if (heap->size == 0) {
        printf("Max Heap is empty. Cannot extract maximum.\n");
        return -1; // Assuming -1 as an error value
    }

    if (heap->size == 1) {
        heap->size--;
        return heap->arr[0];
    }

    int root = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;

    maxHeapify(heap, 0);

    return root;
}

void displayMaxHeap(struct MaxHeap* heap) {
    printf("Max Heap: ");
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->arr[i]);
    }
    printf("\n");
}

int main() {
    struct MaxHeap maxHeap = {{}, 0};

    insertMaxHeap(&maxHeap, 10);
    insertMaxHeap(&maxHeap, 20);
    insertMaxHeap(&maxHeap, 15);

    displayMaxHeap(&maxHeap);

    printf("Extracted Max: %d\n", extractMax(&maxHeap));

    displayMaxHeap(&maxHeap);

    return 0;
}
