#include<stdio.h>
#include <math.h>
struct poly
{
    int coef;
    int exp;
}p1[10];
void readpoly(struct poly p[],int n)
{
    for (int i=0;i<n;i++)
    {
        printf("Coeffficient:-");
        scanf("%d",&p[i].coef);
        printf("Exponent:-");
        scanf("%d",&p[i].exp);
    }
}
void display(struct poly p[],int n)
{
    for (int i=0;i<n-1;i++)
    {
        printf("%dx^%d+",p[i].coef,p[i].exp);
    }
    if (p[n-1].exp>0)
    {
        printf("%dx^%d\n",p[n-1].coef,p[n-1].exp);
    }
    else
    {
        printf("%d\n",p[n-1].coef);
    }
}
void polyeval(struct poly p[],int n)
{
    int total=0;
    int x;
    printf("Enter the no.:-");
    scanf("%d",&x);
    for(int i=0;i<n;i++)
    {
        total+=p[i].coef*pow(x,p[i].exp);
    }
    printf("%d",total);
}
void main()
{
    int n1;
    printf("Enter the no.of terms:-");
    scanf("%d",&n1);
    readpoly(p1,n1);
    display(p1,n1);
    polyeval(p1,n1);
}