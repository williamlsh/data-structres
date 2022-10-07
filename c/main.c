// Doubly linked list in C

#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *prev;
  struct Node *next;
};

// Insert node at the front
void insertAtFront(struct Node **head, int data) {
  // allocate memory for newNode
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

  // assign data to newNode
  newNode->data = data;
  // make newNode as a head
  newNode->next = *head;
  // assign null to prev
  newNode->prev = NULL;

  // previous of head (now head is the second node) is newNode
  if (*head != NULL) {
    (*head)->prev = newNode;
  }
  // head points to newNode
  *head = newNode;
}

// Insert a newNode at the end of the list
void insertAtEnd(struct Node **head, int data) {
  // allocate memory for node
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  // store the head node temporarily (for later use)
  struct Node *temp = *head;

  // assign data to newNode
  newNode->data = data;
  // assign null to next of newNode
  newNode->next = NULL;

  // if the linked list is empty, make the newNode as head node
  if (*head == NULL) {
    newNode->prev = NULL;
    *head = newNode;
    return;
  }

  // if the linked list is not empty, traverse to the end of the linked list
  while (temp->next != NULL) {
    temp = temp->next;
  }
  // now, the last node of the linked list is temp
  // assign next of the last node (temp) to newNode
  temp->next = newNode;
  // assign prev of newNode to temp
  newNode->prev = temp;
}

void insertAfter(struct Node **head, int position, int data) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  struct Node *temp = *head, *index;

  newNode->data = data;

  if (*head == NULL) {
    return;
  }

  for (int i = 2; i < position; ++i) {
    if (temp->next != NULL) {
      temp = temp->next;
    }
  }
  index = temp->next;
  temp->next = newNode;
  newNode->prev = temp;
  newNode->next = index;
  index->prev = newNode;
}

void deleteNode(struct Node **head, int data) {
  struct Node *temp = *head, *prev;

  if (temp != NULL && temp->data == data) {
    *head = temp->next;
    temp->next->prev = NULL;
    free(temp);
  }

  while (temp != NULL && temp->data != data) {
    prev = temp;
    temp = temp->next;
  }
  if (temp == NULL) {
    return;
  }
  prev->next = temp->next;
  temp->next->prev = prev;
  free(temp);
}

void display(struct Node *head) {
  while (head != NULL) {
    printf("%d->", head->data);
    head = head->next;
  }
  if (head == NULL) {
    printf("NULL\n");
  } else {
    printf("\n");
  }
}

int main() {
  // initialize an empty node
  struct Node *head = NULL;

  insertAtEnd(&head, 5);
  insertAtFront(&head, 1);
  insertAtFront(&head, 6);
  insertAtEnd(&head, 9);
  display(head);

  insertAfter(&head, 3, 0);
  display(head);

  deleteNode(&head, 5);
}
