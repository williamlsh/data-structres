// Bubble sort in C

#include <stdio.h>

// Perform the bubble sort.
void bubbleSort(int array[], int size) {
  // loop to access each array element
  for (int step = 0; step < size - 1; ++step) {
    // check if swapping occurs
    int swapped = 0;
    // loop to compare array elements
    for (int i = 0; i < size - step - 1; ++i) {
      // compare two array elements
      // change > to < to sort in descending order
      if (array[i] > array[i + 1]) {
        // swapping occurs if elements
        // are not in the intended order
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;

        swapped = 1;
      }
    }
    // no swapping means the array is already sorted
    // so no need for further comparison
    if (swapped == 0) {
      break;
    }
  }
}

void display(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

int main() {
  int data[] = {-2, 45, 0, 11, -9};

  int size = sizeof(data) / sizeof(data[0]);
  bubbleSort(data, size);
  display(data, size);
}
