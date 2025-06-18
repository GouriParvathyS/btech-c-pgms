#include <stdio.h>
#include <stdlib.h>
typedef struct terms
{
    int coeff;
    int exp;
    struct terms *next;

} t;
t *head1, *head2, *rear1, *rear2;
t *head3;
t *rear3;
t *polymult(struct node *head1,struct node *head2)
{
    t *result=NULL;
    t *temp1=head1;
    while(temp1!=NULL)
    {
        t *temp2=head2;
        while(temp2!=NULL)
        {
            int coeff=temp1->coeff*temp2->coeff;
            int exp=temp1->exp+temp2->exp;
            t *temp3=result;
            
                while(temp3!=NULL)
                {
                    if (temp2->exp==exp)
                    {
                        temp->coeff+=coeff;
                        break;
                    }
                    temp3=temp3->next;
                }
            if (temp3==NULL)
            {
                struct t *newnode;
                newnode=(*t)malloc(sizeof(t));
                newnode->coeff=coeff;
                newnode->exp=exp;
                newnode->next=result;
                result=newnode;
            }
            temp2=temp2->next;
        }temp1=temp1->next;
    }

}