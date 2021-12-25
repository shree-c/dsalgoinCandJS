#include "utility.h"

void selectionsort(int *arr, int lo, int hi) {
	int n = 0;
	int c = 0;
	for (int i = lo; i < hi; i++) {
		int minindex = i;
		for (int j = i + 1; j <= hi; j++) {
			c++;
			if (arr[j] < arr[minindex]) {
				minindex = j;
			}
		}
		if (minindex != i) {
			swap(&arr[i], &arr[minindex]);
			n++;
		}
	}
	printf("%d swaps, %d comparisions\n", n, c);
}
int main() {
	srand(time(0));
	int upper = 100, lower = 0;
	int arr[MAX];
	for (int i = 0; i < MAX; i++) {
		arr[i] = (rand() % (upper - lower + 1)) + lower;
	}

	printarray(arr, MAX);
	selectionsort(arr, 0, MAX - 1);
	printarray(arr, MAX);
}
