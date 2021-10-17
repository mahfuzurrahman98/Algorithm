#include <stdio.h>

void Swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

int partition(int a[], int low, int high) {

  int pivot = a[low];
  int i = low;
  int j = high;

  while (i < j) {
    while (a[i] <= pivot) {
      i++;
    }
    while (a[j] > pivot) {
      j--;
    }
    if (i < j) {
      Swap(&a[i], &a[j]);
    }
  }
  Swap(&a[low], &a[j]);
  return j;
}

void quickSort(int a[], int low, int high) {

  int partitionIndex; // Index of pivot after partition

  if (low < high) {
    partitionIndex = partition(a, low, high);
    quickSort(a, low, partitionIndex - 1);  // sort left subarray
    quickSort(a, partitionIndex + 1, high); // sort right subarray
  }
}

int main() {

  int a[] = {34, 9, 12, 2, 91, 14};
  int n = sizeof(a) / sizeof(a[0]);
  quickSort(a, 0, n - 1);

  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
}