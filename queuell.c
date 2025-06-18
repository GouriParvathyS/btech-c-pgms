#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}Node;
Node *front=NULL;
Node *rear=NULL;
Node *create(int data)
{
    Node *newnode=(Node *)malloc(sizeof(Node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}
void Enqueue(int data)
{
    Node* newnode=create(data);
    if (front==NULL)
    {
        front=newnode;
        rear=newnode;
    }
    else{
        rear->next=newnode;
        rear=newnode;
    }
}
void Dequeue()
{
    if (front==NULL)
    {
        printf("Empty");
    }
    else{
        printf("deleted element is %d\n",front->data);
        if (front==rear)
        {
            front=NULL;
            rear=NULL;
        }
        else{
            front=front->next;
        }
    }
}
void display()
{
    Node *temp=front;
    if (front==NULL)
    {
        printf("Empty");
    }
    else{
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
    printf("\n");
    }
}
void main(){
    Enqueue(1);
    Enqueue(2);
    Enqueue(3);
    Enqueue(4);
    Enqueue(5);
    display();
    Dequeue();
    display();
    Dequeue();
    display();
    Dequeue();
    display();
    Dequeue();
    display();
    Dequeue();
    display();
}