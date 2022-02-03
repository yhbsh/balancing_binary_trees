#include "../lib/functions.h"


int main() {
    srand(time(NULL));

    int n;
    scanf("%d", &n);

    Node *root = init_tree(n);

    draw(root);

    return 0;
}
