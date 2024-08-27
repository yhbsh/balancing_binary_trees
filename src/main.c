#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "lib.h"

int main(int argc, const char *argv[]) {
    int nodes;

    if (argc <= 1) {
        nodes = 100;
    }

    srand(time(NULL));

    Node *root = bst_create(nodes);

    bst_transform_1(root);
    bst_dump(root, "bst1.dot");

    bst_transform_2(root);
    bst_dump(root, "bst2.dot");

    bst_transform_3(root);
    bst_dump(root, "bst3.dot");

    bst_transform_4(root);
    bst_dump(root, "bst4.dot");

    bst_free(&root);

    return 0;
}
