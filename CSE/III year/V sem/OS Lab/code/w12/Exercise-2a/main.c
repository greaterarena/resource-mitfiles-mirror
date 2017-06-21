#include <stdio.h>
#include <string.h>
#define READ 0
#define WRITE  1
char* rx_mess = "Receivers Message";
char* tx_mess = "Transmitters Message";
int main()
{
    int fd[2], bytesRead;
    char m1[100];
    char m2[100];
    pipe(fd);
    if(fork() == 0)
    {
        write(fd[WRITE], rx_mess, strlen(rx_mess) + 1);
        close(fd[WRITE]);

        bytesRead = read(fd[READ], m2,100);
        if(bytesRead==0)
		printf("\nError Nothing Read");
	else
		printf("RX PRINTING %d BYTES: %s\n",bytesRead, m2);
        close(fd[READ]);
	printf("\nchild death");
    }
    else
    {
        bytesRead = read(fd[READ], m1,100);
	if(bytesRead==0)
		printf("\nError Nothing Read");
	else
        	printf("TX PRINTING %d BYTES: %s\n",bytesRead, m1);
        close(fd[READ]);

	write(fd[WRITE], tx_mess, strlen(tx_mess) + 1);
        close(fd[WRITE]);
	
	sleep(2);
	printf("\nparent death\n");
    }
}
