#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

// Creating a new BSTNode with input data
BSTNode* create_node(int data) {
    BSTNode* temp = (BSTNode*)malloc(sizeof(BSTNode));
    temp->data = data;
    temp->left = temp->right = NULL;

    return temp;
}

// Insert a new node into the binary search tree
BSTNode* insert(BSTNode* root, int data) {
    if (root == NULL) return create_node(data);
    if (data < root->data)
        // If the data is less than the root node, insert it into the left subtree
        root->left = insert(root->left, data);
    else if (data > root->data)
        // If the data is greater than or equal to the root node, insert it into the right subtree
        root->right = insert(root->right, data);
    return root;
}

// Ignore this function
void visit(BSTNode* node) {
    printf("%d ", node->data);
}

// De-allocating all the memory of the tree
void destroy(BSTNode* node) {
    if (node != NULL) {
        freeTree(node->left);
        freeTree(node->right);
        free(node);
    }
}

/* -------------------------- */
/* FUNCTIONS FOR LAB EXERCISE */
/* -------------------------- */

// Delete a node from the binary search tree
BSTNode* delete(BSTNode* root, int data) {
    /* EXERCISE */
}

// Search a node from the binary search tree
BSTNode* search(BSTNode* root, int data) {
    /* EXERCISE */
}

// Traverse the binary search tree in-order
void inorder(BSTNode* root, Visit visit) {
    /* EXERCISE */
}

// Traverse the binary search tree pre-order
void preorder(BSTNode* root, Visit visit) {
    /* EXERCISE */
}

// Traverse the binary search tree post-order
void postorder(BSTNode* root, Visit visit) {
    /* EXERCISE */
}

// Find minimum value of a binary search tree
BSTNode* min_value(BSTNode* root) {
    /* EXERCISE */
}

// Find maximum value of a binary search tree
BSTNode* max_value(BSTNode* root) {
    /* EXERCISE */
}
