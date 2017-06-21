#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#define READ 0
#define WRITE  1
char* rx_mess = "Receivers Message";
char* tx_mess = "Transmitters Message";
int main()
{
    int fd, bytesRead;
    char m1[100];
    char m2[100];
    if(fork() == 0)
    {
        do {
			fd= open("apipe",O_WRONLY);
			if(fd == -1)
			sleep(1);
		} while(fd==-1);			
		write(fd, rx_mess, strlen(rx_mess) + 1);
        close(fd);
		
		fd=open("apipe", O_RDONLY);	
        bytesRead = read(fd, m2,100);
        if(bytesRead==0)
			printf("\nError Nothing Read");
		else
			printf("RX PRINTING %d BYTES: %s\n",bytesRead, m2);
        close(fd);
		printf("\nchild death");
    }
    else
    {
		unlink("apipe"); 
		mknod("apipe", S_IFIFO, 0);
		chmod("apipe",0660);
		
		fd=open("apipe", O_RDONLY);	
        bytesRead = read(fd, m1,100);
		if(bytesRead==0)
			printf("\nError Nothing Read");
		else
			printf("TX PRINTING %d BYTES: %s\n",bytesRead, m1);
		close(fd);
		
		do {
			fd= open("apipe",O_WRONLY);
			if(fd == -1)
			sleep(1);
		} while(fd==-1);			
		write(fd, tx_mess, strlen(tx_mess) + 1);
        close(fd);
	
		sleep(2);
		printf("\nparent death\n");
    }
}
