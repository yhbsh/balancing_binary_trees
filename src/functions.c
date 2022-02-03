



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
        int data = rand() % 100;
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