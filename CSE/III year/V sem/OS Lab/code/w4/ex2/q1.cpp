#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <string>

using namespace std;

int main(){
    pid_t pid;
    int n;
    cout<<"INIT FORK";
    pid = fork();
    switch(pid){
        case -1: cout<<"\nfork failed";return 0; break;
        case 0: printf("\nCHILD: ID - %d | PARENT ID - %d\n",getpid(),getppid());break;
        default : printf("\nPARENT: ID - %d | PARENT ID - %d\n",getpid(),getppid());break;
    }

	return 0;
}
