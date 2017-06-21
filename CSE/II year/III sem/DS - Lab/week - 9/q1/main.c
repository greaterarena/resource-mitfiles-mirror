#include <stdio.h>
#include <stdlib.h>

struct node
{
    int c,exp;
    struct node* link;
};
typedef struct node NODE;
typedef struct node* nodeptr;

nodeptr insertend(nodeptr head,int d1,int d2)
{
    nodeptr temp,curr;
    temp=(nodeptr)malloc(sizeof(NODE));
    temp->c=d1;
    temp->exp=d2;
    temp->link=NULL;
    if(head->link==NULL)
    {
        head->link=temp;
        temp->link=head;
        return head;
    }
    curr=head->link;
    while(curr->link!=head)
    {
        curr=curr->link;
    }
    curr->link=temp;
    temp->link=head;
    return head;
}
nodeptr add(nodeptr head1,nodeptr head2,nodeptr result)
{
    nodeptr one,two;int flag;
    one=head1->link;
    two=head2->link;
    while(one!=head1)
    {
        flag=0;
        while(two!=head2)
        {
            if(one->exp==two->exp)
            {
                flag=1;
                break;
            }
            two=two->link;
        }
        if(flag==1)
        {
            result=insertend(result,(one->c+two->c),one->exp);
        }
        else
        {
            result=insertend(result,one->c,one->exp);
        }
        one=one->link;
    }
    while(two!=head2)
    {
        flag=0;
        while(one!=head1)
        {
            if(one->exp==two->exp)
            {
                flag=1;
                break;
            }
            one=one->link;
        }
        if(flag==0)
        {
            result=insertend(result,two->c,two->exp);
        }
        two=two->link;
    }
    return result;
}
nodeptr subtract(nodeptr head1,nodeptr head2,nodeptr result)
{
    nodeptr one,two;int flag;
    one=head1->link;
    two=head2->link;
    while(one!=head1)
    {
        flag=0;
        while(two!=head2)
        {
            if(one->exp==two->exp)
            {
                flag=1;
                break;
            }
            two=two->link;
        }
        if(flag==1)
        {
            result=insertend(result,(one->c-two->c),one->exp);
        }
        else
        {
            result=insertend(result,one->c,one->exp);
        }
        one=one->link;
    }
    while(two!=head2)
    {
        flag=0;
        while(one!=head1)
        {
            if(one->exp==two->exp)
            {
                flag=1;
                break;
            }
            one=one->link;
        }
        if(flag==0)
        {
            result=insertend(result,two->c,two->exp);
        }
        two=two->link;
    }
    return result;
}

void disp(nodeptr head)
{
    nodeptr curr=head->link;
    printf("\nPRINTING :");
    while(curr!=head)
    {
        printf("+%d*x^%d ",curr->c,curr->exp);
        curr=curr->link;
    }
}
int main()
{
    nodeptr head1,head2,result;
    int d1,d2,ch,flag;
    head1=(nodeptr)malloc(sizeof(NODE));
    head2=(nodeptr)malloc(sizeof(NODE));
    result=(nodeptr)malloc(sizeof(NODE));
    head1->link=NULL;
    head2->link=NULL;
    result->link=NULL;
    do
    {
        printf("\n1.Enter in list 1\n2.Enter in list 2\n3.Add and Display\n4.Subtract and Display :");
        scanf("%d",&ch);flag=0;
        switch(ch)
        {
            case 1:printf("\nEnter coeff :");
                    scanf("%d",&d1);
                    printf("\nEnter exponent :");
                    scanf("%d",&d2);
                    head1=insertend(head1,d1,d2);
                    break;
            case 2:printf("\nEnter coeff :");
                    scanf("%d",&d1);
                    printf("\nEnter exponent :");
                    scanf("%d",&d2);
                    head2=insertend(head2,d1,d2);
                    break;
            case 3:result=add(head1,head2,result);
                   disp(result);
                   break;
            case 4:result=subtract(head1,head2,result);
                   disp(result);
                   break;
            default:flag=1;
        }
    }while(flag!=1);
    return 0;
}
