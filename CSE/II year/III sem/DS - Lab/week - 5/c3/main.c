#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *data;
    int top;
    int max;
}stack;

void in(stack *t, int max){
    char* test;
    int i;
    test=(char *)malloc(sizeof(char)*max);
    if(test==NULL){printf("you are dead jim\n");exit(0);}
    t->data=test;
    t->top=-1;
    t->max=max;
}

void del(stack *t){
    free(t->data);
    t->data=NULL;
    t->top=-1;
    t->max=0;
}

int isfull(stack *t){
    return t->top >= t->max-1;
}
int isempty(stack *t){
    return t->top < 0;
}

void push(stack *t, char y){
    if(isfull(t)){printf("stack is full"); exit(0);}
    else
    t->data[++t->top] = y;
}

char pop(stack *t){
    if(isempty(t)){printf("stack is empty"); exit(0);}
    else
        return t->data[t->top--];
}

int prcdi(char x){
    switch(x){
    case '+':
    case '-':return 1;break;
    case '*':
    case '/':return 3;break;
    case '$':return 6;break;
    case '(':return 7;break;
    case ')':return 0;break;}
}

int prcds(char x){
    switch(x){
    case '+':
    case '-':return 2;break;
    case '*':
    case '/':return 4;break;
    case '$':return 5;break;
    case '(':return 0;break;
    default: return -3;break;}
}


int main()
{
    char y[200],out[200],flag=0,u[200];
    int i=0,j=0,t=0;
    stack x;
    gets(y);
    in(&x,strlen(y));
    while(y[i]!='\0'){
    if(isalnum(y[i])){out[j++]=y[i];}
    else {
        while(x.top!=-1 && prcds(x.data[x.top])>prcdi(y[i])){
            out[j++]=pop(&x);
        }
        if(x.top==-1 || prcdi(y[i])!=prcds(x.data[x.top]))
            push(&x,y[i]);
        else
            pop(&x);
            flag+=2;
    }
    i++;
    }

    while(x.top!=-1){
        out[j++]=pop(&x);
    }
    puts(out);
    del(&x);
    return 0;
}

