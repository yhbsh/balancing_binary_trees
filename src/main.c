#include "../lib/functions.h"





int main() {
    srand(time(NULL));

    int n, out = 0;
    scanf("%d", &n);

    Node *root = init_tree(n);

    // draw(root, &out);


    first_transformation(root);    

    draw(root, &out);

    second_transformation(root);

    draw(root, &out);

    third_transformation(root);

    draw(root, &out);

    forth_transformation(root);

    draw(root, &out);

    draw(root, &out);





    return 0;
}
