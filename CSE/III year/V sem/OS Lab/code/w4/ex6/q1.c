#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    alarm(2);
    while(1)
        printf("tree\n");

	return 0;
}
