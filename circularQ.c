#include <stdio.h>
int queue[10];
int front =-1;
int rear=-1;
int maxsize;
void Enqueue(int data)
{
    
        if (front==-1)
        {
            front=0;
            queue[++rear]=data;
        }
        else{
            if (front!=(rear+1)%maxsize)
            {
                rear=(rear+1)%maxsize;
                queue[rear]=data;
            }
            else{
                printf("Queue full\n");
            }
        }

}
void dequeue(){
    if (front==-1)
    {
        printf("Queue Empty\n");
    }
    else{
        int d=queue[front];
        printf("The delted element is %d\n",d);
        if (front==rear){
            front=-1;
            rear=-1;
        }
        else{
            front=(front+1)%maxsize;
        }
    }
}
void display(){
    if(front==-1){
        printf("Queue empty.");
    }
    else{
        if (front<=rear){
    for (int i=front;i<=rear;i++){
        printf("%d ",queue[i]);
    }}
    else{
        for (int i=front;i<maxsize;i++){
        printf("%d ",queue[i]);
    }
    for (int i=0;i<=rear;i++){
        printf("%d ",queue[i]);
    }
    }}
    printf("\n");
}
void main(){
    printf("Enter the size of the queue:-");
    scanf("%d",&maxsize);
    Enqueue(10);
    Enqueue(20);
    Enqueue(30);
    Enqueue(40);
    Enqueue(50);
    display();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    Enqueue(100);
    Enqueue(150);
    display();
}