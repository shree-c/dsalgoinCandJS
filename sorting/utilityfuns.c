#include <stdio.h>
void printarray(int *arr, int max) {
	printf("printing array: [ ");
	for (int i = 0; i < max; i++) {
		printf("%d ", arr[i]);
	}
	printf(" ]\n\n");
}
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
