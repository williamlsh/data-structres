// Checking if a binary tree is a complete binary tree in C

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int item;
  struct Node *left, *right;
};

struct Node *createNode(int item) {
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->item = item;
  node->left = node->right = NULL;
  return node;
}

// Count the number of nodes
int countNumNodes(struct Node *root) {
  if (root == NULL) {
    return 0;
  }
  return (1 + countNumNodes(root->left) + countNumNodes(root->right));
}

bool checkComplete(struct Node *root, int index, int numberNodes) {
  if (root == NULL) {
    return true;
  }
  if (index >= numberNodes) {
    return false;
  }
  return checkComplete(root->left, 2 * index + 1, numberNodes) &&
         checkComplete(root->right, 2 * index + 2, numberNodes);
}

int main() {
  struct Node *root = NULL;
  root = createNode(1);
  root->left = createNode(2);
  root->right = createNode(3);
  root->left->left = createNode(4);
  root->left->right = createNode(5);
  root->right->left = createNode(6);

  int node_count = countNumNodes(root);
  int index = 0;
  if (checkComplete(root, index, node_count))
    printf("The tree is a complete binary tree\n");
  else
    printf("The tree is not a complete binary tree\n");
}
