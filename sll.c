#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} nd;
nd *head = NULL;
nd *rear = NULL;
nd *create_new_node()
{
    nd *new_node = (nd *)malloc(sizeof(nd));
    printf("Enter node data\n");
    scanf("%d", &new_node->data);
    new_node->next = NULL;
    return new_node;
}
void insert_end()
{
    nd *new_node = create_new_node();
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
    nd *new_node = create_new_node();
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
    nd *new_node = create_new_node();
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
void main()
{
    printf("Enter\n1 to insert elements at end\n2 to insert elements at front\n3 to insert elements at a position\n4 to delete elements from front\n5 to delete elements from end\n6 to delete elements before given element\n7 to display sll\n");
    int op;
    char ch = 'y';
    while (ch == 'y')
    {
        printf("Enter options from 1 to 7\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            insert_end();
            break;
        case 2:
            insert_front();
            break;
        case 3:
            insert_position();
            break;
        case 4:
            delete_front();
            break;
        case 5:
            delete_end();
            break;
        case 6:
            delete_position();
            break;
        case 7:
            display();
            break;
        default:
            printf("Invalid choice\n");
        }
        printf("Continue\n");
        scanf(" %c", &ch);
    }
}

