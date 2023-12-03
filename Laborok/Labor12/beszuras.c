#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int data;
    struct _node *left;
    struct _node *right;
} node;

node *new_elem(int a)
{
    node *new = (node *)malloc(sizeof(node));
    new->data = a;
    new->left = NULL;
    new->right = NULL;
    return new;
}

void insert(node **root, int a)
{
    if (*root == NULL)
    {
        *root = new_elem(a);
    }
    node *p = *root;
    while (1)
    {
        if (a < p->data)
        {
            if (p->left == NULL)
            {
                p->left = new_elem(a);
            }
            else
            {
                p = p->left;
            }
        }
        else if (a > p->data)
        {
            if (p->right == NULL)
            {
                p->right =new_elem(a);
            }
            else
            {
                p = p->right;
            }
        }
        else
        {
            return;
        }
    }
}


void freeTree(node *root)
{
    if (root == NULL)
    {
        return;
    }

    freeTree(root->left);
    freeTree(root->right);

    free(root);
}
char indent[1000];

void printTree(node* root, int space) {
    int i;

    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += 10;

    // Process right child first
    printTree(root->right, space);

    // Print current node after space count
    printf("\n");
    for (i = 10; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);

    // Process left child
    printTree(root->left, space);
}
int main()
{
    node *root = NULL;

    // Beszúrás példája:
  
    insert(&root, 5);
    insert(&root, 3);
    insert(&root, 7);
    insert(&root, 2);
    insert(&root, 4);
    insert(&root, 6);
    insert(&root, 8);
    
    // A fa elemeinek kiíratása (inorder bejárással):
    printf("Fa elemei inorder bejárással: ");
    printTree(root,0);
    printf("\n");

    // Ne felejtsd el felszabadítani a fa memóriáját, amikor már nincs rá szükség!
    freeTree(root);

    return 0;
}