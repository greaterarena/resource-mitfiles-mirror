#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct st
{
    int top1,top2;
    char a[20];
};

typedef struct st S;

void push(S *s, char ch, int a)
{
    switch(a)
    {
        case 1: if(s->top1==10)
                    {printf("\nstack 1 overflow."); return;}
                s->a[(s->top1)++]=ch;break;
        case 2: if(s->top2==20)
                  {printf("\nstack 2 overflow."); return;}
                s->a[(s->top2)++]=ch;break;
    }
}

char pop(S *s,int a)
{
    switch(a)
    {
        case 1: if(s->top1==0)
                    {printf("\n stack 1 underflow.");return;}
                return s->a[--(s->top1)];
        case 2: if(s->top2==10)
                    {printf("\n stack 2 underflow.");return;}
                return s->a[--(s->top2)];
    }

}


int main()
{
    S s;
    s.top1=0;
    s.top2=10;
    int a;
    char b;
    while(1)
    {
        printf("\n1.push stack-1  2.push stack-2 3. pop stack-1 4. pop stack-2: ");
        scanf("%d",&a);
        switch(a)
        {
            case 1: printf("\nvalue: ");
                    scanf("%s",&b);
                    push(&s,b,1);break;
            case 2: printf("\nvalue: ");
                    scanf("%s",&b);
                    push(&s,b,2);break;
            case 3: printf("popped element: %c", pop(&s,1));
                    break;
            case 4: printf("popped element: %c", pop(&s,2));
                    break;
            default: return 0;

        }
    }
return 0;
}
