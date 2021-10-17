#include <stdio.h>

void bubbleSort(int a[], int n) {
  int temp;
  for (int i = 0; i < n; i++) { //Total n-1 passes
    //For every passes
    for (int j = 0; j < n - 1; j++) {
      if (a[j] > a[j + 1]) { //check wethar a number is greater than it's next adjacent
        //then swap
        temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
      }
    }
  }
}

void printArray(int a[], int n) {
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