#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *next;    
    struct node *prev;    
}Node;
Node *head=NULL;
Node *tail=NULL;
Node *create(int data)
{
    Node *newnode=(Node *)malloc(sizeof(Node));
    newnode->data=data;
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}
void insert_f(int data){
    Node *newnode=create(data);
    if (head==NULL)
    {
        head=newnode;
        tail=newnode;
        head->next=tail;
        head->prev=tail;
        tail->next=head;
        tail->prev=head;
    }
    else{
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
        tail->next=head;
        head->prev=tail;
    }
}
void insert_E(int data){
    Node *newnode=create(data);
    if (head==NULL)
    {
        head=newnode;
        tail=newnode;
    }
    else{
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
        head->prev=tail;
        tail->next=head;
    }
}
void delete_E(){
    Node *temp=head;
    if (head==NULL)
    {
        printf("Empty");
    }
    else{
        if(tail->next==head)
        {
            printf("The deleted element is %d",tail->data);
            head=NULL;
            tail=NULL;
        }
        else{
            Node* ptr=tail->prev;
            printf("The deleted element is %d",ptr->data);
            ptr->next=head;
            head->prev=ptr;
            tail=ptr;
        }
    }
}
void display()
{
    Node *temp = head;
    if (head == NULL)
    {
        printf("No elements in sll\n");
    }
    else
    {
        while (temp->next!=tail)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        temp = temp->next;
        printf("%d ", temp->data);
        printf("\n");
    }
}
void main(){
    insert_E(1);
    display();
    insert_E(2);
    display();
    insert_E(3);
    display();
    insert_E(4);
    display();
    insert_E(5);
    delete_E();
    display();
    delete_E();
}
