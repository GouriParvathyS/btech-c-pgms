#include <stdio.h>

void main()
{
    int n,s;
    printf("Enter the no.of elements in  the array");
    scanf("%d",&n);
    int a[n];
    printf("enter the elements:-");
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for (int i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }
    for (int i=0;i<n-1;i++)
    {
        int minp=i;
        for (int j = i+1; j < n; j++)
        {
            if (a[minp]>a[j])
            {
                minp=j;
            }
        }
        int temp;
        temp=a[minp];
        a[minp]=a[i];
        a[i]=temp;
    }
    printf("The array after sorting\n");
    for (int i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }
}