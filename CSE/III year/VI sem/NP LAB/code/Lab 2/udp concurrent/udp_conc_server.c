#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MYPORT 7000
#define MAXBUFLEN 100


int main(void)
{
    int sockfd;
    struct sockaddr_in my_addr;
    struct sockaddr_in their_addr; // connector’s address information
    int addr_len, numbytes;
    char buf[MAXBUFLEN];
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }
    my_addr.sin_family = AF_INET; // host byte order
    my_addr.sin_port = htons(MYPORT); // short, network byte order
    my_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // automatically fill with my IP
    bzero(&(my_addr.sin_zero), 8); // zero the rest of the struct

    if (bind(sockfd, (struct sockaddr *)&my_addr, sizeof(struct sockaddr)) == -1) {
        perror("bind");
        exit(1);
    }

    addr_len = sizeof(struct sockaddr);

    while(1==1){

        if ((numbytes=recvfrom(sockfd,buf, MAXBUFLEN-1, 0,(struct sockaddr *)&their_addr, &addr_len)) == -1) {
            perror("recvfrom");
            exit(1);
        }

       else{
            if(fork()==0){
                int child_id = getpid();

				//fix this part of the code to convert to sqaure
				int i,temp = 0;

				for(i=0;i<numbytes;i++)
					temp = (temp*10) + (buf[i]-'0');

				temp = temp * temp;

				char c[20];

				//converts int to char

				sprintf(c, "%d", temp);

                int temp_sock;

                if ((temp_sock = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
                    perror("socket");
                    exit(1);
                }

				 if ((numbytes = sendto(temp_sock, c, strlen(c), 0,(struct sockaddr *)&their_addr, sizeof(struct sockaddr))) == -1) {
					perror("recvfrom");
					exit(1);
				  }


                printf("%d: reply sent %s\n",child_id, c);

        }
      }
    }
    close(sockfd);
    return 0;
}
