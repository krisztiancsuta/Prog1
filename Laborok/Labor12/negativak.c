
#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    double data;
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
int negatives(node *root)
{
    if (root == NULL)
        return 0;
    uint32_t cnt = 0;
    if (root->left != NULL && root->left->data < 0)
        cnt++;
    if (root->right != NULL && root->right->data < 0)
        cnt++;

    return cnt + negatives(root->left) + negatives(root->right);
}

node *find(node *root, double data)
{
    while (root != NULL && data != root->data)
    {
        if (data < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return root;
}
/*
void insert(node **root, double a)
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
                p->right = new_elem(a);
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
*/
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

void printTree(node *root, int space)
{
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
    printf("%f\n", root->data);

    // Process left child
    printTree(root->left, space);
}
// DFS
void inorder(node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%2f\n", root->data);
    inorder(root->right);
}

// BFS
void preorder(node *root)
{
    if (root == NULL)
        return;
    printf("%f\n", root->data);
    preorder(root->left);
    preorder(root->right);
}
int negatives2(node *root)
{
    int cnt = 0;
    if (root == NULL)
        return 0;
    if (root->data < 0)
        cnt++;
    return cnt + negatives2(root->left) + negatives2(root->right);
    ;
}

node *insert(node *root, double data)
{

    if (root == NULL)
    {
        root = (node *)calloc(1, sizeof(node));
        root->data = data;
    }
    else if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

void insert2(node **root, double data)
{
     
    if (*root == NULL)
    {
        *root = (node *)calloc(1, sizeof(node));
        (*root)->data = data;
    }
    else if (data < (*root)->data)
        (*root)->left = insert((*root)->left, data);
    else
        (*root)->right = insert((*root)->right, data);
}

int main()
{

    node *root = NULL;
/*
    root = insert(root, 42);
    root = insert(root, 25);
    root = insert(root, 42);
    root = insert(root, 25);
    root = insert(root, 42);
    root = insert(root, 25);
    root = insert(root, 42);
    root = insert(root, 25);
*/
    printf("%p\n",&root);
    insert2(&root,31);
     printf("%p\n",&root);
    printf("%p\n",root);
    insert2(&root,32);
     printf("%p\n",&root);
    printf("%p\n",root);
    insert2(&root,48);
     printf("%p\n",&root);
    printf("%p\n",root);
    insert2(&root,23);
     printf("%p\n",&root);
    printf("%p\n",root);
    
    printf("DFS ---------------------\n");
    inorder(root);
    printf("BFS ---------------------\n");
    preorder(root);
    printf("%d\n", negatives(root));
    printf("%d\n", negatives2(root));

    printf("Fa elemei inorder bejárással: ");
    printTree(root, 0);
    printf("\n");

    node *elem = find(root, -3);
    if (elem == NULL)
        printf("Nincs talalat");
    else
        printf("%f", elem->data);

    freeTree(root);
    return 0;
}