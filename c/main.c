// Checking if a binary tree is height balanced in C
// Implementation reference:
// https://www.geeksforgeeks.org/how-to-determine-if-a-binary-tree-is-balanced/

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

int max(int a, int b) { return (a >= b) ? a : b; }

int height(struct Node *node) {
  if (node == NULL) {
    return 0;
  }
  return 1 + max(height(node->left), height(node->right));
}

bool isBalanced(struct Node *root) {
  int leftHeight, rightHeight;
  if (root == NULL) {
    return true;
  }

  leftHeight = height(root->left);
  rightHeight = height(root->right);

  if (abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) &&
      isBalanced(root->right)) {
    return true;
  }

  return false;
}

int main() {
  struct Node *root = NULL;
  root = createNode(1);
  root->left = createNode(2);
  root->right = createNode(3);
  root->left->left = createNode(4);
  root->left->right = createNode(5);
  root->left->left->left = createNode(6);

  if (isBalanced(root))
    printf("Tree is balanced");
  else
    printf("Tree is not balanced");
}
