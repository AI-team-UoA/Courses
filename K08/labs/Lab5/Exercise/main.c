#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

int main() {
    BSTNode* root = NULL;

    // Insert some nodes into the tree
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    // Print the in-order traversal of the tree
    printf("In-order traversal: ");
    inorder(root, visit);
    printf("\n");

    // Delete some nodes from the tree
    printf("Deleting nodes 20 and 60\n");
    root = delete(root, 20);
    root = delete(root, 60);

    // Print the in-order traversal of the tree again
    printf("In-order traversal after deletion: ");
    inorder(root, visit);
    printf("\n");

    destroy(root);
    return 0;
}


