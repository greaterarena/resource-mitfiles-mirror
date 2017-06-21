#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include <sys/wait.h>
#include<stdlib.h>
int stop=0;
void alarmHandler(int signo)
{
	//signal(SIGALRM, SIG_IGN);          /* ignore this signal       */
  stop =1;
  }
int main()
{
	signal(SIGALRM, alarmHandler);
	alarm(1);
	while(!stop)
	{
		
		printf("Running loop!\n");

	}
	printf("Loop terminated by Alarm!");
	return 0;
}
