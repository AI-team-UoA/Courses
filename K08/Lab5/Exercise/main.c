#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

int main() {
    BSTree* tree = create_tree();

    // Insert some nodes into the tree
    insert(tree, 50);
    insert(tree, 30);
    insert(tree, 70);
    insert(tree, 20);
    insert(tree, 40);
    insert(tree, 60);
    insert(tree, 80);

    // Print the in-order traversal of the tree
    printf("In-order traversal: ");
    inorder(tree, visit);
    printf("\n");

    // Delete some nodes from the tree
    printf("Deleting nodes 20 and 60\n");
    delete(tree, 20);
    delete(tree, 60);

    // Print the in-order traversal of the tree again
    printf("In-order traversal after deletion: ");
    inorder(tree, visit);
    printf("\n");

    destroy_tree(tree);
    return 0;
}


