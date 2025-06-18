#include<stdio.h>
struct poly{
    int coef;
    int exp;
}p1[10],p2[10],p3[10];
void read(struct poly p[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("Enter coefficient:-");
        scanf("%d",&p[i].coef);
        printf("Enter exp:-");
        scanf("%d",&p[i].exp);

    }
}
void display(struct poly p[],int n)
{
    for ( int i=0;i<n-1;i++)
    {
        printf("%dx^%d+",p[i].coef,p[i].exp);
    }
    if(p[n-1].exp>0)
    {
        printf("%dx^%d\n",p[n-1].coef,p[n-1].exp);
    }
    else{
        printf("%d\n",p[n-1].coef);
    }
}
int polyadd(struct poly p1[],struct poly p2[],struct poly p3[],int n1,int n2)
{
    int i=0,j=0,k=0;
    while(i<n1 && j<n2)
    {
        if (p1[i].exp==p2[j].exp)
        {
            p3[k].coef=p1[i].coef +p2[j].coef;
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
    int n1;
    int n2;
    printf("Enter the no.of terms");
    scanf("%d",&n1);
    printf("Enter the no.of terms");
    scanf("%d",&n2);
    read(p1,n1);
    display(p1,n1);
    read(p2,n2);
    display(p2,n2);
    int n3=polyadd(p1,p2,p3,n1,n2);
    display(p3,n3);
}