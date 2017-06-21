#include <stdio.h>
#include <stdlib.h>

void dectobin(int a)
{ if(a != 0) { dectobin(a / 2); printf("%d", a%2);}}


int main(){
    int n;
    printf("enter a decimal number ->");
    scanf("%d",&n);
    printf("\nbinary equivalent -> ");
    dectobin(n);
}
