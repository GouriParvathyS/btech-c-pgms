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
    int minp,temp;
    for (int i=0;i<n-1;i++)
    {
        minp=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[minp])
            minp=j;
        }
        if (minp!=i){
        temp=a[i];
        a[i]=a[minp];
        a[minp]=temp;}
        for(int k=0;k<n;k++)
        {
            printf("%d",a[k]);
        }
        printf("\n");
    }
    
    
}