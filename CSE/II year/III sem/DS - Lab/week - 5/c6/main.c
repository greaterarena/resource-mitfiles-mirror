#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct st
{
    int top;
    char a[10][10];
};

typedef struct st S;

void push(char * a, S *s)
{
    strcpy(s->a[(s->top)++],a);
}

char* pop(S *s)
{
    return s->a[--(s->top)];
}
int main()
{
    S s;
    s.top=0;
    char pre[10],rpre[10],post[10],b[10],a[2];
    int i,len,j=0;
    post[0]='\0';
    printf("exp: ");
    gets(pre);
    len=strlen(pre);

    for(i=len-1;i>-1;i--)
        rpre[j++]=pre[i];
    rpre[j]='\0';

    for(i=0;i<len;i++)
    {
        if(isalnum(rpre[i]))
        {
            b[0]=rpre[i];
            b[1]='\0';
            push(b,&s);
        }
        else
        {
            a[0]='\0';
            strcpy(post,a);
            b[0]=rpre[i];
            b[1]='\0';
            strcat(post,pop(&s));
            strcat(post,pop(&s));
            strcat(post,b);
            push(post,&s);
        }
    }
    printf("\npostfix: ");
    puts(s.a[s.top-1]);
    return 0;
}
