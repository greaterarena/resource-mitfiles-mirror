#include<stdio.h>
#include<stdlib.h>
int main()
{
	int pid;
	int status;
	pid=fork();
	if(pid==-1)
		printf("\nChild not created");
	else if(pid!=0) 
	{	
		wait(&status);		
		printf("\nParent pid=%d and ppid=%d and status=%d", getpid(), getppid(), status>>8);		
	}
	
	else
	{
		printf("\nChild pid=%d and ppid=%d ",getpid(), getppid());
		exit(44);
	}
	return 0;
}  
