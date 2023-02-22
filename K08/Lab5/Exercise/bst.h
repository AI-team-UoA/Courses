#ifndef CODE_BST_H
#define CODE_BST_H
#include <stdbool.h>

typedef struct tree_struct BSTree;
typedef struct BSTNode BSTNode;

// Function pointer for visiting nodes during traversal
typedef void (*Visit)(BSTNode* node);
void visit(BSTNode* node);


/* ------------- */
/* BST INTERFACE */
/* ------------- */
BSTree* create_tree();
void destroy_tree(BSTree* tree);

void insert(BSTree* tree, int data);
void delete(BSTree* tree, int data);
bool search(BSTree* tree, int data);

void inorder(BSTree* tree, Visit visit);
void preorder(BSTree* tree, Visit visit);
void postorder(BSTree* tree, Visit visit);

int min_value(BSTree* tree);
int max_value(BSTree* tree);

#endif //CODE_BST_H