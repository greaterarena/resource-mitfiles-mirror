#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include <sys/wait.h>
#include<stdlib.h>
int main()
{
	int pid,i;
	pid=fork();
	if(pid<0)
	{
		printf("Fork failed");
		exit(-1);
	}
	if(pid==0)
	{
		
		for(i=0;i<=10;i=i+2)
		{
			printf("Child process: ");
		   printf("%d\n", i);
	   }
	}
	if(pid>0)
	{
		
		nice(10);
		for(i=1;i<=10;i=i+2)
		{
			printf("Parent process: ");
		   printf("%d\n", i);
	   }
		
	}
	return 0;
}
