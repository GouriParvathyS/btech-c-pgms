#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int row;
    int col;
    int value;
}triplet;
int nonzero=0;
int a[10][10];
void input(int r,int c)
{
    for(int i=0;i<r;i++)
    {
          for(int j=0;j<c;j++)
          {
            scanf("%d",&a[i][j]);
          }
    }
}
void display(int r,int c)
{
    for(int i=0;i<r;i++)
    {
          for(int j=0;j<c;j++)
          {
            printf("%d ",a[i][j]);
          }
          printf("\n");
    }
}
void count(int r,int c)
{
    for(int i=0;i<r;i++)
    {
          for(int j=0;j<c;j++)
          {
            if (a[i][j]!=0)
            {
                nonzero++;
            }
          }
    }
}
void sparserep(triplet rows[],int r,int c)
{
    rows[0].row=r;    
    rows[0].col=c;    
    rows[0].value=nonzero;  
    int m=1;
    for(int i=0;i<r;i++)
    {
          for(int j=0;j<c;j++)
          {
            if (a[i][j]!=0)
            {
            rows[m].row=i;    
            rows[m].col=j;    
            rows[m].value=a[i][j]; 
            m++;
            }
          }
    }
}
void d(triplet rows [])
{
    for (int i=0;i<=nonzero;i++)
    {
        printf("%d %d %d\n",rows[i].row,rows[i].col,rows[i].value);
    }
}
void main()
{
    int r,c;
    printf("Enter the no.of of rows:-");
    scanf("%d",&r);
    printf("Enter the no.of of cols:-");
    scanf("%d",&c);
    input(r,c);
    display(r,c);
    count(r,c);
    triplet rows[nonzero+1];
    sparserep(rows,r,c);
    d(rows);
}