#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}Node;
Node *head=NULL;
Node *tail=NULL;
Node *create(int data)
{
    Node *newnode=(Node *)malloc(sizeof(Node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}
void insert_f(int data){
    Node *newnode=create(data);
    if (head==NULL)
    {
        head=newnode;
        tail=newnode;
    }
    else{
        newnode->next=head;
        head=newnode;
    }
}
void delete_f(){
    Node *temp=head;
    if (head==NULL)
    {
        printf("Empty");
    }
    else{
        printf("the deleted element is %d",head->data);
        if(head->next==NULL)
        {
            head=NULL;
            tail=NULL;
        }
        else{
            head=head->next;
        }
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
        tail=newnode;
    }
}
void delete_E(){
    Node*prev=NULL;
    Node *temp=head;
    if (head==NULL)
    {
        printf("Empty");
    }
    else{
        
        while(temp->next!=NULL)
        {
            prev=temp;
            temp=temp->next;
        }
        printf("the deleted element is %d",temp->data);
        prev->next=NULL;
        tail=prev;
    }
}
void insert_atP(int data,int pos){
    Node *newnode=create(data);
    Node *temp=head;
    Node *prev;
    
    if (pos==1)
    {
        insert_f(data);
    }
    else{
        int count=1;
        while(temp!=NULL && pos!=count )
        {
            
            prev=temp;
            temp=temp->next;
            count++;
        }
        if(pos==count)
        {
            newnode->next=temp;
            prev->next=newnode;
        }
        else if(temp==NULL)
        {
            printf("Element absent");
        }
    }
}
void delete_atP(int pos){
    Node *temp=head;
    Node *prev;
    
    if (pos==1)
    {
        delete_f();
    }
    else{
        int count=1;
        while(temp!=NULL && pos!=count )
        {
            
            prev=temp;
            temp=temp->next;
            count++;
        }
        if(pos==count)
        {
            printf("%d",temp->data);
            prev->next=temp->next;
        }
        else if(temp==NULL)
        {
            printf("Element absent");
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
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void main()
{
    printf("Enter\n1 to insert elements at end\n2 to insert elements at front\n3 to insert elements at a position\n4 to delete elements from front\n5 to delete elements from end\n6 to delete elements before given element\n7 to display sll\n");
    int op;
    char ch = 'y';
    int data;
    int pos1;
    while (ch == 'y')
    {
        printf("Enter options from 1 to 7\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("Enter:-");
            scanf("%d",&data);
            insert_E(data);
            break;
            
        case 2:
            printf("Enter:-");
            scanf("%d",&data);
            insert_f(data);
            break;
        case 3:
            printf("Enter:-");
            scanf("%d",&data);
            printf("Enter:-");
            int pos;
            scanf("%d",&pos);
            insert_atP(data,pos);
            break;
        case 4:
            display();
            break;
        case 5:
            delete_f();
            break;
        case 6:
            delete_E();
            break;
        case 7:
            printf("Enter:-");
            scanf("%d",&pos1);
            delete_atP(pos1);
            break;
        }
        printf("WISH TO CONTINUE\n");
        scanf(" %c",&ch);
}
}