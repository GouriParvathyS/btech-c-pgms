#include <stdio.h>
int binarySearch(int a[],int n,int s)
{
    int l=0;int h=n-1;int mid;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(a[mid]==s)
        {
            printf("The element found at %d",mid+1);
            return mid;
        }
        else if(a[mid]<s)
        {
            l=mid+1;
        }
        else{
            h=mid-1;
        }
    }
    return -1;
}
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
    printf("Enter the element to be searched:-");
    scanf("%d",&s);
    int r=binarySearch(a,n,s);
    if (r==-1)
    {
        printf("Element absent\n");
    }
    
}