#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
    return;
}
struct node *create_node(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
struct node *insert(struct node *root, int data)
{
    struct node *newnode = create_node(data);
    if (root == NULL)
    {
        root = newnode;
        return root;
    }
    if (root->data > data)
    {
        root->left = insert(root->left, data);
        return root;
    }
    root->right = insert(root->right, data);
    return root;
}
struct node *delete(struct node *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data > data)
    {
        root->left = delete (root->left, data);
        return root;
    }
    else if (root->data < data)
    {
        root->right = delete (root->right, data);
        return root;
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            root->left = NULL;
            free(root);
            return temp;
        }
        else if (root->left == NULL)
        {
            struct node *temp = root->right;
            root->right = NULL;
            free(root);
            return temp;
        }
        else
        {
            struct node *inordersucessor = root->right;
            while (inordersucessor->left != NULL)
            {
                inordersucessor = inordersucessor->left;
            }
            int i = inordersucessor->data;
            int t = root->data;
            root->data = i;
            inordersucessor->data = t;
            root->right = delete (root->right, t);
            return root;
        }
    }
}
int main()
{

    int d, n;
    struct node *root = NULL;
    printf("enter the no of elements in tree\n");
    scanf("%d", &n);
    printf("enter data for tree\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &d);
        root = insert(root, d);
    }
    inorder(root);
    printf("\nenter the element you want to delete in your binary search tree\n");
    scanf("%d", &d);
    root = delete (root, d);
    inorder(root);
    return 0;
}