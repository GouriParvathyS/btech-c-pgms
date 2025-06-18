#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}Node;
Node *top=NULL;
Node *create(int data)
{
    Node *newnode=(Node *)malloc(sizeof(Node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}
void push(int data)
{
    Node *newnode=create(data);
    if (top==NULL)
    {
        top=newnode;
    }
    else{
        newnode->next=top;
        top=newnode;
    }

}
void pop()
{
    if (top==NULL)
    {
        printf("Empty");
    }
    else{
        printf("The deleted element is %d\n",top->data);
        top=top->next;
    }
}
void display(){
    Node *temp=top;
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
}
void main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    display();
    pop();
    display();


}