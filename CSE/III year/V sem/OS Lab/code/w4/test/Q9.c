#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include <sys/wait.h>
#include<stdlib.h>
int main()
{
alarm(3);
	while(1)
	{
		
		printf("Running loop!\n");

	}
	return 0;
}

