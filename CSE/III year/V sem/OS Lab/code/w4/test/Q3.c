#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{ 
	int pid;	
	pid = fork();
	if (pid == -1)
     		printf("Fork Failed");
   	else if (pid == 0)
     		printf("\nProcess ID of Child: %d \tProcess ID of Parent: %d", getpid(), getppid());
   	else
      		printf("\nProcess ID of Parent: %d \tProcess ID of GrandParent: %d", getpid(), getppid());
	return 0;
}
