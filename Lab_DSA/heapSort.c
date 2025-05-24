#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(int arr[], int size, int index) {
    int largest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < size && arr[leftChild] > arr[largest]) {
        largest = leftChild;
    }

    if (rightChild < size && arr[rightChild] > arr[largest]) {
        largest = rightChild;
    }

    if (largest != index) {
        swap(&arr[index], &arr[largest]);
       
