#include "utility.h"
void merge(int *arr, int l, int m, int h) {
	//finding two temperory array sizes
	int ls = m - l + 1;
	int rs = h - m;
	//creating temp arrays
	int L[ls];
	int R[rs];
	//copying elements to subarrays
	for (int i = l, q = 0; i <= m; i++) {
		L[q++] = arr[i];
	}
	for (int i = m + 1, q = 0; i <= h; i++) {
		R[q++] = arr[i];
	}
	//merging arrays
	int v1 = 0, v2 = 0, k = l;
	//putting them back into original array by comparing elements
	while (v1 < ls && v2 < rs) {
		if (L[v1] <= R[v2]) {
			arr[k++] = L[v1++];
		} else {
			arr[k++] = R[v2++];
		}
	}
	//adding remaining elements if subarrays are of unequal size
	while (v1 < ls) {
		arr[k++] = L[v1++];
	}
	while (v2 < rs) {
		arr[k++] = R[v2++];
	}
}

void insersion_sort_opt(int *arr, int lo, int hi) {
	for (int i = lo + 1; i <= hi; i++) {
		int temp = arr[i], j = i - 1;
		for (; j >= 0 && arr[j] > temp; j--) {
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = temp;
	}
}

void msort(int *arr, int l, int h) {
	if (l < h) {
		int mid = (l + h)/2;
		printf("%d %d %d\n", l, h, h - l);
		msort(arr, l, mid);
		if (h - l < 50) {
			printf("-->%d %d %d\n", l, h, h - l);
			insersion_sort_opt(arr, l, mid);
			insersion_sort_opt(arr, mid+1, h);
			return;
		}
		msort(arr, mid+1, h);
		merge(arr, l, mid, h);
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
	msort(arr, 0, MAX - 1);
	printarray(arr, MAX);
}

