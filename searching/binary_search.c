#include <stdio.h>
#include <stdlib.h>
int bin_search_rec(long int *arr, int start, int end, int item) {
  int mid = (start + end)/2;
  if (start > end) {
    fprintf(stderr, "Unsuccessful search\n");
    exit(1);
  }
  else if (item < arr[mid])
    bin_search_rec(arr, start, mid - 1, item);
  else if (item > arr[mid])
    bin_search_rec(arr, mid + 1, end, item);
    return mid;
}

int bin_search_ite(long int *arr, int start, int end, int item) {
  while (start < end) {
    int mid = (start + end)/2;
    if (item > arr[mid])
      start = mid + 1;
    else if (item < arr[mid])
      end = mid - 1;
    else
      return mid;
  }
  fprintf(stderr, "Unsuccessful search\n");
  return 1;
}
