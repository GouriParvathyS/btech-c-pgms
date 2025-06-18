#include <stdio.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
}node;
node *root=NULL;
node *create(int data)
{
    struct node *newnode = (node *)malloc(sizeof(node));
    newnode->data=data;
    newnode->left=newnode->right=NULL;
    return (newnode);
}
void insert(node *root,int value)
{
    if (root==NULL){
        root=create(value);
    }
    if(value<root->data)
    {
        root->left=insert(root->left,value);
    }
    else{
        root->right=insert(root->right,value);
    }
}
int minimum(node *root)
{
    if (root==NULL)
    {
        return 0;
    }
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root->key;
}
void preorder(node *root)
{
    if(root!=NULL)
    {
    printf("%d",root->data);
    preorder(root->left);
    preorder(root->right);
    }
}
void inorder(node *root)
{
    if(root!=NULL)
    {
    inorder(root->left);
    printf("%d",root->data);
    inorder(root->right);
    }
}
void postorder(node *root)
{
    if(root!=NULL)
    {
    postorder(root->left);
    postorder(root->right);
    printf("%d",root->data);
    }
}
void delete(node **root,int value)
{
    if ((*root)==NULL)
    {
        printf("No elements");
    }
    if ((*root)->data<value)
    {
        delete(&((*root)->left),value);
    }
    else if ((*root)->data>value){
        delete(&((*root)->right),value);
    }
    else{
            if ((*root)->left == NULL)
        {
            struct Node *temp = *root;
            *root = (*root)->right;
            free(temp);
        }
        else if ((*root)->right == NULL)
        {
            struct Node *temp = *root;
            *root = (*root)->left;
            free(temp);
        }
        else
        {
            int minKey = minimum((*root)->right);
            (*root)->data = minKey;
            deleteNode(&((*root)->right), minKey);
        }
    }
}