#include <stdio.h>
#include <stdlib.h>

void add(int *x, int *y){ /* passing pointer to function*/
        int sum = *x + *y;
        printf("sum -> %d", sum);
}

int divt(int x, int y){ /* passing pointer to function*/
        int *div;
        int z = x / y;
        printf("\n z = %d \n", z);
        div = &z;
        return div;
}

int main()
{
    int x,y,*q,*w;
    printf("enter 2 elements->");
    scanf("%d %d", &x, &y);
    q = &x;
    w = &y;
    add (q, w);
    int *divd = divt(x, y);
    printf("\n%d / %d = %d",x,y,*divd);
    int p2p = 911;
    /* pointer to pointer */
    int *p;
    int **pp;
    p = &p2p;
    pp = &p;
    printf("\n\ndivx = %d divd = %d div = %d",**pp,*p,p2p);
    return 0;
}
