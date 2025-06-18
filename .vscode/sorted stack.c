#include <stdio.h>
int stack1[10],stack2[10];
int top1=-1;
int top2=-1;
void push
{
    if(top>=n-1)
    {
        printf("stack is full\n");
    }
    else{
    if(top1==-1)
    {
        printf("Enter the data:-");
        scanf("%d",&data);
        stack1[++top1]=data
    }
    else{
        while(stack1[top1]<data && top1!=0)
        {
            stack2[++top2]=stack1[top1--];
        }
        stack1[++top1]=data;
        while(top2!=0)
        {
            stack1[++top1]=stack2[top2--];
        }
    }
    }
}
void display()
{
    if (top1==-1)
    {
        printf("The stack is empty.\n");
    }
    else{
    for (int i=top1;i>-1;i--)
    {
        printf("%d",stack1[i]);
    }
    printf("\n");
    }
}
void main(){
    push(9);
    push(9);
    push(9);
    push(9);
    push(9);
    push(9);
    display();
    
}