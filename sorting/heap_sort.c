#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100000

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void max_heapify(int *arr, int index, int max_size) {
    int left = 2 * index;
    int right = 2 * index + 1;
    int largest_index = index;
    if (left < max_size && arr[left] > arr[largest_index]) {
        largest_index = left;
    }
    if (right < max_size && arr[right] > arr[largest_index]) {
        largest_index = right;
    }
    if (largest_index != index) {
        swap(&arr[index], &arr[largest_index]);
        max_heapify(arr, largest_index, max_size);
    }
}

void build_maxheap(int *arr, int max_size) {
    for (int i = ((max_size - 1) / 2) - 1; i >= 0; i--) {
        max_heapify(arr, i, max_size);
    }
}
void heap_sort(int *arr, int max_size) {
    for (int i = 0; i < max_size; i++) {
        build_maxheap(arr, max_size - i);
        swap(&arr[0], &arr[max_size - 1 - i]);
    }
}
int main() {
    int arr[MAX];
    srand(time(NULL));
    for (int i = 0; i < MAX; i++) {
        arr[i] = (rand() % MAX) + 1;
    }
    for (int i = 0; i < MAX; i++) {
        printf("%d ", arr[i]);
    }
    heap_sort(arr, MAX);
    putchar('\n');
    for (int i = 0; i < MAX; i++) {
        printf("%d ", arr[i]);
    }
    putchar('\n');
}
