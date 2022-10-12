// Checking if a binary tree is a full binary tree in C

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
  node->left = NULL;
  node->right = NULL;
  return node;
}

bool isFullBinaryTree(struct Node *root) {
  if (root == NULL) {
    return true;
  }

  if (root->left == NULL && root->right == NULL) {
    return true;
  } else {
    return isFullBinaryTree(root->left) && isFullBinaryTree(root->right);
  }
  return false;
}

int main() {
  struct Node *root = NULL;
  root = createNode(1);
  root->left = createNode(2);
  root->left = createNode(3);

  if (isFullBinaryTree(root))
    printf("The tree is a full binary tree\n");
  else
    printf("The tree is not a full binary tree\n");
}
