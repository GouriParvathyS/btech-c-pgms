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
t *create_node()
{
    t *term = (t *)malloc(sizeof(t));
    printf("Enter coefficient and exponent\n");
    scanf("%d%d", &term->coeff, &term->exp);
    term->next = NULL;
    return term;
}
t *inputPoly(t *head, t *rear)
{
    char ch = 'y';
    while (ch == 'y')
    {
        t *term = create_node();
        if (head == NULL)
        {
            head = term;
            rear = term;
        }
        else
        {
            rear->next = term;
            rear = rear->next;
        }
        printf("Wish to add more terms\n");
        scanf(" %c", &ch);
    }
    return head;
}
void display(t *head)
{
    if (head == NULL)
    {
        printf("No elements\n");
    }
    else
    {
        t *temp = head->next;
        printf("%d*x^%d", head->coeff, head->exp);
        while (temp != NULL)
        {
            printf("+%d*x^%d", temp->coeff, temp->exp);
            temp = temp->next;
        }
        printf("\n");
    }
}
t *polyAdd(t *head1, t *head2)
{
    if (head1 == NULL && head2 == NULL)
    {
        printf("No terms\n");
    }
    else
    {
        t *temp1 = head1;
        t *temp2 = head2;
        while (temp1 != NULL && temp2 != NULL)
        {
            t *new_node = (t *)malloc(sizeof(t)); 
            new_node->next = NULL;
            if (temp1->exp == temp2->exp)
            {
                if (head3 == NULL)
                {
                    new_node->exp = temp1->exp;
                    new_node->coeff = temp1->coeff + temp2->coeff;
                    head3 = new_node;
                    rear3 = new_node;
                }
                else
                {
                    new_node->exp = temp1->exp;
                    new_node->coeff = temp1->coeff + temp2->coeff;
                    rear3->next = new_node;
                    rear3 = new_node;
                }
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            else if (temp1->exp > temp2->exp)
            {
                if (head3 == NULL)
                {
                    new_node->exp = temp1->exp;
                    new_node->coeff = temp1->coeff;
                    head3 = new_node;
                    rear3 = new_node;
                }
                else
                {
                    new_node->exp = temp1->exp;
                    new_node->coeff = temp1->coeff;
                    rear3->next = new_node;
                    rear3 = new_node;
                }
                temp1 = temp1->next;
            }
            else if (temp1->exp < temp2->exp)
            {
                if (head3 == NULL)
                {
                    new_node->exp = temp2->exp;
                    new_node->coeff = temp2->coeff + temp2->coeff;
                    head3 = new_node;
                    rear3 = new_node;
                }
                else
                {
                    new_node->exp = temp2->exp;
                    new_node->coeff = temp2->coeff;
                    rear3->next = new_node;
                    rear3 = new_node;
                }
                temp2 = temp2->next;
            }
        }
        while (temp1 != NULL)
        {
            if (head3 == NULL)
            {
                t *new_node = (t *)malloc(sizeof(t));
                new_node->next = NULL;
                new_node->exp = temp1->exp;
                new_node->coeff = temp1->coeff;
                head3 = new_node;
                rear3 = new_node;
            }
            else
            {
                t *new_node = (t *)malloc(sizeof(t));
                new_node->next = NULL;
                new_node->exp = temp1->exp;
                new_node->coeff = temp1->coeff;
                rear3->next = new_node;
                rear3 = new_node;
            }
            temp1 = temp1->next;
        }
        while (temp2 != NULL)
        {
            if (head3 == NULL)
            {
                t *new_node = (t *)malloc(sizeof(t));
                new_node->next = NULL;
                new_node->exp = temp2->exp;
                new_node->coeff = temp2->coeff + temp2->coeff;
                head3 = new_node;
                rear3 = new_node;
            }
            else
            {
                t *new_node = (t *)malloc(sizeof(t));
                new_node->next = NULL;
                new_node->exp = temp2->exp;
                new_node->coeff = temp2->coeff;
                rear3->next = new_node;
                rear3 = new_node;
            }
            temp2 = temp2->next;
        }
    }
    return head3;
}
t *polyMultiply(t *head1, t *head2)
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
                    if (temp3->exp==exp)
                    {
                        temp3->coeff+=coeff;
                        break;
                    }
                    temp3=temp3->next;
                }
            if (temp3==NULL)
            {
                t *new_node = (t *)malloc(sizeof(t));
                new_node->coeff=coeff;
                new_node->exp=exp;
                new_node->next=result;
                result=new_node;
            }
            temp2=temp2->next;
        }temp1=temp1->next;
    }


    return result;
}

void main()
{
    printf("Input polynomial 1\n");
    head1 = inputPoly(head1, rear1);
    display(head1);
    printf("Input polynomial 2\n");
    head2 = inputPoly(head2, rear2);
    display(head2);
    head3 = polyAdd(head1, head2);
    display(head3);
    printf("Result of polynomial multiplication:\n");
    t *head4 = polyMultiply(head1, head2);
    display(head4);
}
