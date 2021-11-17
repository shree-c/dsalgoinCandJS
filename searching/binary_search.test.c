#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX 200
void swap(long int *a, long int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
void insersion_sort(long int *arr, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) {
      swap(&arr[j - 1], &arr[j]);
    }
  }
}
int bin_search(long int *arr, int start, int end, int item) {
  int mid = (start + end)/2;
  printf("%d -- %d --- %d\n", start, end, mid);
  getchar();
  if (start > end) {
    fprintf(stderr, "Unsuccessful search\n");
    exit(1);
  }
  else if (item < arr[mid])
    bin_search(arr, start, mid - 1, item);
  else if (item > arr[mid])
    bin_search(arr, mid + 1, end, item);
    return mid;
}

int bin_search_ite(long int *arr, int start, int end, int item);
int bin_search_rec(long int *arr, int start, int end, int item);
int main() {
  long int arr[200];
  srand(time(0));
  for (int i = 0; i < MAX; i++) {
      arr[i] = i;
  }
  insersion_sort(arr, MAX);
  for (int i = 0; i < MAX; i++) {
    if ( i == bin_search_rec(arr, 0, MAX - 1, i))
      printf("---->found!!\n");
    else
      printf("\n\n--->failed\n");
  }
  return 0;
}
