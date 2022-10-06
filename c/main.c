// Linked list implementation in C

#include <stdio.h>
#include <stdlib.h>

// Creating a node.
struct Node {
  int data;
  struct Node *next;
};

// Insert at beginning.
void insertAtBeginning(struct Node **head_ref, int new_data) {
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
  new_node->data = new_data;
  new_node->next = *head_ref;
  *head_ref = new_node;
}

void insertAtEnd(struct Node **head_ref, int new_data) {
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
  new_node->data = new_data;
  new_node->next = NULL;

  if (*head_ref == NULL) {
    *head_ref = new_node;
    return;
  }

  struct Node *temp = *head_ref;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = new_node;
}

void insertAfter(struct Node **head_ref, int position, int new_data) {
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
  new_node->data = new_data;

  struct Node *temp = *head_ref;
  for (int i = 2; i < position; i++) {
    if (temp->next != NULL) {
      temp = temp->next;
    }
  }
  new_node->next = temp->next;
  temp->next = new_node;
}

void deleteNode(struct Node **head_ref, int key) {
  struct Node *temp = *head_ref, *prev;

  if (temp != NULL && temp->data == key) {
    *head_ref = temp->next;
    free(temp);
    return;
  }

  // Find the key to be deleted
  while (temp != NULL && temp->data != key) {
    prev = temp;
    temp = temp->next;
  }

  // If the key is not present
  if (temp == NULL) {
    return;
  }

  // Remove the node
  prev->next = temp->next;
  free(temp);
}

int searchNode(struct Node **head_ref, int key) {
  struct Node *temp = *head_ref;
  while (temp != NULL) {
    if (temp->data == key) {
      return 1;
    }
    temp = temp->next;
  }
  return 0;
}

void reverse(struct Node **head_ref) {
  struct Node *current = *head_ref, *next, *prev = NULL;

  while (current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }

  *head_ref = prev;
}

void sort(struct Node **head_ref) {
  struct Node *current = *head_ref, *index = NULL;
  int temp;

  if (head_ref == NULL) {
    return;
  }

  while (current != NULL) {
    // index points to the node next to current
    index = current->next;
    while (index != NULL) {
      if (current->data > index->data) {
        temp = current->data;
        current->data = index->data;
        index->data = temp;
      }
      index = index->next;
    }
    current = current->next;
  }
}

void display(struct Node *node) {
  while (node != NULL) {
    printf("%d ", node->data);
    node = node->next;
  }
}

int main() {
  struct Node *head = NULL;

  insertAtEnd(&head, 1);
  insertAtBeginning(&head, 2);
  insertAtBeginning(&head, 3);
  insertAtEnd(&head, 4);
  insertAfter(&head, 2, 5);

  printf("Linked list: ");
  display(head);

  printf("\nAfter deleting an element: ");
  deleteNode(&head, 3);
  display(head);

  int item_to_find = 3;
  if (searchNode(&head, item_to_find)) {
    printf("\n%d is found", item_to_find);
  } else {
    printf("\n%d is not found", item_to_find);
  }

  printf("\nAfter reversing list: ");
  reverse(&head);
  display(head);

  printf("\nAfter sorting list: ");
  sort(&head);
  display(head);
}
