#include <stdio.h>
int front=-1,rear=-1;
int q[10];
void Enqueue(int n)
{
    printf("enter the element to be inserted:-");
    int item;
    scanf("%d",&item);
    if(front==-1)
    {
        front=0;
        rear=0;
        q[rear]=item;
    }
    else{
        if ((rear+1)%n!=front)
        {
        rear=(rear+1)%n;
        q[rear]=item;
    }
        else
        {
            printf("Queue is Full.\n");
        }
    }
}
void Dequeue(int n)
{
    if(front==-1)
    {
        printf("Queue is empty.\n");
    }
    else{
        int item=q[front];
        printf("The deleted element is %d\n",item);
        if (front==rear)
        {
            front=-1;
            rear=-1;
        }
        else{
            front=(front+1)%n;
        }
    }
}
void display()
{
    for (int i=front;i<=rear;i++)
    {
        printf("%d ",q[i]);
    }
}
void main()
{
    Enqueue(5);
    Enqueue(5);
    Enqueue(5);
    Enqueue(5);
    Enqueue(5);
    Enqueue(5);
    display();
    Dequeue(5);
    display();
    Dequeue(5);
    Dequeue(5);
    Dequeue(5);
    Dequeue(5);
    Dequeue(5);
}
