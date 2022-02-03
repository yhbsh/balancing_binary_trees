#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "./model.h"
#include "../src/functions.c"
#include "./draw_tree.h"

Node *init_node(int data, bool color);
Node *insert_tree(Node *root, Node *node);
Node *init_tree(int n);