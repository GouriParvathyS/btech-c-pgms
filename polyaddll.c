/**#include <stdio.h>
#include <stdlib.h>
typedef struct poly{
    int coef;
    int exp;
    struct poly *next;
}poly;
struct poly *newnode;
poly *head1=NULL;
poly *head2=NULL;
poly *head3=NULL;
poly* create(poly *head1)
{
    int c=1;
    poly *temp;
    while(c==1)
    {
        newnode=(poly*)malloc(sizeof(poly));
        printf("Enter the coefficienr:-");
        scanf("%d",&newnode->coef);
        printf("Enter the exponent:-");
        scanf("%d",&newnode->exp);
        printf("Do you which to continue 1:-");
        scanf("%d",&c);
        if(head1==NULL)
        {
            head1=newnode;
            newnode->next=NULL;
        }
        else{
            
            temp=head1;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp=temp->next;
            temp=temp->next=newnode;
            newnode->next=NULL;
        }
    }
    return head1;
}
poly *display(poly *head1)
{
    poly*temp=head1;
    if (head1==NULL)
    {
        printf("Empty.");
    }
    else{
        while(temp->next!=NULL)
        {
            printf("%d(X)^%d+",temp->coef,temp->exp);
            temp=temp->next;
        }
        if(temp->exp>0)
        {
            printf("%d(X)^%d",temp->coef,temp->exp);
        }
        else{
            printf("%d",temp->coef);
        }

    }
}
poly *polyadd(poly *head1,poly*head2,poly *head3)
{
    poly*temp1=head1;
    poly*temp2=head2;
    poly*temp3=head3;
    while (temp1!=NULL||temp2!=NULL)
    {
        newnode=(poly*)malloc(sizeof(poly));
        newnode->next=NULL;
        if(temp1!=NULL&&temp2!=NULL)
        {
            if (temp1->exp==temp2->exp)
            {
                newnode->coef=temp1->coef+temp2->coef;
                newnode->exp=temp1->exp;
                temp1=temp1->next;
                temp2=temp2->next;
            }
            else if (temp1->exp>temp2->exp)
            {
                newnode->coef=temp1->coef;
                newnode->exp=temp1->exp;
                temp1=temp1->next;
            }
            else{
                newnode->coef=temp2->coef;
                newnode->exp=temp2->exp;
                temp2=temp2->next;
            }
        }
        else if(temp2!=NULL)
        {
            newnode->coef=temp1->coef;
            newnode->exp=temp1->exp;
            temp1=temp1->next;
        }
        else{
            newnode->coef=temp2->coef;
            newnode->exp=temp2->exp;
            temp2=temp2->next;
        }
    
    if(head3==NULL)
    {
        head3=newnode;
        newnode->next=NULL;
    }
    else{
        temp3->next=newnode;
        temp3=temp3->next;
    }}
    return head3;
}
void main()
{
    printf("Enter :-\n");
    poly*head1=create(head1);
    display(head1);
    poly* head2=create(head2);
    display(head2);
    poly *p;
    p=polyadd(head1,head2,head3);
    display(p);
}**/
#include <stdio.h>
#include <stdlib.h>

typedef struct poly {
    int coef;
    int exp;
    struct poly *next;
} poly;

poly *create(poly *head) {
    int c = 1;
    poly *temp, *newnode;
    while (c == 1) {
        newnode = (poly*)malloc(sizeof(poly));
        printf("Enter the coefficient: ");
        scanf("%d", &newnode->coef);
        printf("Enter the exponent: ");
        scanf("%d", &newnode->exp);
        printf("Do you want to continue? (1/0): ");
        scanf("%d", &c);
        
        if (head == NULL) {
            head = newnode;
            newnode->next = NULL;
        } else {
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->next = NULL;
        }
    }
    return head;
}

void display(poly *head) {
    poly *temp = head;
    
    if (head == NULL) {
        printf("Empty.\n");
    } else {
        while (temp != NULL) {
            printf("%d(X)^%d", temp->coef, temp->exp);
            if (temp->next != NULL) {
                printf(" + ");
            }
            temp = temp->next;
        }
        printf("\n");
    }
}

poly *polyadd(poly *head1, poly *head2) {
    poly *temp1 = head1;
    poly *temp2 = head2;
    poly *head3 = NULL;
    poly *temp3 = NULL;

    while (temp1 != NULL || temp2 != NULL) {
        poly *newnode = (poly*)malloc(sizeof(poly));
        newnode->next = NULL;

        if (temp1 != NULL && temp2 != NULL) {
            if (temp1->exp == temp2->exp) {
                newnode->coef = temp1->coef + temp2->coef;
                newnode->exp = temp1->exp;
                temp1 = temp1->next;
                temp2 = temp2->next;
            } else if (temp1->exp > temp2->exp) {
                newnode->coef = temp1->coef;
                newnode->exp = temp1->exp;
                temp1 = temp1->next;
            } else {
                newnode->coef = temp2->coef;
                newnode->exp = temp2->exp;
                temp2 = temp2->next;
            }
        } else if (temp1 != NULL) {
            newnode->coef = temp1->coef;
            newnode->exp = temp1->exp;
            temp1 = temp1->next;
        } else {
            newnode->coef = temp2->coef;
            newnode->exp = temp2->exp;
            temp2 = temp2->next;
        }
        if (head3 == NULL) {
            head3 = newnode;
            temp3 = newnode;
        } else {
            temp3->next = newnode;
            temp3 = temp3->next;
        }
    }
    return head3;
}

int main() {
    printf("Enter polynomial 1:\n");
    poly *head1 = create(NULL);
    printf("Polynomial 1: ");
    display(head1);

    printf("\nEnter polynomial 2:\n");
    poly *head2 = create(NULL);
    printf("Polynomial 2: ");
    display(head2);

    poly *result = polyadd(head1, head2);
    printf("\nResult of addition: ");
    display(result);

    // Free allocated memory
    /**while (head1 != NULL) {
        poly *temp = head1;
        head1 = head1->next;
        free(temp);
    }
    while (head2 != NULL) {
        poly *temp = head2;
        head2 = head2->next;
        free(temp);
    }
    while (result != NULL) {
        poly *temp = result;
        result = result->next;
        free(temp);
    }**/

    return 0;
}
