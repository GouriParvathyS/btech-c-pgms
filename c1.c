#include <stdio.h>

void main() {
    int n,k;
    printf("Enter the no. of elements:-");
    scanf("%d",&n);
    int a[n];
    printf("Enter the element to be checked:-");
    scanf("%d",&k);
    printf("Enter the elements:-");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int c=0;
    for(int i=0;i<n;i++)
    {
        if (a[i]==k)
        {
            c++;
            printf("The element is  at %d",i+1);
        }
    }
    if (c==0)
    printf("no");
    
}

