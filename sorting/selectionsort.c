#include "utility.h"

void selectionsort(int *arr, int lo, int hi) {
	for (int i = lo; i < hi; i++) {
		int minindex = i;
		for (int j = i + 1; j <= hi; j++) {
			if (arr[j] < arr[minindex]) {
				minindex = j;
			}
		}
		swap(&arr[i], &arr[minindex]);
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
	selectionsort(arr, 0, MAX - 1);
	printarray(arr, MAX);
}
