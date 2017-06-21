#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void alarmify(int signo)
{
    if (signo == SIGALRM){
        printf("LOL Alarm Time\n");
        exit(0);
    }
}
int main(void)
{
    if (signal(SIGALRM, alarmify) == SIG_ERR)
        printf("\ncan't catch SIGALRM\n");
    alarm(2);
    while(1)
        printf("tree\n");
    return 0;
}
