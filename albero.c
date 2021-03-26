#include <stdio.h>
#include <stdlib.h>


struct tree_node{
    struct tree_node *left;
    struct tree_node *right;
    int valore;
    int key;
};

void in_order_view(struct tree_node * tree)
{
    if(tree != NULL)
    {
        in_order_view(tree->left);
        printf("key %d, value %d\n", tree->key, tree->valore);
        in_order_view(tree->right);
    }
}

void insert(struct tree_node **tree, struct tree_node *new)
{
    if(*tree == NULL)
    {
        *tree = new;
        (*tree)->left = NULL;
        (*tree)->right = NULL;
    }
    else
    {
        if(new->key < (*tree)->key)
        {
            insert(&(*tree)->left, new);
        }else if(new->key > (*tree)->key)
        {
            insert(&(*tree)->right, new);
        }else{
            printf("chiave dublicata\n");
        }
    }
}

int main()
{
    struct tree_node *tree = NULL;

    char scelta = 'y';
    int valore = 0;

    while (scelta == 'y')
    {
        struct tree_node *elemento = (struct tree_node*) malloc(sizeof(struct tree_node));
        printf("inserire valore: ");+
        scanf("%d", &valore);
        elemento->key = valore;
        elemento->valore = valore;
        
        insert(&tree, elemento);

        printf("si vuole inserire altro? ");
        fflush(stdin);
        scelta = getchar();
    }
    
    in_order_view(tree);


}