#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "lib.h"

#define INF 10000

struct Node {
    struct Node *left, *right;
    int data;
    int color;
};

Node *bst_node_create(int data, int color) {
    Node *n  = (Node *)malloc(sizeof(Node));
    n->left  = NULL;
    n->right = NULL;
    n->data  = data;
    n->color = color;

    return n;
}

void bst_node_free(Node **node) {
    free(*node);
    *node = NULL;
}

Node *bst_add(Node *root, Node *node) {
    if (root == NULL) {
        return node;
    } else {
        Node *curr = root;
        Node *prev = NULL;
        bool run   = true;

        while (curr != NULL) {
            if (curr->data > node->data) {
                prev = curr;
                curr = curr->left;
            } else if (curr->data < node->data) {
                prev = curr;
                curr = curr->right;
            } else {
                return root;
            }
        }

        if (prev->data < node->data) {
            prev->right = node;
        } else if (prev->data > node->data) {
            prev->left = node;
        }

        return root;
    }
}

Node *bst_create(int nodes) {

    Node *root = bst_node_create(INF, 1);

    for (int i = 0; i < nodes; i++) {
        int data   = rand() % 5000;
        bool color = rand() % 2;
        Node *node = bst_node_create(data, color);
        if (node->color == true) {
            root->right = bst_add(root->right, node);
        } else {
            root->left = bst_add(root->left, node);
        }
    }

    return root;
}

void bst_free_recursive(Node *node) {
    if (node == NULL) {
        return;
    }

    bst_free_recursive(node->left);
    bst_free_recursive(node->right);

    bst_node_free(&node);
}

void bst_free(Node **root) {
    if (root == NULL || *root == NULL) {
        return;
    }

    bst_free_recursive(*root);

    *root = NULL;
}

Node *right_rotation(Node *node, Node *parent) {

    Node *left_child = node->left;
    if (left_child != NULL) {
        Node *tmp         = left_child->right;
        left_child->right = node;
        node->left        = tmp;

        if (parent == NULL) {
            return left_child;
        }

        parent->right = left_child;

        return left_child;
    } else {
        return node;
    }
}

Node *left_rotation(Node *node, Node *parent) {
    Node *right_child = node->right;

    if (right_child != NULL) {
        Node *tmp         = right_child->left;
        right_child->left = node;
        node->right       = tmp;

        if (parent == NULL) {
            return right_child;
        }

        parent->left = right_child;
        return right_child;
    } else {
        return node;
    }
}

void bst_transform_1(Node *root) {

    Node *parent;
    Node *curr;
    int out = 0;

    parent = root;
    curr   = root->left;
    while (curr != NULL) {
        if (curr->right != NULL) {
            curr = left_rotation(curr, parent);
        } else {
            parent = curr;
            curr   = curr->left;
        }
    }

    parent = root;
    curr   = root->right;
    while (curr != NULL) {
        if (curr->left != NULL) {
            curr = right_rotation(curr, parent);
        } else {
            parent = curr;
            curr   = curr->right;
        }
    }
}

Node *special_right_rotation(Node *node, Node *parent) {
    Node *left_child = node->left;
    if (left_child != NULL) {
        left_child->right = node;
        node->left        = NULL;
        parent->left      = left_child;

        return left_child;
    } else {
        return node;
    }
}

Node *special_left_rotation(Node *node, Node *parent) {
    Node *right_child = node->right;
    if (right_child != NULL) {
        right_child->left = node;
        node->right       = NULL;
        parent->right     = right_child;

        return right_child;
    } else {
        return node;
    }
}

void bst_transform_2(Node *root) {

    Node *curr_left    = root->left;
    Node *curr_right   = root->right;
    Node *parent_left  = root;
    Node *parent_right = root;

    int k = 2;
    int n = 1;

    while (curr_left != NULL || curr_right != NULL) {
        for (int i = 0; i < k * n; i++) {
            if (curr_left != NULL) curr_left = special_right_rotation(curr_left, parent_left);

            if (curr_right != NULL) {
                curr_right = special_left_rotation(curr_right, parent_right);
            }
        }
        if (curr_left != NULL) {
            parent_left = curr_left;
            curr_left   = curr_left->left;
        }

        if (curr_right != NULL) {
            parent_right = curr_right;
            curr_right   = curr_right->right;
        }
        n++;
    }
}

