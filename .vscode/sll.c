#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node  *next;
}nd;
struct node *head;
struct node *temp;
void insertionF()
{
    nd *newnode=malloc(sizeof(nd));
    newnode->next=NULL;
    printf("Enter the data:-");
    scanf("%d",&newnode->data);
    if (head==NULL)
    {
        head=newnode;
        temp=newnode;
    }
    else{
        temp->next=newnode;
    }
}
void insertionE()
{
    nd *newnode=malloc(sizeof(nd));
    newnode->next=NULL;
    printf("Enter the data:-");
    scanf("%d",&newnode->data);
    if (head==NULL)
    {
        head=newnode;
    }
    else{
        newnode->next=temp;
        head=newnode;
    }
}
void DeleteF()
{
    if (head==NULL)
    {
        printf("List is empty.");
    }
    else{
        struct node *temp=head;
        printf("The deleted element is %d\n",head->data);
        head=head->next;
    }
}
void DeleteE()
{
    if (head==NULL)
    {
        printf("List is empty.");
    }
    else{
        struct node *temp=head;
        printf("The deleted element is %d\n",head->data);
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=NULL;
    }
}
void display()
{
    struct node *temp=head;
    while(temp->next!=NULL)
        {
            printf("%d",temp->data);
            temp=temp->next;
            
        }
        printf("\n");
}
void main(){
    int p=0;
    while(p==0)
    {
        int c;
        printf("1.IF\n2.IE\n3.DF\n4.DE\n5.D\n6.Exit\n");
        scanf("%d",&c);
        switch(c)
        {
             case 1:
                insertionF();
                break;
            case 2:
                insertionE();
                break;
            case 3:
                DeleteF();
                break;
            case 4:
                DeleteE();
                break;
            case 5:
                display();
                break;
            case 6:
                p=1;
                break;
        }
    }
}