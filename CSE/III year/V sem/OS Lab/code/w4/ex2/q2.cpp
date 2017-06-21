#include <stdio.h>
#include <unistd.h>

using namespace std;

int main(){
    pid_t pid;
    printf("INIT FORK");
    pid = fork();
    switch(pid){
        case -1: printf("\nfork failed");return 0; break;
        case 0: printf("\nCHILD: ID - %d | PARENT ID - %d\n",getpid(),getppid());
                sleep(5);
                printf("\nCHILD: ID - %d | PARENT ID - %d\n",getpid(),getppid());
                break;
        default : sleep(1);break;
    }

	return 0;
}
