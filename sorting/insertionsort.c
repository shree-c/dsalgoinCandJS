#include "utility.h"

void insersion_sort(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) {
      swap(&arr[j - 1], &arr[j]);
    }
  }
}

int main() {
	srand(time(0));
	int upper = 100, lower = 0;
	int arr[MAX];
	for (int i = 0; i < MAX; i++) {
		arr[i] = (rand() % (upper - lower + 1)) + lower;
	}

	printarray(arr, MAX);
	insersion_sort(arr, MAX);
	printarray(arr, MAX);
}

