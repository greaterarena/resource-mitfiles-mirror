#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char data[100];
    struct node *rlink;
    struct node *llink;
};
typedef struct node *PTR;
typedef struct node NODE;

PTR insertf(PTR head,char d[100])
{
    PTR temp=(PTR)malloc(sizeof(NODE));
    strcpy(temp->data,d);
    if(head->rlink==head)
    {
        head->rlink=temp;
        temp->llink=head;
        temp->rlink=head;
        head->llink=temp;
    }
    else
    {
        temp->rlink=head->rlink;
        (head->rlink)->llink=temp;
        head->rlink=temp;
        temp->llink=head;
    }
    return head;
}

PTR insertr(PTR head,char d[100])
{
    PTR temp=(PTR)malloc(sizeof(NODE));
    PTR t = head;
    strcpy(temp->data,d);
    if(head->rlink==head)
    {
        head->rlink=temp;
        temp->llink=head;
        temp->rlink=head;
        head->llink=temp;
    }
    else
    {
        while(t->rlink!=head)
            t = t->rlink;
        t->rlink = temp;
        temp->rlink=head;
        temp->llink = t;
    }
    return head;
}

PTR rev(PTR h1)
{
    PTR head1=(PTR)malloc(sizeof(NODE));
    head1->rlink=head1;
    head1->llink=head1;
    PTR temp=h1->rlink;
    while(temp!=h1){
        head1=insertf(head1,temp->data);
        temp = temp->rlink;
    }
    return head1;
}

void display(PTR head)
{
    PTR temp;
    if(head->rlink==head)
    {
        printf("list is empty");
        return;
    }
    temp=head->rlink;
    while(temp!=head)
    {
        printf("%s ",temp->data);
        temp=temp->rlink;
    }
}

int main()
{
    PTR head1=(PTR)malloc(sizeof(NODE));
    head1->rlink=head1;
    head1->llink=head1;
    PTR head2=(PTR)malloc(sizeof(NODE));
    head2->rlink=head2;
    head2->llink=head2;

    char c,t;
    char q[100];

    printf("enter your choice for the linked list");
    do
    {
        printf("insert?press y OR n");
        scanf("%c",&c);
        scanf("%c",&t);
        if(c=='y'||c=='Y')
        {
            printf("enter item to be inserted");
            scanf("%s",q);
            scanf("%c",&t);
            head1=insertr(head1,q);
        }
    }while(c=='y'||c=='Y');

    display(head1);printf("\n");

    head1 = rev(head1);

    display(head1);printf("\n");

    return 0;
}
