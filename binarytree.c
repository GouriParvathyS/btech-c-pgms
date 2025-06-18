
#include <stdio.h>
int complete_node = 15;

// array to store the tree
char tree[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', '\0', '\0', 'J', '\0', 'K', 'L'};
int get_right_child(int index1)
{
// node is not null
// and the result must lie within the number of nodes for a complete binary tree
if(tree[index1]!='\0' && ((2*index1)+2)<=complete_node)
    return (2*index1)+2;
// right child doesn't exist
return -1;
}

int get_left_child(int index1)
{
// node is not null
// and the result must lie within the number of nodes for a complete binary tree
if(tree[index1]!='\0' && (2*index1+1)<=complete_node)
return 2*index1+1;
// left child doesn't exist
return -1;
}

void preorder(int index1)
{
// checking for valid index1 and null node
if(index1>=0 && tree[index1]!='\0')
{
printf(" %c ",tree[index1]); // visiting root
preorder(get_left_child(index1)); //visiting left subtree
preorder(get_right_child(index1)); //visiting right subtree
}
}

void postorder(int index1)
{
// checking for valid index1 and null node
if(index1>=0 && tree[index1]!='\0')
{
postorder(get_left_child(index1)); //visiting left subtree
postorder(get_right_child(index1)); //visiting right subtree
printf(" %c ",tree[index1]); //visiting root
}
}

void inorder(int index1)
{
// checking for valid index1 and null node
if(index1>=0 && tree[index1]!='\0')
{
inorder(get_left_child(index1)); //visiting left subtree
printf(" %c ",tree[index1]); //visiting root
inorder(get_right_child(index1)); // visiting right subtree
}
}

int main()
{
printf("Preorder:\n");
preorder(0);
printf("\nPostorder:\n");
postorder(0);
printf("\nInorder:\n");
inorder(0);
printf("\n");
return 0;
}/*
int complete_node;
int index1=0;
int tree[9]={-1,-1,-1,-1,-1,-1,-1,-1,-1};
int get_rightnode(int index1)
{
    if (tree[index1]!=-1 && ((2*index1)+2)<=complete_node)
{
    return 2*index1+2;
}return -1;
}
int get_leftnode(int index1)
{
    if (tree[index1]!=-1 && ((2*index1)+1)<=complete_node)
{
    return 2*index1+1;
}return -1;
}
void insert(int value,int index1){
    if (index1==-1 || tree[index1]==-1)
    {
        tree[index1]=value;
    }
    if (value<tree[index1])
    {
        
        index1=get_leftnode(index1);
        insert(value,index1);
    }
    else{
        index1=get_rightnode(index1);
        insert(value,index1);
    }
}
void preorder(int index1)
{{
    if (index1>=0 && tree[index1]!=-1){
    printf("%d",tree[index1]);
    preorder(get_leftnode(index1));
    preorder(get_rightnode(index1));}}
}
void inorder(int index1)
{{
    if (index1>=0 && tree[index1]!=-1){
    inorder(get_leftnode(index1));
    printf("%d",tree[index1]);
    inorder(get_rightnode(index1));}}
}
void postorder(int index1)
{
    if (index1>=0 && tree[index1]!=-1){{
    postorder(get_leftnode(index1));
    postorder(get_rightnode(index1));
    printf("%d",tree[index1]);}}
}
void main(){
    
    insert(10,0);
    insert(30,0);
    insert(20,0);
    insert(40,0);
    insert(50,0);
    complete_node=5;
    preorder(0);
    printf("\n");
    inorder(0);
    printf("\n");
    postorder(0);
}*/