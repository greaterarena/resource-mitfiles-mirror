#include<stdio.h>
#include<stdlib.h>
int main()
{
	int pid;
	pid=fork();
	if(pid==-1)
		printf("\nChild not created");
	else if(pid==0)
	{
		printf("\nChild pid=%d and ppid=%d",getpid(), getppid());
		exit(0);
	}
	else 
	{	
		printf("\nParent pid=%d and ppid=%d", getpid(), getppid());		
		pause();
	}
	return 0;
}  
