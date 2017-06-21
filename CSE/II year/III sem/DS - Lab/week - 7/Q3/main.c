#include <stdio.h>
#include<string.h>
#define row 5
#define str_size 20
struct deq
{
    int r,f;
    int a[row][str_size];
};

void addright(struct deq * q,char * ele)
{
    strcpy(q->a[++(q->r)],ele);
}

char * deleteleft(struct deq * q)
{
    char * a=q->a[q->f];
    if(q->f==q->r)
    {
        q->f=0;
        q->r=-1;
    }
    else
        q->f++;
    return a;
}

void addleft(struct deq * q,char * ele)
{
    if(q->r==-1)
    {
        q->r=0;
        strcpy(q->a[q->f],ele);
    }
    else
    {
        q->f--;
        strcpy(q->a[q->f],ele);
    }


}

void showq(struct deq * q)
{
    int i=q->f;
    if(q->r<q->f)
        printf("\nDouble Ended Que is Empty");
    else
    {
        for(i=q->f;i<=q->r;i++)
            printf("%s\t",q->a[i]);
    }

}

int main()
{
    int ch;
    char ele[str_size];
    struct deq q,q1;
    q.f=0;
    q.r=-1;
    q1.f=row;
    q1.r=row-1;
    printf("\n1.insert queue\t2.delete queue\t3.display queue\n4.push stack\t5.pop stack\t6.display stack\n7.exit");
    while(1)
    {
            printf("\n\nEnter Your Choice: ");
            scanf("%d",&ch);

            switch(ch)
            {
                case 4: if(q1.f==0 && q1.r!=-1)
                        printf("\ninsertion invalid");
                        else
                        {
                            printf("\nEnter The String: ");
                            scanf("%s",&ele);
                            addleft(&q1,ele);
                        }
                        break;

                case 1: if(q.r==4)
                        printf("\ninsertion invalid");
                        else
                        {
                            printf("\nEnter The String: ");
                            scanf("%s",&ele);
                            addright(&q,ele);
                        }
                    break;

                case 2: if(q.r<q.f)
                        printf("\nQueue Empty");
                        else
                        printf("\nString Deleted from Left Is - %s",deleteleft(&q));
                        break;

                case 5: if(q1.r<q1.f)
                        printf("\nQueue Empty");
                        else
                        printf("\nString Deleted from Left Is - %s",deleteleft(&q1));
                        break;

                case 3: showq(&q);
                        break;

                case 6: showq(&q1);
                        break;

                case 7: exit(0);

                default: printf("\nIncorrect Choice Entered, Please Enter Again!!");

            }
    }

    return 0;

}
