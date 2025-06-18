#include <stdio.h>
void main(){
    printf("enter the no.of elements:-");
    int n;
    int a[10];
    scanf("%d",&n);
    printf("enter the elements:-");
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for (int i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }
    printf("\n");
    int swapped=1;
    for ( int i=0;i<n-1 && swapped==1;i++)
    {
        swapped=0;
        for (int j=0;j<n-i-1;j++)
        {
            if (a[j]>a[j+1])
            {
                int temp;
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                swapped=1;
            }
        }
    }
    for (int i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }
   printf("\n");
}