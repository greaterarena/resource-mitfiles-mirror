#include <stdio.h>
#include <stdlib.h>

int tr = 0;

int tower (int n, int source, int temp, int destination)
{
	if(n==1)
	{
	    // printf("move disk1 from %d to %d\n",source,destination);
	     tr++;
	     return;
	}

	/*moving n-1 disks from A to B using C as auxiliary*/
	tower(n-1, source, destination, temp);

	//printf("move disk %d from %d to %d\n",n,source,destination);
	tr++;

	/*moving n-1 disks from B to C using A as auxiliary*/
	tower(n-1, temp, source, destination);
	return tr;
}

int main(){
    int n, s, d, t,z;
    printf("enter the number of disks ->");
    scanf("%d",&n);
    printf("enter the source auxilliary and destination poles ->");
    scanf("%d %d %d",&s,&t,&d);
    z = tower(n,s,t,d);
    printf("moves -> %d",z);
}
