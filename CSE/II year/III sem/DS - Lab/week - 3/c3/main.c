#include<stdio.h>

int fib(int n)
{
	if(n==0)
		return 0;
	if(n==1)
		return 1;
	else
	{
		return fib(n-2) + fib(n-1);
    }
}


int main(){
	int f,r,i;
	printf("enter  -> ");
	scanf("%d", &f);
    for(i=0; i<f; i++)
    {r = fib(i);
	printf("%d ",r);}
}
