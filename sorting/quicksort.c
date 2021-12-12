#include "utility.h"

int partition(int *arr, int lo, int hi) {
	int i = lo - 1;
	int pivot = arr[hi];
	for (int j = lo; j < hi; j++) {
		if (arr[j] <= pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	i++;
	swap(&arr[i], &arr[hi]);
	return i;
}

void quicksort(int *arr, int lo, int hi) {
	if (lo < hi) {
		int pivot = partition(arr, lo, hi);
		quicksort(arr, lo, pivot - 1);
		quicksort(arr, pivot + 1, hi);
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
	quicksort(arr, 0, MAX - 1);
	printarray(arr, MAX);
}

