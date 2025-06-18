#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node;
struct node *head=NULL;
void insert_E(int data)
{
    struct node *newnode=(node *)malloc(sizeof(node));
    newnode->data=data;
    newnode->next=NULL;
    if ( head==NULL){
        head=newnode;
    }
    else{
        struct node *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
}
void display(){
    if ( head==NULL){
        printf("Empty\n");
    }
    else{
        struct node *temp=head;
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
}}
void removeduplicate()
{
    struct node *temp=head;
    struct node *temp1=NULL;
    while(temp!=NULL)
    {
        int a=temp->data;
        temp1=temp->next;
        struct node *prev=temp;
        while(temp1!=NULL)
        {
            if (a==temp1->data)
            {
                prev->next=temp1->next;
            }
            prev=temp1;
            temp1=temp1->next;
        }
        temp=temp->next;
    }
}
void main()
{
    insert_E(10);
    insert_E(20);
    insert_E(30);
    insert_E(10);
    insert_E(40);
    insert_E(20);
    display();
    removeduplicate();
    display();
}