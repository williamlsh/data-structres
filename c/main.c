// Checking if a binary tree is a perfect binary tree in C

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

int depth(struct Node *root) {
  int d = 0;
  while (root != NULL) {
    d++;
    root = root->left;
  }
  return d;
}

bool is_perfect(struct Node *root, int d, int level) {
  if (root == NULL) {
    return true;
  }

  if (root->left == NULL && root->right == NULL) {
    return (d == level + 1);
  }
  if (root->left == NULL || root->right == NULL) {
    return false;
  }

  return is_perfect(root->left, d, level + 1) &&
         is_perfect(root->right, d, level + 1);
}

bool is_Perfect(struct Node *root) {
  int d = depth(root);
  return is_perfect(root, d, 0);
}

int main() {
  struct Node *root = NULL;
  root = createNode(1);
  root->left = createNode(2);
  root->right = createNode(3);
  root->left->left = createNode(4);
  root->left->right = createNode(5);
  root->right->left = createNode(6);

  if (is_Perfect(root))
    printf("The tree is a perfect binary tree\n");
  else
    printf("The tree is not a perfect binary tree\n");
}
