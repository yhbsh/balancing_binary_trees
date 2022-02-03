



Node *init_node(int data, bool color) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->left = n->right = NULL;
    n->data = data;
    // true (1) is black
    // false (0) is white
    n->color = color;

    return n;
}

Node *insert_tree(Node *root, Node *node) {
    if (root == NULL) {
        return node;

    } else {
        Node *curr = root;
        Node *prev = NULL;
        bool run = true;

        while (run == true && curr != NULL) {
            if (curr->data > node->data) {
                prev = curr;
                curr = curr->left;
            } else if (curr->data < node->data) {
                prev = curr;
                curr = curr->right;
            } else {                
                return root;
            }

            if (curr == NULL) {
                run = false;
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

 
Node *init_tree(int n) {

    Node *root = init_node(INF, 1); // this is the root

    for (int i = 0; i < n; i++) {
        int data = rand() % 5000;
        bool color = rand() % 2;

        Node *node = init_node(data, color);

        if (node->color == true) {
            root->right = insert_tree(root->right, node);
        } else {
            root->left = insert_tree(root->left, node);
        } 
    }


    return root;

}


Node *right_rotation(Node *node, Node* parent) {


    Node *left_child = node->left;
    if (left_child != NULL) {
        Node *tmp = left_child->right;
        left_child->right = node;            
        node->left = tmp;

        

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
        Node *tmp = right_child->left;
        right_child->left = node;
        node->right = tmp;
        

        if (parent == NULL) {
            return right_child;
        }


        parent->left = right_child;
        return right_child;
    } else {
        return node;
    }
    
}



void first_transformation(Node *root) {
        
    Node *parent;
    Node *curr;
    int out = 0;

    
    parent = root;
    curr = root->left;
    while (curr != NULL) {
        if (curr->right != NULL) {
            curr = left_rotation(curr, parent);
        } else {
            parent = curr;
            curr = curr->left;
        }
    }

    parent = root;
    curr = root->right;
    while(curr != NULL) {
        if (curr->left != NULL) {
            curr = right_rotation(curr, parent);
        } else {
            parent = curr;
            curr = curr->right;
        }
    }
}

Node *special_right_rotation(Node *node, Node *parent) {
    Node *left_child = node->left;
    if (left_child != NULL) {
        left_child->right = node;            
        node->left = NULL;
        parent->left = left_child;

        return left_child;
    } else {
        return node;
    }

}

Node *special_left_rotation(Node *node, Node *parent) {
    Node *right_child = node->right;
    if (right_child != NULL) {
        right_child->left = node;            
        node->right = NULL;
        parent->right = right_child;
        
        return right_child;
    } else {
        return node;
    }
}

void second_transformation(Node *root) {

    Node *curr_left = root->left;
    Node *curr_right = root->right;
    Node *parent_left = root;
    Node *parent_right = root;

    int k = 2;
    int n = 1;


    while (curr_left != NULL || curr_right != NULL) {
        for (int i = 0; i < k * n; i++) {
            if (curr_left != NULL)
                curr_left = special_right_rotation(curr_left, parent_left);

            if (curr_right != NULL) {
                curr_right = special_left_rotation(curr_right, parent_right);
            }
        }
        if (curr_left != NULL) {
            parent_left = curr_left;
            curr_left = curr_left->left;
        }

        if (curr_right != NULL) {
            parent_right = curr_right;
            curr_right = curr_right->right;
        }
        n++;
    }

}

void third_transformation(Node *root) {

    Node *curr_left = root->left;
    Node *curr_right = root->right;
    Node *parent_left = root;
    Node *parent_right = root;




    while (curr_left != NULL || curr_right != NULL) {
        for (int i = 0; i < rand() % 10; i++) {
            if (curr_left != NULL)
                curr_left = special_right_rotation(curr_left, parent_left);

            if (curr_right != NULL) {
                curr_right = special_left_rotation(curr_right, parent_right);
            }
        }
        if (curr_left != NULL) {
            parent_left = curr_left;
            curr_left = curr_left->left;
        }

        if (curr_right != NULL) {
            parent_right = curr_right;
            curr_right = curr_right->right;
        }
    }

}



void forth_transformation(Node *root) {

    Node *curr_left = root->left;
    Node *curr_right = root->right;
    Node *parent_left = root;
    Node *parent_right = root;




    while (curr_left != NULL || curr_right != NULL) {
        for (int i = 0; i < rand() % 10; i++) {
            if (curr_left != NULL)
                curr_left = special_right_rotation(curr_left, parent_left);
        }
        for (int i = 0; i < rand() % 10; i++) {
            if (curr_right != NULL) {
                curr_right = special_left_rotation(curr_right, parent_right);
            }
        }
        if (curr_left != NULL) {
            parent_left = curr_left;
            curr_left = curr_left->left;
        }

        if (curr_right != NULL) {
            parent_right = curr_right;
            curr_right = curr_right->right;
        }
    }

}