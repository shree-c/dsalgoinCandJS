#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX 100
#define LL 1
#define HL 200
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;
node *add_node(int data)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    return temp;
}
node *ins(node *n, int data)
{
    if (n == NULL)
    {
        n = add_node(data);
    }
    else
    {
        if (data < n->data)
            n->left = ins(n->left, data);
        else
            n->right = ins(n->right, data);
    }
    return n;
}

void in_s(node **n, int data)
{
    if (*n == NULL)
    {
        *n = add_node(data);
    }
    else
    {
        if (data < (*n)->data)
            in_s(&((*n)->left), data);
        else
            in_s(&((*n)->right), data);
    }
}
void in_traversal(node *r)
{
    if (r == NULL)
    {
        return;
    }
    else
    {
        in_traversal(r->left);
        printf("%d\n", r->data);
        in_traversal(r->right);
    }
}
int main()
{
    srand(time(0));
    int arr[MAX];
    node *root = NULL;
    for (int i = 0; i < MAX; i++)
        in_s(&root, (rand() % HL) + LL);
    in_traversal(root);
    return 0;
}
