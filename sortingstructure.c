#include<stdio.h>
void main()
{
    struct student
    {
        char name[30];
        int m1;
        int m2;
        int m3;
        int m4;
    }a[5];
    int n;
    printf("Enter the no.of students");
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        printf("Enter:-");
        scanf("%s",&a[i].name);
        scanf("%d",&a[i].m1);
        scanf("%d",&a[i].m2);
        scanf("%d",&a[i].m3);
        
        a[i].m4=a[i].m1+a[i].m2+a[i].m3;
    }
            int temp;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(a[j].m4>a[j+1].m4)
            {
                temp=a[j].m4;
                a[j].m4=a[j+1].m4;
                a[j+1].m4=temp;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%d\n",a[i].m4);
    }
}
