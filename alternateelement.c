#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node;
struct node *head=NULL;
struct node *head2=NULL;
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
void displaya(struct node*head){
    if ( head==NULL){
        printf("Empty\n");
    }
    else{
        struct node *temp=head;
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
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
void max()
{
    int max=0;
    int min;
    if ( head==NULL){
        printf("Empty\n");
    }
    else{
        struct node *temp=head;
        min=temp->data;
        while(temp!=NULL)
        {
            if (temp->data > max)
            {
                max=temp->data;
            }
            if (temp->data <min)
            {
                max=temp->data;
            }
            temp=temp->next;
            
        }
        printf("%d is the max",max);
        printf("%d is the min",min);
    }
}
void copy()
{
 if ( head==NULL){
        printf("Empty\n");
    }
    else{
        struct node *temp=head;
        while(temp!=NULL)
        {
            if ( head==NULL){
                head=temp;
            }
            else{
                struct node *ptr=head;
                while(ptr->next!=NULL)
                {
                    ptr=ptr->next;
                }
                ptr->next=temp;
                }
        }
}}
void difference(){
    int a,b;
    printf("Enter the index of the minuend:-");
    scanf("%d",&a);
    printf("Enter the index of the subtrahend:-");
    scanf("%d",&b);
    struct node*temp=head;
    int count=0;
    while(temp!=NULL && count!=a)
    {
        count++;
        temp=temp->next;
    }
    if (temp == NULL) {
        printf("Index %d out of range.\n", a);
        }
    int m=temp->data;
    temp=head;
    count=0;
    while(temp!=NULL && count!=b)
    {
        count++;
        temp=temp->next;
    }
    if (temp == NULL) {
        printf("Index %d out of range.\n", a);
        }
    int n=temp->data;
    int dif=m-n;
    printf("%d",dif);
}
void main()
{
    insert_E(10);
    insert_E(20);
    insert_E(30);
    insert_E(10);
    insert_E(40);
    insert_E(20);
    display(head);
    difference();
}