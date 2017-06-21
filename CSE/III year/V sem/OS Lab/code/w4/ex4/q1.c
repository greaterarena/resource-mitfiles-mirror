#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
	pid_t pid;
	pid = fork();
	switch(pid){
		case -1 : perror("fork failed");exit(1);break;
		case  0 : execlp("/bin/ls","ls",NULL);break;
		default : sleep(5);printf("Parent\n");break;
	}
	return 0;
}
