#ifndef LIB_H
#define LIB_H

#define BST_API

typedef struct Node Node;

BST_API Node *bst_create(int nodes);
BST_API void bst_free(Node **root);

BST_API void bst_dump(Node *root, const char *file_path);

BST_API void bst_transform_1(Node *root);
BST_API void bst_transform_2(Node *root);
BST_API void bst_transform_3(Node *root);
BST_API void bst_transform_4(Node *root);

#endif // LIB_H
