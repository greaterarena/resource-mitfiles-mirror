#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct{
    float c[50];
    int top;
    int ms;
}s;

void init(s* x){
    x->top = -1;
    x->ms = 50;
}

int f(s*x){
    return x->top>=x->ms-1;
}

int e(s*x){
    return x->top<-1;
}

void push(s*x,float q){
    if(f(x)){
        printf("\nStack Overflow");
        return;}
    else{
        x->c[++x->top] = q;
        }
}

float pop(s*x){
    if(e(x)){
        printf("\nStack underflow");
        return;
    }
    else
        return x->c[x->top--];
}

float val(float a,float b,char z){
    switch(z){
    case '+':return (a+b);
    case '-':return (a-b);
    case '*':return (a*b);
    case '/':return (a/b);
    case '$':return (pow(a,b));
    }
}

int main()
{
    int i = 0,j=0;
    s p;
    init(&p);
    printf("enter infix string -> ");
    char t[50];
    gets(t);
    while(t[i]!='\0'){
        push(&p,t[i]);
        i++;
    }
     while(i!=0){
        t[j++]=pop(&p);
        i--;
    }
    t[j]='\0';
    while(t[i]!='\0'){
        if(isdigit(t[i])){
            float x = (float) t[i] - 48;
            push(&p,x);
        }
        else{
            float a = pop(&p);
            float b = pop(&p);
            float value = val(a,b,t[i]);
            push(&p,value);
        }
    i++;
    }
    printf("\nvalue -> %f",pop(&p));
    return 0;
}
