#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
};
struct Node *root = NULL, *temp = NULL;

struct Node *newNode(int key)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->key = key;
    node->left = node->right = NULL;
    return (node);
}

void inorder(struct Node *root)
{
    int count=0;
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}
int countLeafNodes(struct Node* root) {
    if (root == NULL) // If the tree is empty
        return 0;
    else if (root->left == NULL && root->right == NULL) // If the node is a leaf node
        return 1;
    else // Recursively count leaf nodes in left and right subtrees
        return countLeafNodes(root->left) + countLeafNodes(root->right);
}

void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->key);
    }
}

int minimum(struct Node *root)
{
    if (root == NULL)
        return 0;
    else
    {
        while (root->left != NULL)
        {
            root = root->left;
        }
        return root->key;
    }
}
int tree_height(struct Node *root) {
    // Get the height of the tree
    if (!root)
        return 0;
    else {
        int left_height = tree_height(root->left);
        int right_height = tree_height(root->right);
        if (left_height >= right_height)
            return left_height + 1;
        else
            return right_height + 1;
    }
}

void print_level(struct Node *root, int level_no) {
    if (!root)
        return;
    if (level_no == 0) {
        printf("%d -> ", root->key);
    }
    else {
        print_level(root->left, level_no - 1);
        print_level(root->right, level_no - 1);
    }

}

void print_tree_level_order(struct Node* root) {
    if (!root)
        return;
    int height = tree_height(root);
    for (int i=0; i<height; i++) {
        printf("Level %d: ", i);
        print_level(root, i);
        printf("\n");
    }
    printf("\n\n-----Complete Level Order Traversal:-----\n");
    for (int i=0; i<height; i++) {
        print_level(root, i);
    }
    printf("\n");
}
struct Node *insert(struct Node *node, int key)
{
    if (node == NULL)
        return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    return node;
}

void deleteNode(struct Node *root, int key)
{
    if (root == NULL)
        return;
    if (key < root->key)
        deleteNode((root->left), key);
    else if (key > root->key)
        deleteNode((root->right), key);
    else
    {
        if (root->left == NULL)
        {
            struct Node *temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root;
            root = root->left;
            free(temp);
        }
        else
        {
            int minKey = minimum(root->right);
            root->key = minKey;
            deleteNode((root->right), minKey);
        }
    }
}

void main()
{
    int ch, key;
    int count ;
    printf("1.Insert\n2.Inorder\n3.Preorder\n4.Postorder\n5.Delete\n6.Exit\n");
    while (1)
    {
        printf("Enter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the key:");
            scanf("%d", &key);
            root = insert(root, key);
            break;
        case 2:
            printf("Inorder: ");
            inorder(root);
            printf("\n");
            break;
        case 3:
            printf("Preorder: ");
            preorder(root);
            printf("\n");
            break;
        case 4:
            printf("Postorder: ");
            postorder(root);
            printf("\n");
            break;
        case 5:
            printf("Enter the key to delete: ");
            scanf("%d", &key);
            deleteNode(root, key);
            break;
        case 6:
            
            print_tree_level_order(root);
        }
    }
}
