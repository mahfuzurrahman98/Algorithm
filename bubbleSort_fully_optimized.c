#include <stdio.h>

void Swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

void bubbleSort(int *a, int n) {
  int isSorted;
  for (int i = 0; i < n; i++) {
    isSorted = 1; //assume it is sorted
    for (int j = 0; j < n - i - 1; j++) {
      if (a[j] > a[j + 1]) {
        Swap(&a[j], &a[j + 1]);
        isSorted = 0; //if swaps then, not sorted yet. set it to 0
      }
    }
    if (isSorted) {
      printf("Sorted in %dth pass\n", i);
      break;
    }
  }
}

void printArray(int *a, int n) {
  printf("Array: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
}

int main() {
  //	int arr[] = {58, 36, 12, 47, 98, 53, 9};
  int arr[] = {5, 8, 39, 19};
  int n = sizeof(arr) / sizeof(arr[0]);
  bubbleSort(arr, n);
  printArray(arr, n);
}