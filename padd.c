#include <stdio.h>
#include <stdlib.h>
typedef struct polynomial{
    int coef;
    int exp;
}poly;
void create(poly p[],int n)
{
    for (int i =0;i<n;i++)
    {
        printf("Enter the coefficient:");
        scanf("%d",&p[i].coef);
        printf("Enter the exponent:");
        scanf("%d",&p[i].exp);
    }
}
void display(poly p[],int n)
{
    printf("%dx^%d",p[0].coef,p[0].exp);
    for (int i=1;i<n;i++)
    {
        printf("+%dx^%d",p[i].coef,p[i].exp);
    }
}
int polyadd(poly p1[],poly p2[],poly p3[],int n1,int n2)
{
    int i=0,j=0,k=0;
    while(i<n1 && j<n2)
    {
        if (p1[i].exp==p2[j].exp)
        {
            p3[k].coef=p1[i].coef+p2[j].coef;
            p3[k].exp=p1[i].exp;
            i++;
            j++;
            k++;
        }
        else if(p1[i].exp>p2[j].exp)
        {
            p3[k].coef=p1[i].coef;
            p3[k].exp=p1[i].exp;
            i++;
            k++;
        }
        else{
            p3[k].coef=p2[j].coef;
            p3[k].exp=p2[j].exp;
            j++;
            k++;
        }
    }
    while(i<n1)
    {
        p3[k].coef=p1[i].coef;
        p3[k].exp=p1[i].exp;
        i++;
        k++;
    }
    while(j<n2)
    {
        p3[k].coef=p2[j].coef;
        p3[k].exp=p2[j].exp;
        j++;
        k++;
    }  
    return k;
}
void main()
{
    int n1,n2;
    printf("Enter the no.of terms:-");
    scanf("%d",&n1);
    poly p1[n1];
    create(p1,n1);
    display(p1,n1);
    printf("Enter the no.of terms:-");
    scanf("%d",&n2);
    poly p2[n2];
    create(p2,n2);
    display(p2,n2);
    poly p3[10];
    int k1=polyadd(p1,p2,p3,n1,n2);
    display(p3,k1);
}