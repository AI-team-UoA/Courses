#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "bst.h"

// Define a binary search tree
struct tree_struct{
    BSTNode* root;
};

// Define a node in the binary search tree
typedef struct BSTNode {
    int data;
    BSTNode *left, *right;
} BSTNode;


BSTNode* insert_node(BSTNode* root, int data);
void visit(BSTNode* node);
void destroy(BSTNode* node);
BSTNode* delete_node(BSTNode* root, int data) ;
bool search_node(BSTNode* root, int data) ;
void inorder_traversal(BSTNode* root, Visit visit);
void preorder_traversal(BSTNode* root, Visit visit);
void postorder_traversal(BSTNode* root, Visit visit);
int find_min_value(BSTNode* root);
int find_max_value(BSTNode* root);

/* -------------------------- */
/* DRIVER CODE FOR BST MODULE */
/* YOU DON'T HAVE TO EDIT THIS */
/* -------------------------- */

// Create and return a pointer to a new BST
BSTree* create_tree() {
    BSTree* new_tree = malloc(sizeof(BSTree));
    new_tree->root = NULL;
    return new_tree;
}

// Free all memory allocated for a BST
void destroy_tree(BSTree* tree){
    if(tree->root != NULL)
        destroy(tree->root);
}

// Insert a new element into a given BST
void insert(BSTree* tree, int data) {
    tree->root = insert_node(tree->root, data);
}

// Delete a node with given data in provided BST
void delete(BSTree* tree, int data){
    tree->root = delete_node(tree->root, data);
}

// Returns whether a node with given data exists in the BST
bool search(BSTree* tree, int data){
    return search_node(tree->root, data);
}

void inorder(BSTree* tree, Visit visit) {
    inorder_traversal(tree->root, visit);
}

void preorder(BSTree* tree, Visit visit) {
    preorder_traversal(tree->root, visit);
}

void postorder(BSTree* tree, Visit visit) {
    postorder_traversal(tree->root, visit);
}

int min_value(BSTree* tree) {
    assert(tree->root != NULL);
    return find_min_value(tree->root);
}

int max_value(BSTree* tree) {
    assert(tree->root != NULL);
    return find_max_value(tree->root);
}

/* ------------- */
/* BST FUNCTIONS */
/* ------------- */

// Creating a new BSTNode with input data
BSTNode* create_node(int data) {
    BSTNode* temp = (BSTNode*)malloc(sizeof(BSTNode));
    temp->data = data;
    temp->left = temp->right = NULL;

    return temp;
}

// Insert a new node into the binary search tree
BSTNode* insert_node(BSTNode* root, int data) {
    if (root == NULL) return create_node(data);
    if (data < root->data)
        // If the data is less than the root node, insert it into the left subtree
        root->left = insert_node(root->left, data);
    else if (data > root->data)
        // If the data is greater than or equal to the root node, insert it into the right subtree
        root->right = insert_node(root->right, data);
    return root;
}

// Ignore this function
void visit(BSTNode* node) {
    printf("%d ", node->data);
}

// De-allocating all the memory of the tree
void destroy(BSTNode* node) {
    if (node != NULL) {
        destroy(node->left);
        destroy(node->right);
        free(node);
    }
}

/* -------------------------- */
/* FUNCTIONS FOR LAB EXERCISE */
/* -------------------------- */

// Delete a node from the binary search tree
BSTNode* delete_node(BSTNode* root, int data) {
    /* EXERCISE */

    if (root == NULL) return root;
    if (data < root->data)
        // If the data is less than the root node, search for it in the left subtree
        root->left = delete_node(root->left, data);
    else if (data > root->data)
        // If the data is greater than the root node, search for it in the right subtree        
        root->right = delete_node(root->right, data);
    else {
        // If the data is found, delete the node
        if (root->left == NULL) {
            BSTNode* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            BSTNode* temp = root->left;
            free(root);
            return temp;
        }
        BSTNode* temp = root->right;
        while (temp->left != NULL)
            temp = temp->left;
        root->data = temp->data;
        root->right = delete_node(root->right, temp->data);
    }

    return root;
}

// Search a node from the binary search tree
bool search_node(BSTNode* root, int data) {
    /* EXERCISE */
    if (root == NULL)
        return false;
    if (root->data == data)
        return true;
    if (root->data < data)
        return search_node(root->right, data);

    return search_node(root->left, data);
}

// Traverse the binary search tree in-order
void inorder_traversal(BSTNode* root, Visit visit) {
    /* EXERCISE */
    if (root != NULL) {
        inorder_traversal(root->left, visit);
        visit(root);
        inorder_traversal(root->right, visit);
    }
}

// Traverse the binary search tree pre-order
void preorder_traversal(BSTNode* root, Visit visit) {
    /* EXERCISE */
    if (root != NULL) {
        visit(root);
        preorder_traversal(root->left, visit);
        preorder_traversal(root->right, visit);
    }
}

// Traverse the binary search tree post-order
void postorder_traversal(BSTNode* root, Visit visit) {
    /* EXERCISE */
    if (root != NULL) {
        postorder_traversal(root->left, visit);
        postorder_traversal(root->right, visit);
        visit(root);
    }
}

// Find minimum value of a binary search tree
int find_min_value(BSTNode* root) {
    /* EXERCISE */
    if (root->left == NULL)
        return root->data;
    return find_min_value(root->left);
}

// Find maximum value of a binary search tree
int find_max_value(BSTNode* root) {
    /* EXERCISE */
    if (root->right == NULL)
        return root->data;
    return find_max_value(root->right);
}