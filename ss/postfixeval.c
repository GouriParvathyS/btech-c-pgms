#include <stdio.h>
#include <math.h>
char postfix[10];int stack[10];
int top=-1;
int pop()
{
    if (top>-1)
    {
        return stack[top--];
    }
}
void evaluate()
{
    int x,y,result=0;
    for (int i=0;postfix[i]!='\0';i++)
    {
        
        if (postfix[i]=='+'|| postfix[i]=='-' || postfix[i]=='*' || postfix[i]=='/' || postfix[i]=='^')
        {
            result=0;
            y=pop();
            x=pop();
            if (postfix[i]=='+')
                result=x+y;
            else if (postfix[i]=='-')
                result=x-y;
            else if (postfix[i]=='*')
                result=x*y;
            else if (postfix[i]=='/')
                result=x/y;
            else
                result=pow(x,y);
            stack[++top]=result;
        }
        else{
            stack[++top]=(int)postfix[i]-48;
        }
        
    }
    printf("%d",result);
}
void main()
{
    printf("Enter the postfix:-");
    scanf("%s",postfix);
    evaluate();
}