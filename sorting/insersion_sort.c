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
