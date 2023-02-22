#ifndef CODE_BST_H
#define CODE_BST_H

// Define a node in the binary search tree
typedef struct BSTNode BSTNode;
typedef struct BSTNode {
    int data;
    BSTNode *left, *right;
} BSTNode;

// Function pointer for visiting nodes during traversal
typedef void (*Visit)(BSTNode* node);
void visit(BSTNode* node);
BSTNode* create_node(int data);
BSTNode* insert(BSTNode* root, int data);
void destroy(BSTNode* node);

/* -------------------------- */
/* FUNCTIONS FOR LAB EXERCISE */
/* -------------------------- */

BSTNode* delete(BSTNode* root, int data);
BSTNode* search(BSTNode* root, int data);
void inorder(BSTNode* root, Visit visit);
void preorder(BSTNode* root, Visit visit);
void postorder(BSTNode* root, Visit visit);
BSTNode* min_value(BSTNode* root);
BSTNode* max_value(BSTNode* root);

#endif //CODE_BST_H
