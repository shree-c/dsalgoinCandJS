#include "utility.h"
int spseq[8] = {701, 301, 132, 57, 23, 10, 4, 1};
void shellsort(int *arr, int lo, int hi) {
	//for getting gaps
	for (int x = 0; x <  8; x++) {
		//takes up element group for a gap
		for (int offset = lo; offset < spseq[x]; offset++) {
			//for jumping between element groups
			for (int i = offset + spseq[x]; i <= hi; i+= spseq[x]) {
				int j = i - spseq[x];
				int temp = arr[i];
				for (; j >= lo && arr[j] > temp; j -= spseq[x]) {
					arr[j + spseq[x]] = arr[j];
				}
				arr[j + spseq[x]] = temp;
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
	shellsort(arr, 0, MAX - 1);
	printarray(arr, MAX);
}

