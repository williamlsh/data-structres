// Deque implementation in C
// Implementation reference:
// https://www.geeksforgeeks.org/implementation-deque-using-circular-array/

#include <stdio.h>

#define SIZE 10

// Create an empty array ‘arr’ of size N.
// initialize front = -1 , rear = 0
int items[SIZE], front = -1, rear = 0;

// Checks whether Deque is full or not.
int isFull() {
  return ((front == 0 && rear == SIZE - 1) || (rear + 1 == front));
}

// Checks whether Deque is empty or not.
int isEmpty() { return front == -1; }

void insertFront(int key) {
  if (isFull()) {
    printf("Overflow");
    return;
  }

  if (front == -1) {
    // If queue is initially empty
    front = rear = 0;
  } else if (front == 0) {
    // front is at first position of queue
    front = SIZE - 1;
  } else {
    // decrement front end by '1'
    front--;
  }
  // insert current element into Deque
  items[front] = key;
}

void insertRear(int key) {
  if (isFull()) {
    printf("Overflow");
    return;
  }

  if (front == -1) {
    front = rear = 0;
  } else if (rear == SIZE - 1) {
    rear = 0;
  } else {
    rear++;
  }
  items[rear] = key;
}

void deleteFront() {
  if (isEmpty()) {
    printf("Underflow");
    return;
  }

  printf("Delete item from front: %d\n", items[front]);
  if (front == rear) {
    // Deque has only one element
    front = rear = -1;
  } else if (front == SIZE - 1) {
    // back to initial position
    front = 0;
  } else {
    // increment front by '1' to remove current front value from Deque
    front++;
  }
}

void deleteRear() {
  if (isEmpty()) {
    printf("Underflow");
    return;
  }

  printf("Delete item from rear: %d\n", items[rear]);
  if (front == rear) {
    front = rear = -1;
  } else if (rear == 0) {
    rear = SIZE - 1;
  } else {
    rear--;
  }
}

int getFront() {
  if (isEmpty()) {
    printf("Underflow");
    return -1;
  }
  return items[front];
}

void display() {
  if (isEmpty()) {
    return;
  }
  for (int i = 0; i < SIZE; i++) {
    printf("%d ", items[i]);
  }
  printf("\n");
}

int getRear() {
  if (isEmpty()) {
    printf("Underflow");
    return -1;
  }
  return items[rear];
}

int main() {
  insertRear(5);
  insertRear(10);
  printf("rear: %d\n", getRear());
  deleteRear();
  printf("rear: %d\n", getRear());
  insertFront(15);
  printf("rear: %d\n", getFront());
  deleteFront();
  printf("rear: %d\n", getFront());
  display();
}
