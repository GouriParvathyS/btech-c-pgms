#include <stdio.h>
#include <stdlib.h>
struct queue{
    int data;
    int priority;
}queue[10];
int front1=-1;int front2=-1; int rear1=-1;int rear2=-1;
int size=5;
struct queue temp;
void display(){
    if (front1==-1)
    {
        printf("The queue is empty.");
    }
    else{
        for (int i=front1;i<=rear1;i++)
            printf("%d",queue[i].data);
        }
        printf("\n");
    }
void Enqueue(){
    int data,priority;
    printf("enter the data to be entered:-");
    scanf("%d %d",&data,&priority);
    if (rear1==size-1){
        printf("Queue full\n");
    }
    else{
        if (front1==-1){
        front1=0;front2=0;
        queue[++rear1].data=data;
        queue[++rear2].priority=priority;
    }
    else{
        queue[++rear1].data=data;
        queue[++rear2].priority=priority;
        for (int i=rear2;i>front2;i--)
        {
            if (queue[i-1].priority<queue[i].priority)
            {
                temp=queue[i];
                queue[i]=queue[i-1];
                queue[i-1]=temp;
            }
        }
    }
}
display();
}
void dequeue(){
    if (front1==-1)
{
    printf("Queue Full\n");
}
else{
    printf("The deleted element is %d",queue[front1].data);
    if (front1==rear1)
    {
        front1=-1;
        rear1=-1;
        front2=-1;
        rear2=-1;
    }
    else{
        front1++;
        rear1++;
    }
}}
void main(){
    Enqueue();
    Enqueue();
    Enqueue();
    Enqueue();
    Enqueue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
}