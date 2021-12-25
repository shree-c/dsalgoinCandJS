#include "utility.h"
void bubblesort(int *arr, int lo, int hi) {
	int c = 0;
	int s = 0;
	for (int i = lo; i < hi; i++) {
		for (int j = lo; j < (hi - i); j++) {
			c++;
			if (arr[j] > arr[j + 1]) {
				s++;
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
	printf("%d comparisons, %d swaps\n", c, s);
}

void nbubble(int *arr, int lo, int hi) {
	int swapped = 0;
	do {
		swapped = 0;
		for (int i = lo; i < hi; i++) {
			if (arr[i] > arr[i + 1]) {
				swap(&arr[i], &arr[i + 1]);
				swapped = 1;
			}
		}
		hi--;
	} while (swapped);
}
int main() {
	srand(time(0));
	int upper = 100, lower = 0;
	int arr[MAX];
	for (int i = 0; i < MAX; i++) {
		arr[i] = (rand() % (upper - lower + 1)) + lower;
	}
	printarray(arr, MAX);
	nbubble(arr, 0, MAX-1);
	printarray(arr, MAX);
}

