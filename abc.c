#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node  *next;
    struct node *prev;
}nd;
nd *front=NULL;;
nd *rear=NULL;

nd *temp;

void insertatF()
{
    int x;
    nd *newnode=malloc(sizeof(nd));
    newnode->next=NULL;
    printf("enter the data:-");
    scanf("%d",&x);
    newnode->data=x;
    if (front==NULL)
    {
        front=newnode;
        rear=newnode;
        newnode->next=newnode;
        newnode->prev=newnode;
    }
    else
    {
        
        newnode->next=front;
        front->prev=newnode;
        newnode->prev=rear;
        rear->next=newnode;
        front=newnode;
    }
}
void insertatEnd()
{
    int x;
    nd *newnode=malloc(sizeof(nd));
    newnode->next=NULL;
    printf("enter the data:-");
    scanf("%d",&x);
    newnode->data=x;
    if (front==NULL)
    {
        front=newnode;
        rear=newnode;
        newnode->next=newnode;
        newnode->prev=newnode;
    }
    else
    {
        newnode->prev=rear;
        rear->next=newnode;
        newnode->next=front;
        front->prev=newnode;
        rear=newnode;
    }
}
void display()
{
    temp=front;
    if(front==NULL)
    printf("List is empty");
    else{
    while(temp!=rear)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
    printf("%d\n",temp->data);}

} 
void deleteF()
{
    if(front==NULL)
    {
        printf("EMPTY");
    }
    else{
        temp=front;
        front=front->next;
        front->prev=rear;
        rear->next=front;
        free(temp);
    }
}
void deleteEnd()
{
    {
    if(front==NULL)
    {
        printf("EMPTY");
    }
    else{
        temp=rear;
        rear=rear->prev;
        rear->next=front;
        front->prev=rear;
        free(temp);
    }
}
}
void main(){
insertatF();
insertatF();
insertatF();
display();
deleteF();
display();
deleteEnd();
display();}