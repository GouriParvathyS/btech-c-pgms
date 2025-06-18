#include<stdio.h>
int a[10],b[10];
void merge(int a[],int lb,int mid ,int ub){
    int i=lb;
    int j=mid+1;
    int k=lb;
    while(i<=mid && j<=ub)
    {
        if(a[i]<=a[j])
        {
            b[k]=a[i];
            k++;
            i++;
        }
        else if(a[i]>a[j])
        {
            b[k]=a[j];
            k++;
            j++;
        }
    }
    
    while(i<=mid)
        {
            b[k]=a[i];
            k++;
            i++;
        }
    
    while(j<=ub)
        {
            b[k]=a[j];
            k++;
            j++;
        }
    for (i = lb; i <= ub; i++) {
        a[i] = b[i];
    }
}
void mergesort(int a[],int lb,int ub)
{
    if (lb<ub)
    {
        int mid=(lb+ub)/2;
        mergesort(a,lb,mid);
        mergesort(a,mid+1,ub);
        merge(a,lb,mid,ub);
    }
}
void main(){
    printf("enter the no.of elements:-");
    int n;
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
    mergesort(a,0,n-1);
    for (int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}