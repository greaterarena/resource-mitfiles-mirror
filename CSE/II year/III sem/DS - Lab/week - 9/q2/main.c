#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *rlink;
    struct node *llink;
};
typedef struct node *PTR;
typedef struct node NODE;

PTR insertf(PTR head,int d)
{
    PTR temp=(PTR)malloc(sizeof(NODE));
    temp->data=d;
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

PTR sum(PTR h1,PTR h2,PTR h3)
{
    int sum=0,car=0;
    PTR one=h1->rlink;
    PTR two=h2->rlink;
    while(one!=h1&&two!=h2)
    {
        sum=(one->data)+(two->data);
        h3=insertf(h3,((sum%10)+car));
        car=sum/10;
        one=one->rlink;
        two=two->rlink;
    }
    if(one==h1&&two!=h2)
    {
        while(two!=h2)
        {
            sum=(two->data)+car;
            h3=insertf(h3,(sum%10));
            car=sum/10;
            two=two->rlink;
        }
    }

    else if(two==h2&&one!=h1)
    {
        while(one!=h1)
        {
            sum=(one->data)+car;
            h3=insertf(h3,(sum%10));
            car=sum/10;
            one=one->rlink;
        }
    }


    if(car==1)
        h3=insertf(h3,1);
    return h3;
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
        printf("%d",temp->data);
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
    PTR head3=(PTR)malloc(sizeof(NODE));
    head3->llink=head3;
    head3->rlink=head3;

    char c,t;
    int d;
    printf("enter your choice for 1st linked list");
    do
    {
        printf("insert?press y OR n");
        scanf("%c",&c);
        scanf("%c",&t);
        if(c=='y'||c=='Y')
        {
            printf("enter item to be inserted");
            scanf("%d",&d);
            scanf("%c",&t);
            head1=insertf(head1,d);
        }
    }while(c=='y'||c=='Y');


    printf("enter your choice for 2nd linked list");
    do
    {
        printf("insert?press y OR n");
        scanf("%c",&c);
        scanf("%c",&t);
        if(c=='y'||c=='Y')
        {
            printf("enter item to be inserted");
            scanf("%d",&d);
            scanf("%c",&t);
            head2=insertf(head2,d);
        }
    }while(c=='y'||c=='Y');

    printf("sum is");
    head3=sum(head1,head2,head3);
    display(head3);
    return 0;
}
