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

#define MYPORT 7000
#define MAXBUFLEN 100

// the port users will be connecting to
int main(int argc, char *argv[])
{
    int sockfd;
    struct sockaddr_in their_addr; // connector’s address information
    struct hostent *he;
    int numbytes;
    char buf[MAXBUFLEN];

    if (argc != 3) {
        fprintf(stderr,"usage: talker hostname message\n");
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
    their_addr.sin_addr = *((struct in_addr *)he->h_addr);
    bzero(&(their_addr.sin_zero), 8);


    FILE *file2read = fopen("hello.c", "r");
    if(file2read == NULL) {
      perror("file open");
      close(sockfd);
    }

    int num_read = 0;
    while((num_read = fread(buf, 1, sizeof(buf), file2read)) > 0) {

      if ((numbytes = sendto(sockfd, buf, num_read, 0,(struct sockaddr *)&their_addr, sizeof(struct sockaddr))) == -1) {
        perror("recvfrom");
        exit(1);
      }

      //send(conn_sock_fd, buf, num_read, 0); // Make appropriate send(...) call
    }

    printf("sent %d bytes to %s\n", numbytes, inet_ntoa(their_addr.sin_addr));

    fclose(file2read);
    printf("Done sending file Hello\n");


    int addr_len = sizeof(struct sockaddr);

    while(1==1){

        if ((numbytes=recvfrom(sockfd,buf, MAXBUFLEN-1, 0,(struct sockaddr *)&their_addr, &addr_len)) == -1) {
                perror("recvfrom");
                exit(1);
        }
        else{
            char* new_filename = "hello-out.txt";
            FILE *local_file = fopen(new_filename, "w");
            if(local_file == NULL) {
              perror("Can't open file to write");
              close(sockfd);
              continue;
            }
            printf("%d bytes recvd", numbytes);
            fwrite(buf, 1, numbytes, local_file);
            fclose(local_file);
            break;
        }
    }


    close(sockfd);
    return 0;
}
