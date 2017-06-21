#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

#define MYPORT 7000
#define MAXBUFLEN 100 // the port users will be connecting to

int main(int argc, char *argv[])
{
    int sockfd;
    struct sockaddr_in their_addr; // connector’s address information
    struct hostent *he;
    int numbytes;

    if (argc != 2) {
        fprintf(stderr,"usage: talker hostname\n");
        exit(1);
    }

    if ((he=gethostbyname(argv[1])) == NULL) {
        perror("gethostbyname");
        exit(1);
    }
    // get the host info
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }
    their_addr.sin_family = AF_INET;
    their_addr.sin_port = htons(MYPORT);
    //their_addr.sin_addr = *((struct in_addr *)he->h_addr);
    their_addr.sin_addr.s_addr = inet_addr("172.16.59.89");
    bzero(&(their_addr.sin_zero), 8);

    if ((numbytes=sendto(sockfd, "time", 4, 0,(struct sockaddr *)&their_addr, sizeof(struct sockaddr))) == -1) {
        perror("recvfrom");
        exit(1);
    }
	//printf("sent %d bytes to %s\n", numbytes, inet_ntoa(their_addr.sin_addr));
	char buf[MAXBUFLEN];
	int addr_len = sizeof(struct sockaddr);
	while(1==1){
		 if ((numbytes=recvfrom(sockfd,buf, MAXBUFLEN, 0,(struct sockaddr *)&their_addr, &addr_len)) == -1) {
            perror("recvfrom");
            exit(1);
        }
        else{
            char subbuff[15];
            memcpy( subbuff, &buf, numbytes );
            subbuff[numbytes] = '\0';
            printf("\nSERVER TIME: %s\n", subbuff);

            time_t current_time;
            char* c_time_string;
            current_time = time(NULL);
            c_time_string = ctime(&current_time);

            printf("\nLOCAL TIME:  %s\n", c_time_string);

            close(sockfd);
            return 0;
        }
	}
    close(sockfd);
    return 0;
}
