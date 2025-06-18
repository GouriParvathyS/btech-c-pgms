/**#include <stdio.h>
#include <string.h>
int stack[10];
char prefix[10],infix[10];
int top=-1;
int precedence(char operator)
{
    switch (operator)
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
void toprefix()
{
    int j=0,temp;
    for(int i=0;infix[i]!='\0';i++)
    {
        if (infix[i]=='+'||infix[i]=='-'||infix[i]=='*'||infix[i]=='/')
        {
            if (top==-1)
            {
                stack[++top]=infix[i];
            }
            else
            {
                if (precedence(infix[i])>precedence(stack[top]))
                {
                    stack[++top]=infix[i];
                }
                else{
                    prefix[j++]=stack[top--];
                    stack[++top]=infix[i];
                }
                /*if (top>0)
                {
                    if (precedence(stack[top])==precedence(stack[top-1]))
                    {
                        temp=stack[top];
                        stack[top]=stack[top-1];
                        stack[top-1]=temp;
                        prefix[j++]=stack[top--];
                    }
                }
                
            }
        }
        else if (infix[i]=='(')
        {
            stack[++top]=infix[i];
        }
        else if (infix[i]==')')
        {
            while(stack[top]!='(')
            {
                prefix[j++]=stack[top--];
            }
            top--;
        }
        else
        {
            prefix[j++]=infix[i];
        }
    }
    while(top>-1)
    {
        prefix[j++]=stack[top--];
    }
}
void main()
{
    scanf("%s",strrev(infix));
    toprefix();
    char prefix1[20];
    {
        printf("%s",strrev(prefix));
    } 
}**/#include <stdio.h>
#include <string.h>

int stack[10];
char prefix[10], infix[10];
int top = -1;

int precedence(char operator) {
    switch (operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '(':
            return 0;
    }
    return -1; // Indicating invalid operator
}

void toprefix() {
    int j = 0;
    for (int i = strlen(infix) - 1; i >= 0; i--) { // Reversing the input infix expression
        if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/') {
            if (top == -1 || precedence(infix[i]) > precedence(stack[top])) {
                stack[++top] = infix[i];
            } else {
                while (top != -1 && precedence(infix[i]) <= precedence(stack[top])) {
                    prefix[j++] = stack[top--];
                }
                stack[++top] = infix[i];
            }
        } else if (infix[i] == ')') {
            stack[++top] = infix[i];
        } else if (infix[i] == '(') {
            while (stack[top] != ')') {
                prefix[j++] = stack[top--];
            }
            top--; // Discard the '('
        } else {
            prefix[j++] = infix[i];
        }
    }
    while (top > -1) {
        prefix[j++] = stack[top--];
    }
    prefix[j] = '\0'; // Null-terminate the prefix expression
}

int main() {
    printf("Enter infix expression: ");
    scanf("%s", infix);

    toprefix();

    printf("Prefix expression: %s\n", strrev(prefix)); // Reversing the prefix expression
    return 0;
}
