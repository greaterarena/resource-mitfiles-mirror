#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include <sys/wait.h>
#include<stdlib.h>

void childHandler()
{
	int childpid, childstatus;
	childpid=wait(&childstatus);
	printf(
