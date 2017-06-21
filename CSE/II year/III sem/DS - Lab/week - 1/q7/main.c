#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *x, *y, a, b;
    printf("input first number - >");
    scanf("%d", &a);
    printf("\n\ninput second number - >");
    scanf("%d", &b);

    x = &a;
    y = &b;

    int z = *x + *y;

    printf("\n sum -> %d", z) ;

}