void bst_transform_3(Node *root) {

    Node *curr_left    = root->left;
    Node *curr_right   = root->right;
    Node *parent_left  = root;
    Node *parent_right = root;

    while (curr_left != NULL || curr_right != NULL) {
        for (int i = 0; i < rand() % 10; i++) {
            if (curr_left != NULL) curr_left = special_right_rotation(curr_left, parent_left);

            if (curr_right != NULL) {
                curr_right = special_left_rotation(curr_right, parent_right);
            }
        }
        if (curr_left != NULL) {
            parent_left = curr_left;
            curr_left   = curr_left->left;
        }

        if (curr_right != NULL) {
            parent_right = curr_right;
            curr_right   = curr_right->right;
        }
    }
}

void bst_transform_4(Node *root) {

    Node *curr_left    = root->left;
    Node *curr_right   = root->right;
    Node *parent_left  = root;
    Node *parent_right = root;

    while (curr_left != NULL || curr_right != NULL) {
        for (int i = 0; i < rand() % 10; i++) {
            if (curr_left != NULL) curr_left = special_right_rotation(curr_left, parent_left);
        }
        for (int i = 0; i < rand() % 10; i++) {
            if (curr_right != NULL) {
                curr_right = special_left_rotation(curr_right, parent_right);
            }
        }
        if (curr_left != NULL) {
            parent_left = curr_left;
            curr_left   = curr_left->left;
        }

        if (curr_right != NULL) {
            parent_right = curr_right;
            curr_right   = curr_right->right;
        }
    }
}

void bst_dump_recursive(Node *current_node, FILE *dot_file, int *null_counter) {
    if (current_node != NULL) {
        const char *node_color = current_node->color ? "black" : "white";
        const char *font_color = current_node->color ? "white" : "black";

        fprintf(dot_file, "\t\"%d %s\" [style=filled, fillcolor=\"%s\", fontcolor=\"%s\", fontsize=12, shape=doublecircle, fontname=\"Comic Sans MS\"];\n", current_node->data, node_color, node_color, font_color);

        // Left child
        if (current_node->left != NULL) {
            const char *left_color      = current_node->left->color ? "black" : "white";
            const char *left_font_color = current_node->left->color ? "white" : "black";

            fprintf(dot_file, "\t\"%d %s\" [style=filled, fillcolor=\"%s\", fontcolor=\"%s\", fontsize=12, shape=doublecircle, fontname=\"Comic Sans MS\"];\n", current_node->left->data, left_color, left_color, left_font_color);
            fprintf(dot_file, "\t\"%d %s\" -> \"%d %s\";\n", current_node->data, node_color, current_node->left->data, left_color);
        } else {
            fprintf(dot_file, "\t\"NIL%d\" [style=invis];\n", *null_counter);
            fprintf(dot_file, "\t\"%d %s\" -> \"NIL%d\" [style=invis];\n", current_node->data, node_color, (*null_counter)++);
        }

        // Virtual middle NIL child
        fprintf(dot_file, "\t\"NIL%d\" [style=invis];\n", *null_counter);
        fprintf(dot_file, "\t\"%d %s\" -> \"NIL%d\" [style=invis];\n", current_node->data, node_color, (*null_counter)++);

        // Right child
        if (current_node->right != NULL) {
            const char *right_color      = current_node->right->color ? "black" : "white";
            const char *right_font_color = current_node->right->color ? "white" : "black";

            fprintf(dot_file, "\t\"%d %s\" [style=filled, fillcolor=\"%s\", fontcolor=\"%s\", fontsize=12, shape=doublecircle, fontname=\"Comic Sans MS\"];\n", current_node->right->data, right_color, right_color, right_font_color);
            fprintf(dot_file, "\t\"%d %s\" -> \"%d %s\";\n", current_node->data, node_color, current_node->right->data, right_color);
        } else {
            fprintf(dot_file, "\t\"NIL%d\" [style=invis];\n", *null_counter);
            fprintf(dot_file, "\t\"%d %s\" -> \"NIL%d\" [style=invis];\n", current_node->data, node_color, (*null_counter)++);
        }

        // Recursively dump left and right subtrees
        bst_dump_recursive(current_node->left, dot_file, null_counter);
        bst_dump_recursive(current_node->right, dot_file, null_counter);
    }
}

void bst_dump(Node *root, const char *file_path) {
    FILE *dot_file;
    if (root == NULL) {
        printf("> ERROR: Empty tree!");
        return;
    }

    dot_file = fopen(file_path, "w");
    if (dot_file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fprintf(dot_file, "digraph binary_search_tree {\n");
    fprintf(dot_file, "\tordering = out;\n");
    fprintf(dot_file, "\tsplines = false;\n");

    int null_counter = 0;
    bst_dump_recursive(root, dot_file, &null_counter);

    fprintf(dot_file, "}\n");
    fclose(dot_file);

    printf("BST dumped to '%s' file.\n", file_path);
}
