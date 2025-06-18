#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} nd;

nd *front = NULL, *rear = NULL, *top = NULL;

nd *createNode(int data)
{
    nd *newnode = (nd *)malloc(sizeof(nd));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void enqueue(int data)
{
    nd *newnode = createNode(data);
    if (front == NULL)
    {
        front = newnode;
        rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}

void dequeue()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        nd *ptr = front;
        printf("Popped element: %d\n", ptr->data);
        front = front->next;
        free(ptr);
    }
}

void push(int data)
{
    nd *newnode = createNode(data);
    newnode->next = top;
    top = newnode;
}

void pop()
{
    while (top != NULL)
    {
        nd *ptr = top;
        enqueue(ptr->data);
        top = top->next;
        free(ptr);
    }
}

void display()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        nd *temp = front;
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
    while (front != NULL)
    {
        nd *temp = front;
        push(temp->data);
        front = front->next;
    }
    pop();
    display();
}

void main()
{
    int choice;

    do
    {
        printf("Enter 1 for enqueue 2 for dequeue 3 for reverse 4 for display \n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            int data;
            printf("Enter the data\n");
            scanf("%d", &data);
            enqueue(data);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            reverse();
            break;
        case 4:
            display();
            break;
        case 0:
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice != 0);
}