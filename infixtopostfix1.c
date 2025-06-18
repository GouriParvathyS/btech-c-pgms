#include <stdio.h>
int stack[10];
int top=-1;
char infix[10],postfix[10];
char operator;
int precedence(char operator)
{
    switch(operator)
    {
        
        case '+':
        case '-':
            return 1;
            break;
        case '*':
        case '/':
            return 2;
            break;
        case '(':
            return 0;
            break;

    }
}
void topostfix(){
    int j=0,temp;
    for (int i=0;infix[i]!='\0';i++)
    {
        if (infix[i]=='+'||infix[i]=='-'||infix[i]=='*'||infix[i]=='/')
        {
            if (top==-1)
            {
                stack[++top]=infix[i];
            }
            else{
                if ((precedence(infix[i]))>(precedence(stack[top])))
                {
                    stack[++top]=infix[i];
                }
                else{
                postfix[j++]=stack[top--];
                stack[++top]=infix[i];
                }
                if (top>0)
                {
                    if (precedence(stack[top])==precedence(stack[top-1]))
                    {
                        temp=stack[top];
                        stack[top]=stack[top-1];
                        stack[top-1]=temp;
                        postfix[j++]=stack[top--];
                    }
                }
            }
        }else if (infix[i]=='(')
        {
            stack[++top]=infix[i];
        }
        else if (infix[i]==')')
        {
            while(stack[top]!='(')
            {
                postfix[j++]=stack[top--];
            }top--;
        }
        else{
            postfix[j++]=infix[i];
        }
    }
    while(top>-1)
    {
        postfix[j++]=stack[top--];
    }
}
void main(){
    printf("Enter the infix expression:-");
    scanf("%s",&infix);
    topostfix();for(int i=0;postfix[i]!='\0';i++)
    {
        printf("%c",postfix[i]);
    }

}