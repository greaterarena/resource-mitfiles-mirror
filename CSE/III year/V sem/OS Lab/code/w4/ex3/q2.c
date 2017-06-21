#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
	pid_t pid;
	int status;
	pid = fork();
	switch(pid){
		case -1 : perror("fork failed");exit(1);break;
		case  0 : sleep(3);printf("Child\n");exit(0);break;
		default : wait(&status);printf("Parent - %d\n",status);break;
	}
	return 0;
}
