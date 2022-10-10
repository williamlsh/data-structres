// Binary Search Tree operations in C
// Implementation reference: https://www.geeksforgeeks.org/binary-search-tree-set-2-delete/

#include <stdio.h>
#include <stdlib.h>

struct node {
  int key;
  struct node *left, *right;
};

// Create a node
struct node *newNode(int key) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = key;
  temp->left = temp->left = NULL;
  return temp;
}

// Inorder Traversal
void inorder(struct node *root) {
  if (root == NULL) {
    return;
  }

  // Traverse left
  inorder(root->left);

  // Traverse root
  printf("%d -> ", root->key);

  // Traverse right
  inorder(root->right);
}

// Insert a node
struct node *insert(struct node *node, int key) {
  // Return a new node if the tree is empty
  if (node == NULL) {
    return newNode(key);
  }
  // Traverse to the right place and insert the node
  if (key < node->key) {
    node->left = insert(node->left, key);
  } else {
    node->right = insert(node->right, key);
  }
  return node;
}

// Find the inorder successor
struct node *minValueNode(struct node *node) {
  struct node *current = node;

  // Find the leftmost leaf
  if (current && current->left != NULL) {
    current = current->left;
  }

  return current;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  // Return if the tree is empty
  if (root == NULL) {
    return root;
  }

  // Find the node to be deleted.
  if (key < root->key) {
    // If the key to be deleted
    // is smaller than the root's
    // key, then it lies in left subtree
    root->left = deleteNode(root->left, key);
  } else if (key > root->key) {
    // If the key to be deleted
    // is greater than the root's
    // key, then it lies in right subtree
    root->right = deleteNode(root->right, key);
  } else {
    // if key is same as root's key,
    // then this is the node
    // to be deleted.

    // If the node is with only one child or no child
    if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct node *temp = root->left;
      free(root);
      return temp;
    }

    // node with two children:
    // Get the inorder successor
    // (smallest in the right subtree)
    struct node *temp = minValueNode(root->right);
    // Place the inorder successor in position of the node to be deleted
    root->key = temp->key;
    // Delete the inorder successor
    root->right = deleteNode(root->right, key);
  }
  return root;
}

int main() {
  /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
  struct node *root = NULL;
  root = insert(root, 50);
  root = insert(root, 30);
  root = insert(root, 20);
  root = insert(root, 40);
  root = insert(root, 70);
  root = insert(root, 60);
  root = insert(root, 80);

  printf("Inorder traversal of the given tree \n");
  inorder(root);

  printf("\nDelete 20\n");
  root = deleteNode(root, 20);
  printf("Inorder traversal of the modified tree \n");
  inorder(root);

  printf("\nDelete 30\n");
  root = deleteNode(root, 30);
  printf("Inorder traversal of the modified tree \n");
  inorder(root);

  printf("\nDelete 50\n");
  root = deleteNode(root, 50);
  printf("Inorder traversal of the modified tree \n");
  inorder(root);

  return 0;
}
