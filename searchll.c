#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}Node;
Node *head=NULL;
Node *rear=NULL;

Node *create(int data)
{
    Node *newnode=(Node *)malloc(sizeof(Node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}
void insert_end(int data)
{
    Node *new_node = create(data);
    if (head == NULL)
    {
        head = new_node;
        rear = new_node;
    }
    else
    {
        rear->next = new_node;
        rear = rear->next;
    }
}
void search(int data)
{
    int c=0,f=0;
    Node *temp=head;
    while(temp!=NULL)
    {
        c++;
        if (temp->data==data)
        {
            printf("The element is present at %d",c);
            f++;
        }
        temp=temp->next;
    }
    if (f==0)
    {
        printf("Element absent");
    }
}
void main()
{
    insert_end(1);    
    insert_end(2);    
    insert_end(3);    
    insert_end(4);
    search(2);   
}