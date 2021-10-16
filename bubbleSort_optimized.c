#include <stdio.h>

void Swap(int *x, int *y) { //call by reference
  int temp = *x;
  *x = *y;
  *y = temp;
}

void bubbleSort(int *a, int n) { //array is kind of a pointer, so we can call it as *a
  for (int i = 0; i < n; i++) {  //Total n-1 passes
    //After every ith passes the last i's indexes sort with proper number,
    //So skip checking last i's indexes, check remaining n-i indexes
    for (int j = 0; j < n - i - 1; j++) {
      if (a[j] > a[j + 1]) {
        Swap(&a[j], &a[j + 1]);
      }
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
  int arr[] = {58, 36, 12, 47, 98, 53, 9};
  int n = sizeof(arr) / sizeof(arr[0]);
  bubbleSort(arr, n);
  printArray(arr, n);
}