// Selection sort in C

#include <stdio.h>

void swap(int *a, int *b) {
  int temp = *b;
  *b = *a;
  *a = temp;
}

void selectionSort(int arr[], int size) {
  for (int step = 0; step < size - 1; step++) {
    int min_idx = step;
    for (int i = 1 + step; i < size; i++) {
      if (arr[i] < arr[min_idx]) {
        min_idx = i;
      }
    }
    // put min at the correct position
    swap(&arr[min_idx], &arr[step]);
  }
}

void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

int main() {
  int data[] = {20, 12, 10, 15, -2};
  int size = sizeof(data) / sizeof(data[0]);
  selectionSort(data, size);
  printf("Sorted array in Acsending Order:\n");
  printArray(data, size);
}
