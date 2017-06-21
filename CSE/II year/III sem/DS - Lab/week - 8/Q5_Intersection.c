#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
    struct node *prev;
};
typedef struct node *NODE;

void Insert(NODE, int);
void Display(NODE);
NODE getNode();
int main()
{
    int num, item, i, Check;
    NODE head1, head2, head3, temp1, temp2;
    head1=getNode();
    head2=getNode();
    head3=getNode();
    printf("First List:\n");
    printf("Enter the number of elements: ");
    scanf("%d", &num);
    printf("Enter the elements:\n");
    for (i=0; i<num; i++)
    {
        scanf("%d", &item);
        Insert(head1, item);
    }


    printf("Second List:\n");
    printf("Enter the number of elements: ");
    scanf("%d", &num);
    printf("Enter the elements:\n");
    for (i=0; i<num; i++)
    {
        scanf("%d", &item);
        Insert(head2, item);
    }

    temp1=head1->next;
    temp2=head2->next;

    while(temp1!=NULL)
    {
        Check=0;
        temp2=head2->next;
        while (temp2!=NULL)
        {
            if (temp2->info==temp1->info)
                Check=1;
            temp2=temp2->next;
        }
        if (Check==1)
            Insert (head3, temp1->info);
        temp1=temp1->next;
    }

    Display(head3);
    return 0;
}

void Insert (NODE head, int item)
{
    NODE temp = getNode();
    NODE p;
    temp->info=item;
    temp->next=NULL;

    if (head->next==NULL)
        head->next=temp;

    else
    {
        p=head->next;
        while(p->next!=NULL)
            p=p->next;
        p->next=temp;
    }
}

void Display(NODE head)
{
    NODE temp;
    temp=head->next;
    if (temp==NULL)
        printf("The intersection is empty.\n");
    else
    {
        printf("The intersection is:\n");
        while (temp!=NULL)
        {
            printf("%d, ", temp->info);
            temp=temp->next;
        }
        printf("\n\n");
    }
}

NODE getNode()
{
    NODE temp;
    temp=(NODE) malloc(sizeof(struct node));
    temp->next=NULL;
    return temp;
}
