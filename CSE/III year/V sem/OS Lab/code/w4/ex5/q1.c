#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
	pid_t pid;
	pid = fork();
	int i,j;
	switch(pid){
		case -1 : perror("fork failed");exit(1);break;
		case  0 : sleep(1);i=0; while(1)printf("\nChild-%d",i++);break;
		default : sleep(1);j=0; nice(10);while(1)printf("\nParent-%d",j++);break;
	}
	return 0;
}
