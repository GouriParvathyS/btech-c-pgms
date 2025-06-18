#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
}
node;
struct node *head;
struct node *tail;
node *create(int data)
{
    struct node *newnode=(node *)malloc(sizeof(node));
    newnode->data=data;
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}
void insert_E(int data){
    struct node *newnode=create(data);
    if (head==NULL)
    {
        head=newnode;
        tail=newnode;
    }
    else{
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }
}
void display()
{
    node *temp = head;
    if (head == NULL)
    {
        printf("No elements in sll\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
void isPali(){
    if(head==NULL)
    {
        printf("Empty");
    }
    else{
        int flag;
        struct node *temp1 =head;
        struct node *temp2 =tail;
        while(temp1!=NULL  &&  temp2!=NULL)
        {
            if(temp1->next!=temp2){
            flag=0;
            if (temp1->data==temp2->data)
            {   flag=1;
            } 
            else{
                break;
            }
            temp1=temp1->next;
            temp2=temp2->prev;
        }
        else{
            break;
        }}
        if (flag==1)
        {
            printf("Palindrome.");
        }
        else{
            printf("Not a palindrome");
        }
    }
}
void main(){
    insert_E(1);
    insert_E(2);
    insert_E(3);
    insert_E(2);
    insert_E(1);
    display();
    isPali();
}