#include<stdio.h>
int stack[100];
int top=-1;
int data;
void push(int n)
{
    if (top>=n-1)
    {
        printf("stack is full\n");
    }
    else
    {
        printf("Enter the element to be entered:-");
        scanf("%d",&data);
        stack[++top]=data;
    }
}
void pop()
    {
        if (top==-1)
        {
            printf("The stack is empty\n");
        }
        else{
            int d=stack[top--];
            printf("The deleted element is %d\n",d);
        }
    }
void peek()
{
    if(top==-1)
    {
        printf("Stack empty\n");
    }
    else
    {
        printf("The top element is %d\n",stack[top]);
    }
}
void display()
{
    if (top==-1)
    {
        printf("The stack is empty.\n");
    }
    else{
    for (int i=top;i>-1;i--)
    {
        printf("%d",stack[i]);
    }
    printf("\n");
    }
}
void main()
{
    int n;
    printf("Enter the no.of elements:-");
    scanf("%d",&n);
    push(n);
    push(n);
    push(n);
    push(n);
    push(n);
    push(n);
    display();
    peek();
    pop();
    display();
}