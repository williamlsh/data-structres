// Queue implementation in C

#include <stdio.h>
#define SIZE 5

int items[SIZE], front = -1, rear = -1;

void enQueue(int value) {
  if (rear == SIZE - 1) {
    printf("Queue is full.");
  } else {
    if (rear == -1) {
      front++;
    }
    rear++;
    items[rear] = value;
    printf("\nInserted -> %d", value);
  }
  printf("\n");
}

void deQueue() {
  if (front == -1) {
    printf("Queue is empty.");
  } else {
    printf("\nDeleted : %d", items[front]);
    front++;
    if (front > rear) {
      front = rear = -1;
    }
  }
  printf("\n");
}

void display() {
  if (rear == -1) {
    printf("Queue is empty.");
  } else {
    for (int i = 0; i <= rear; i++) {
      printf("%d ", items[i]);
    }
  }
  printf("\n");
}

int main() {
  // deQueue is not possible on empty queue
  deQueue();

  // enQueue 5 elements
  enQueue(1);
  enQueue(2);
  enQueue(3);
  enQueue(4);
  enQueue(5);

  // 6th element can't be added to because the queue is full
  enQueue(6);

  display();

  // deQueue removes element entered first i.e. 1
  deQueue();

  // Now we have just 4 elements
  display();

  return 0;
}
