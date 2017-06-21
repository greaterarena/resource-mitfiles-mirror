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

                char* new_filename = "hello1.c";
                FILE *local_file = fopen(new_filename, "w");
                if(local_file == NULL) {
                  perror("Can't open file to write");
                  close(sockfd);
                  continue;
                }
                printf("%d bytes recvd", numbytes);
                fwrite(buf, 1, numbytes, local_file);
                fclose(local_file);

                system("gcc hello1.c -o hello");
                system("./hello >> output");

                int temp_sock;

                if ((temp_sock = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
                    perror("socket");
                    exit(1);
                }

                FILE *file2read = fopen("output", "r");
                if(file2read == NULL) {
                  perror("file open");
                  close(sockfd);
                  continue;
                }

                char buf[2000];
                int num_read = 0;
                int numbytes;
                while((num_read = fread(buf, 1, sizeof(buf), file2read)) > 0) {
                  if ((numbytes = sendto(temp_sock, buf, num_read, 0,(struct sockaddr *)&their_addr, sizeof(struct sockaddr))) == -1) {
                    perror("recvfrom");
                    exit(1);
                  }
                }

                printf("%d: reply sent %d\n",child_id);
            }
        }
    }
    close(sockfd);
    return 0;
}
