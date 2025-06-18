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
    for (int i=1;i<n;i++)
    {
        int key=a[i];
        int j=i;
       while(a[j-1]>key && j>0)
        {
            a[j]=a[j-1];
            j--;
        }
        a[j]=key;
    }
    for (int i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }
}