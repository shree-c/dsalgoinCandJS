#include "utility.h"
void bubblesort(int *arr, int lo, int hi) {
	for (int i = lo; i <= hi; i++) {
		for (int j = lo; j < (hi - i); j++) {
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
			}
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
	bubblesort(arr, 0, MAX - 1);
	printarray(arr, MAX);
}

