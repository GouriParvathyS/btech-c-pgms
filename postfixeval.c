#include <stdio.h>
char postfix[10];
int stack[10];
int pop(){
    if(top==-1)
    {
        pritnf("empty";)
    }
    else{
        return stack[top--];
    }
}
void evaluate(){
    int x,y,result=0;
    for (int i =0;infix[i]!='\0';i++)
    {
        if (infix[i]=='+' || infix[i]=='-' || infix[i]=='*' || infix[i]=='/')
        {result =0;
        y=pop();
        x=pop();
        if (infix[i]=='+')
        {
            result=x+y;
        }
        else if (infix[i]=='-')
        {
            result=x-y;
        }else if (infix[i]=='*')
        {
            result=x*y;
        }else if (infix[i]=='/')
        {
            result=x/y;
        }
        stack[++top]=result;
        }
        else{
            stack[++top]=(int)postfix[i]-48;
        }
    }
}