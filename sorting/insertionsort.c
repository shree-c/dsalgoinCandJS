#include "utility.h"

void insersion_sort(int *arr, int size) {
  for (int i = 1; i < size; i++) {
    for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) {
      swap(&arr[j - 1], &arr[j]);
    }
  }
}

void insersion_sort_opt(int *arr, int size) {
	for (int i = 1; i < size; i++) {
		int temp = arr[i], j = i - 1;
		for (; j >= 0 && arr[j] > temp; j--) {
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = temp;
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
	insersion_sort_opt(arr, MAX);
	printarray(arr, MAX);
}

