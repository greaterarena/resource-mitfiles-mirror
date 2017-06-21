#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
};
typedef struct node *NODE;


void Insert(NODE, int);
void Display(NODE);
NODE getNode();
int main()
{
    int num, i;
    int item;
    NODE head1, head2, head3;
    NODE temp;
    head1=getNode();
    head2=getNode();
    head3=getNode();
    printf("First List:\n");
    printf("Enter the number of elements: ");
    scanf ("%d", &num);
    printf ("Enter the elements:\n");
    for (i=0; i<num; i++)
    {
        scanf("%d", &item);
        Insert(head1, item);
    }
    printf("Second List:\n");
    printf("Enter the number of elements: ");
    scanf ("%d", &num);
    printf ("Enter the elements:\n");
    for (i=0; i<num; i++)
    {
        scanf("%d", &item);
        Insert(head2, item);
    }
    temp=head1->link;
    while (temp!=NULL)
    {
        Insert(head3, temp->info);
        temp=temp->link;
    }
    temp=head2->link;
    while (temp!=NULL)
    {
        Insert (head3, temp->info);
        temp=temp->link;
    }

    Display(head3);
    return 0;
}

void Insert (NODE head, int item)
{
    NODE temp = getNode();
    NODE p, p1;
    temp->info=item;
    temp->link=NULL;

    if (head->link==NULL)
    {
        head->link=temp;
        return;
    }

    p=head->link;

    if (temp->info < p->info)
    {
        head->link=temp;
        temp->link=p;
        return;
    }

    p1=p;
    p=p->link;

    while(p!=NULL && temp->info >= p->info)
    {
            p1=p;
            p=p->link;
    }

    if (p==NULL && p1->info!=temp->info)
    {
        p1->link=temp;
        return;
    }

    if (p1->info!=temp->info)
    {
        p1->link=temp;
        temp->link=p;
    }


}


void Display(NODE head)
{
    NODE temp;
    temp=head->link;
    if (head->link==NULL)
        printf("The list is empty.\n");
    else
    {
        printf("The Union is:\n");
        while (temp!=NULL)
        {
            printf("%d, ", temp->info);
            temp=temp->link;
        }
        printf("\n\n");
    }
}

NODE getNode()
{
    NODE temp;
    temp=(NODE) malloc(sizeof(struct node));
    temp->link=NULL;
    return temp;
}
