#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <strings.h>
#include <string.h>
#include <sys/time.h>

void usage(const char *progname) {
  fprintf(stderr, "Usage: %s <server-port>\n", progname);
} // End usage()

int sock_and_listen(int port) {
  int sock_fd = socket(AF_INET, SOCK_STREAM, 0); // Make appropriate socket(...) call
  if(sock_fd == -1) { // Check error condition
    perror("socket failed"); return -1;
  }
  struct sockaddr_in serv_addr;

  //---------- Checkpoint-1a: comment out the rest of this function to test until here ----------//

  /* bind, listen */
  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
  serv_addr.sin_port = htons(port);
  if(bind(sock_fd, (struct sockaddr *)&serv_addr, sizeof(struct sockaddr)) < 0) {
    perror("bind"); close(sock_fd); return -1;
  }

  //---------- Checkpoint-1b: comment out the rest of this function to test until here ----------//

  if(listen(sock_fd, SOMAXCONN) < 0) {
    perror("listen"); close(sock_fd); return -1;
  }
  return sock_fd;
}

int main(int argc, char *argv[]) {
  if(argc != 2) {
    usage(argv[0]);
    exit(1);
  }

  int server_port = atoi(argv[1]);

  int listen_sock_fd = -1;

  listen_sock_fd = sock_and_listen(server_port);
  if(listen_sock_fd == -1) { perror("sock_and_listen"); exit(100); }
  fprintf(stderr, "Listening on port %d\n", server_port);

  int loop = 0;
  do {
        printf("Waiting for connection from client...\n");
        struct sockaddr_in cl_addr;
        int cl_addr_size = sizeof(cl_addr);
        char cl_str[1024];
        int conn_sock_fd = accept(listen_sock_fd, &cl_addr, &cl_addr_size);
        if(conn_sock_fd < 0) {
          perror("accept");
          continue;
        }

        strcpy(cl_str, inet_ntoa(cl_addr.sin_addr));
        printf("Connection from %s:%d\n", cl_str, ntohs(cl_addr.sin_port));

        loop = 1;
        char message[256];
        int recd_len = recv( conn_sock_fd, message, 256, 0 );
        if(recd_len < 0) {
          perror("recv");
          close(conn_sock_fd);
          continue;
        }
        message[sizeof(message)-1] = '\0';
        printf("Got Message %s from client\n", message);
        close(conn_sock_fd);
  } while(loop);
}
