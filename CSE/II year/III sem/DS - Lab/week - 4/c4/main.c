#include<stdio.h>
#define MAX 30
int top=-1;
int stack[MAX];

void push(char);
char pop();
main()
{
    char exp[MAX];
    printf("Enter an algebraic expression : ");
    gets(exp);
    check(exp);
}
void check(char exp[] )
{
    int i;
    char temp;
    for(i=0;i<strlen(exp);i++)
    {
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
            push(exp[i]);
        if(exp[i]==')' || exp[i]=='}' || exp[i]==']')
            temp=pop();}
    if(top==-1){printf("Balanced Parentheses\n");}
    else {printf("mismatched Parentheses\n");}
    }


void push(char item)
{
    if(top==(MAX-1))
    {
        printf("Stack Overflow\n");
        return;
    }
    top=top+1;
    stack[top]=item;
}/*End of push()*/

char pop()
{
    if(top==-1)
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    return(stack[top--]);
}/*End of pop()*/
