#include <stdio.h>
int a[]={1,2,3,4};
void insertP()
{
    int p;
    printf("Enter the position:-");
    scanf("%d",&p);
    int v;
    printf("Enter the value:-");
    scanf("%d",&v);
    for (int i=4;i>p-1;i--)
    {
        a[i]=a[i-1];
    }
    a[p-1]=v;
}
void display(n)
{
    for (int i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }
}
void deleteP(n)
{
    int p;
    printf("Enter the position:-");
    scanf("%d",&p);
    printf("The deleted element is %d\n",a[p-1]);
    for (int i=p-1;i<n;i++)
    {
        a[i]=a[i+1];
    }
}
void deleteK(n)
{
    int k,c=0;
    printf("Enter the key:-");
    scanf("%d",&k);
    for(int i=0;i<n;i++)
    {
        if (a[i]==k)
        {
            printf("The deleted element is %d\n",a[i]);
            for (int i=k-1;i<n;i++)
            {
               a[i]=a[i+1];
            }
            c=1;
            break;
        }
    }
    if(c==0)
        {
            printf("No such element present");
        }
}
void main(){

    insertP();
    int h=*(&a+1)-a;
    display(h+1);
    deleteP(h+1);
    int l=*(&a+1)-a;
    display(l);
    deleteK(l);
    int o=*(&a+1)-a;
    display(o-1);

}
