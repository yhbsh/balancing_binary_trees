#include "../lib/functions.h"




int main() {
    srand(time(NULL));

    int n, out = 0;
    scanf("%d", &n);

    Node *root = init_tree(n);

    draw(root, &out);


    first_transformation(root);    


    draw(root, &out);





    return 0;
}
