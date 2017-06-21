#include <stdio.h>
#include <stdlib.h>
void push (int,int[],int*);
void pop (int[],int*);
int main()
{
int a[50], num,r,top;
top=-1;
printf("enter the decimal number to be converted \n");
scanf("%d",&num);
while (num!=0)
{
    r=num%2;
    push(r,a,&top);
     num=num/2;
}
pop(a,&top);
return 1;
}
void push(int r,int a[],int *top)
{
    (*top)++;
    a[(*top)]=r;
}
void pop(int a[],int *top)
{
    while(*top!=-1)
    {
        printf("%d",a[*top]);
        (*top)--;
    }
}
