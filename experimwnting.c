#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} nd;
nd *head = NULL;
nd *rear = NULL;
int data;
nd *create_new_node(int data)
{
    nd *new_node = (nd *)malloc(sizeof(nd));
    new_node->data=data;
    new_node->next = NULL;
    return new_node;
}
void insert_end()
{
    
    printf("Enter node data\n");
    scanf("%d", &data);
    nd *new_node = create_new_node(data);
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
void insert_front()
{
    printf("Enter node data\n");
    scanf("%d", &data);
    nd *new_node = create_new_node(data);
    if (head == NULL)
    {
        head = new_node;
        rear = new_node;
    }
    else
    {
        new_node->next = head;
        head = new_node;
    }
}
void insert_position()
{
    printf("Enter node data\n");
    scanf("%d", &data);
    nd*new_node = create_new_node(data);
    int pos;
    printf("Enter the position (not index) at which to insert\n");
    scanf("%d", &pos);
    if (pos == 1)
    {
        if (head == NULL)
        {
            head = new_node;
            rear = new_node;
        }
        else
        {
            new_node->next = head;
            head = new_node;
        }
    }
    else
    {
        int cnt = 1;
        nd *temp = head;
        nd *prev;
        while (cnt != pos && temp != NULL)
        {
            prev = temp;
            temp = temp->next;
            cnt++;
        }
        if (cnt == pos)
        {
            new_node->next = prev->next;
            prev->next = new_node;
        }
        else if (temp == NULL)
        {
            printf("Position invalid\n");
        }
    }
}
void delete_front()
{
    if (head == NULL)
    {
        printf("Empty\n");
    }
    else
    {
        nd *d = head;
        if (head == rear)
        {
            rear = NULL;
        }
        head = head->next;
        printf("Deleting %d\n", d->data);
        free(d);
    }
}
void delete_end()
{
    if (head == NULL)
    {
        printf("Empty\n");
    }
    else
    {
        nd *d = rear;
        if (head == rear)
        {
            head = NULL;
            rear = NULL;
        }
        else
        {
            nd *temp = head;
            while (temp->next != rear)
            {
                temp = temp->next;
            }
            temp->next = NULL;
            rear = temp;
        }
        printf("Deleting %d\n", d->data);
        free(d);
    }
}
void delete_position()
{
    int pos;
    printf("Enter position at which to delete\n");
    scanf("%d", &pos);
    nd *temp = head;
    nd *prev;
    int cnt = 1;
    if (head == NULL)
    {
        printf("Empty\n");
        return;
    }
    if (pos == 1)
    {
        delete_front();
    }
    else
    {
        while (cnt != pos && temp != NULL)
        {
            prev = temp;
            temp = temp->next;
            cnt++;
        }
        if (cnt == pos)
        {
            prev->next = temp->next;
        }
        else if (temp == NULL)
        {
            printf("Invalid\n");
        }
    }
}
void display()
{
    nd *temp = head;
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
void reverse()
{
    nd *temp=head;
    int stack[10];
    int top=-1;
    nd *head2=NULL;
    while(temp!=NULL)
    {
        stack[++top]=temp->data;
        temp=temp->next;
    }
    for(int i=top;i>=0;i--){
        printf("%d\n",stack[i]);
        nd *newnode=create_new_node(stack[i]);
        if (head2 == NULL)
        {
            head2=newnode;
        }
        else{
            nd *temp1=head2;
            while(temp1->next!=NULL)
            {
                temp1=temp1->next;
            }
            temp1->next=newnode;
        }
    }
    nd *temp2=head2;
    printf("After");
    while(temp2!=NULL)
    {
        printf("\n%d",temp2->data);
        temp2=temp2->next;
    }
    head=head2;
}
void sort(){
    
}
void main()
{
    
    insert_end();
    insert_end();
    insert_end();
    insert_end();
    insert_end();
    display();
    reverse();
    display();
    }
