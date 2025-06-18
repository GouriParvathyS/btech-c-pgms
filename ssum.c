#include <stdio.h>
#include <stdlib.h>
typedef struct sparse{
    int row;
    int col;
    int val;
}sparse;
void read(struct sparse a[],int nz)
{
    a[0].val=nz;
    int rows,cols;
    printf("Enter the no.of rows:-");
    scanf("%d",&rows);
    printf("Enter the no.of rows:-");
    scanf("%d",&cols);
    a[0].row=rows;
    a[0].col=cols;
    for (int i=1;i<=nz;i++)
    {
        scanf("%d %d %d",&a[i].row,&a[i].col,&a[i].val);
    }
}
void display(struct sparse a[],int nz)
{
    printf("The sparse matrix in triplet form is :-\n");
    for (int i=0;i<=a[0].val;i++)
    {
        printf("%d %d %d\n",a[i].row,a[i].col,a[i].val);
        
    }
}
void sumA(struct sparse a[],int nz1,struct sparse b[],struct sparse sum[],int nz2)
{
    int i=1,j=1,l=1;
    if (a[0].row!=b[0].row || a[0].col!=b[0].col){
        printf("Sum not possible");
        exit(0);
    }
    sum[0].row=a[0].row;
    sum[0].col=a[0].col;
    void ADDA()
    {
        sum[l].row=a[i].row;
        sum[l].col=a[i].col;
        sum[l].val=a[i].val;
        l++;
        i++;
    }
    void ADDB()
    {
        sum[l].row=b[j].row;
        sum[l].col=b[j].col;
        sum[l].val=b[j].val;
        l++;
        j++;
    }
    
    while(i<=a[0].val && j<=b[0].val){
    if(a[i].row<b[j].row || (a[i].row==b[j].row && a[i].col<b[j].col))
    {
        ADDA();
    }
    else if(a[i].row>b[j].row || (a[i].row==b[j].row && a[i].col>b[j].col))
    {
        ADDB();
    }
    else if (a[i].row==b[j].row && a[i].col==b[j].col)
    {
        sum[l].row=b[j].row;
        sum[l].col=b[j].col;
        sum[l].val=b[j].val+a[i].val;
        l++;
        i++;
        j++;
    }
}while(i<=a[0].val)
{
    ADDA();
}
while(j<=b[0].val)
{
    ADDB();
}
sum[0].val=l-1;
}
void main(){
    sparse a[100],b[100],sum[100];
    int nz1,nz2;
    printf("enter the no.of nonzer elements:-");
    scanf("%d",&nz1);
    read(a,nz1);
    display(a,nz1);
    printf("enter the no.of nonzer elements:-");
    scanf("%d",&nz2);
    read(b,nz2);
    display(b,nz2);
    sumA(a,nz1,b,sum,nz1);
    display(sum,sum[0].val)           ;
}