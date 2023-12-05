
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct r
{
    struct r *left, *right;
    char name[20 + 1]; // neve
    double w;          // vizhozama
} *river_tree;

void fill(river_tree root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL) )
        return;

    fill(root->left);
    fill(root->right);

     if (root->left != NULL && root->right != NULL)
    {
        if (root->left->w > root->right->w)
        {
            strcpy(root->name, root->left->name);
            root->w = root->left->w + root->right->w;
        }
        else
        {
            strcpy(root->name, root->right->name);
            root->w = root->left->w + root->right->w;
        }
    }
    else if (root->left != NULL)
    {
        strcpy(root->name, root->left->name);
        root->w = root->left->w;
    }
    else if (root->right != NULL)
    {
        strcpy(root->name, root->left->name);
        root->w = root->right->w;
    }

}
