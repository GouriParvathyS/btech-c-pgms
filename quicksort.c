#include <stdio.h>
int partition(int a[],int lb,int ub)
{
    int pivot=a[lb];
    int start = lb;
    int end = ub;
    while(start < end)
    {
        while(a[start]<=pivot)
        {
            start++;
        }
        while(a[end]>pivot)
        {
            end--;
        }

    
    if (start < end)
    {
        int temp;
        temp=a[start];
        a[start]=a[end];
        a[end]=temp;
    }
    }
    int temp;
    temp=a[lb];
    a[lb]=a[end];
    a[end]=temp;
    return end;
}
void quicksort(int a[],int lb,int ub)
{
    if (lb<ub)
    {
        int pivot=partition(a,lb,ub);
        quicksort(a,lb,pivot-1);
        quicksort(a,pivot+1,ub);
    }
}
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
    quicksort(a,0,n-1);
    for (int i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }
}