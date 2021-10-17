#include <stdio.h>

void Swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

void selectionSort(int *a, int n) {
  int minIndex;
  for (int i = 0; i < n; i++) { //Total n passes
    //For every pass
    minIndex = i;                     //set the current index to minIndex(current value is min value)
    for (int j = i + 1; j < n; j++) { //find the next minimum number for ith index
      if (a[j] < a[minIndex]) {       //if any idex j holds smaller value than current minimum
        minIndex = j;                 //update that to minimum
      }
    }
    Swap(&a[i], &a[minIndex]); //swap the minimum value with our current i index value
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
  int arr[] = {58, 36, 12, 47, 98, 53, 9, 41};
  int n = sizeof(arr) / sizeof(arr[0]);
  selectionSort(arr, n);
  printArray(arr, n);
}