#include <stdio.h>
#define max_size 10

struct deq
{
    int r,f;
    int a[max_size];
};

int deleteleft(struct deq * q)
{
    int a=q->a[q->f];
    if(q->f==q->r)
    {
        q->f=0;
        q->r=-1;
    }
    else
        q->f++;
    return a;
}

void addleft(struct deq * q,int ele)
{
    if(q->r==-1)
    {
        q->r=0;
        q->a[q->f]=ele;
    }
    else
    {
        q->f--;
        q->a[q->f]=ele;
    }
}

int deleteright(struct deq * q)
{
   int a=q->a[q->r];
    if(q->f==q->r)
    {
        q->f=0;
        q->r=-1;
    }
    else
        q->r--;
    return a;
}

void showq(struct deq * q)
{
    int i=q->f;
    if(q->r<q->f)
        printf("\nQueue/stack is Empty");
    else
    {
        for(i=q->f;i<=q->r;i++)
            printf("%d\t",q->a[i]);
    }

}

int main()
{
    int ch;
    int ele;
    struct deq q,q1;
    q.f=max_size;
    q.r=max_size-1;
    q1.f=max_size;
    q1.r=max_size-1;
    printf("\n1.insert queue\t2.delete queue\t3.display queue\n4.push stack\t5.pop stack\t6.display stack\n7.exit");
    while(1)
    {
            printf("\n\nEnter Your Choice: ");
            scanf("%d",&ch);

            switch(ch)
            {
                case 1:if(q.f==0 && q.r!=-1) printf("\ninsertion invalid");
                        else
                        {
                            printf("\nEnter The Number: ");
                            scanf("%d",&ele);
                            addleft(&q,ele);
                        }  break;

                case 4:if(q1.f==0 && q1.r!=-1) printf("\ninsertion invalid");
                        else
                        {
                            printf("\nEnter The Number: ");
                            scanf("%d",&ele);
                            addleft(&q1,ele);
                        }  break;

                case 5: if(q1.r<q1.f) printf("\nStack Empty");
                        else
                        printf("\nElement Deleted from Stack Is - %d",deleteleft(&q1));
                        break;

                case 2: if(q.r<q.f)
                        printf("\nQueue Empty");
                        else
                        printf("\nElement Deleted from Queue Is - %d",deleteright(&q));
                        break;
                case 3: showq(&q);
                        break;

                case 6: showq(&q1);
                        break;
                case 7: exit(0);

                default:printf("\nIncorrect Choice Entered, Please Enter Again!!");
            }
    }
    return 0;
}
