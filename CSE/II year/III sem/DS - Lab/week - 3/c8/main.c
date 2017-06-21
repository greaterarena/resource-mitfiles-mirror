#include <stdio.h>
#include <stdlib.h>

int mult (int a, int b) { return (b==1? a : mult(a,b-1)+a);}


int main()
{
    int a,b,c;
    printf(" first number -> ");
    scanf("%d", &a);
    printf("\n second number -> ");
    scanf("%d", &b);
    c = mult(a,b);
    printf("\n product -> %d\n",c);
    return 0;
}
