
void draw_tree_dot(Node* R, FILE *f, int *nbNil)
{
    if (R != NULL)
    {
        fprintf(f, "\t\"%d %s\" [style=filled, fillcolor=\"%s\", fontcolor=\"%s\", fontsize=12, shape=doublecircle, fontname=\"Comic Sans MS\"];\n", R->data, R->color == true ? "black" : "white",R->color == true ? "black" : "white", R->color == true ? "white" : "black");
        // Dessiner un arc vers le fils gauche
        if (R->left != NULL) {
            fprintf(f, "\t\"%d %s\" [style=filled, fillcolor=\"%s\", fontcolor=\"%s\", fontsize=12, shape=doublecircle, fontname=\"Comic Sans MS\"];\n", R->left->data, R->left->color == true ? "black" : "white", R->left->color == true ? "black" : "white", R->left->color == true ? "white" : "black");
            fprintf(f, "\t\"%d %s\" -> \"%d %s\";\n", R->data, R->color == true ? "black" : "white", R->left->data, R->left->color == true ? "black" : "white");
        }
        else
        {
            fprintf(f, "\t\"NIL%d\" [style=invis];\n", *nbNil);
            fprintf(f, "\t\"%d %s\" -> \"NIL%d\" [style=invis];\n", R->data, R->color == true ? "black" : "white", (*nbNil)++);
        }

        // Dessiner un fils NIL virtuel et invisible au milieu (pour une meilleure s�paration des fils gauches et droits)
        fprintf(f, "  \"NIL%d\" [style=invis];\n", *nbNil);
        fprintf(f, "  \"%d %s\" -> \"NIL%d\" [style=invis];\n", R->data, R->color == true ? "black" : "white",(*nbNil)++);

        // Dessiner un arc vers le fils droit
        if (R->right != NULL) {
            fprintf(f, "\t\"%d %s\" [style=filled, fillcolor=\"%s\", fontcolor=\"%s\", fontsize=12, shape=doublecircle, fontname=\"Comic Sans MS\"];\n", R->right->data, R->right->color == true ? "black" : "white", R->right->color == true ? "black" : "white", R->right->color == true ? "white" : "black");
            fprintf(f, "\t\"%d %s\" -> \"%d %s\";\n", R->data, R->color == true ? "black" : "white", R->right->data, R->right->color == true ? "black" : "white");
        }
        else
        {
            fprintf(f, "\"NIL%d\" [style=invis];\n", *nbNil);
            fprintf(f, "\"%d %s\" -> \"NIL%d\" [style=invis];\n", R->data, R->color == true ? "black" : "white", (*nbNil)++);
        }

        // Dessiner les sous-arbres gauche et droit
        draw_tree_dot(R->left, f, nbNil);
        draw_tree_dot(R->right, f, nbNil);
    }
}



void draw(Node* root)
{

    int nbNil;
    FILE *f;

    if (root == NULL)
        printf("> ERREUR : Arbre vide !");
    else
    {
        f = fopen("../out/out.dot", "w");

        fprintf(f, "digraph arbre {\n");

        fprintf(f, "\tordering = out;\n");
        fprintf(f, "\tsplines = false;\n");

        nbNil = 0;
        draw_tree_dot(root, f, &nbNil);

        fprintf(f, "}\n");
        fclose(f);
    
    }
}
