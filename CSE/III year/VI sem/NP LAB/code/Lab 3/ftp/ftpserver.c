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

#define PORT 6893

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
} // End sock_and_listen()

int main(int argc, char *argv[]) {
  if(argc != 2) {
    usage(argv[0]);
    exit(1);
  }

  // Get the server port from the command-line
  int server_port = atoi(argv[1]);

  // socket, bind and listen
  int listen_sock_fd = -1;

  listen_sock_fd = sock_and_listen(server_port);
  if(listen_sock_fd == -1) { perror("sock_and_listen"); exit(100); }
  fprintf(stderr, "Listening on port %d\n", server_port);
  //---------- Checkpoint-1: comment out the code below to test until here ----------//

  int loop = 0;
  do {
    printf("Waiting for connection from client...\n");
    // Accept connection from client
    struct sockaddr_in cl_addr;
    int cl_addr_size = sizeof(cl_addr);
    char cl_str[1024];
    int conn_sock_fd = accept(listen_sock_fd, &cl_addr, &cl_addr_size); // Make appropriate accept(...) call
    if(conn_sock_fd < 0) {
      perror("accept");
      continue;
    }

    //---------- Checkpoint-2: comment out the code below to test until here ----------//

    strcpy(cl_str, inet_ntoa(cl_addr.sin_addr)); // Convert IP address to string for printing
    printf("Connection from %s:%d\n", cl_str, ntohs(cl_addr.sin_port));

    loop = 1;

    //---------- Checkpoint-3: comment out the code below to test until here ----------//

    // Read filename from client
    char filename[256];
    int recd_len = recv( conn_sock_fd, filename, 256, 0); // Make appropriate recv(...) call
    if(recd_len < 0) {
      perror("recv");
      close(conn_sock_fd);
      continue;
    }
    if(recd_len == 0) {
      fprintf(stderr, "Recd empty filename from client\n");
      close(conn_sock_fd);
      continue;
    }
    filename[sizeof(filename)-1] = '\0'; // for additional safety
    printf("Got filename %s from client\n", filename);

    //---------- Checkpoint-4: comment out the code below to test until here ----------//

    // Send file to client
    FILE *file2read = fopen(filename, "r");
    if(file2read == NULL) {
      perror("file open");
      close(conn_sock_fd);
      continue;
    }
    char buf[2000];
    int num_read = 0;
    while((num_read = fread(buf, 1, sizeof(buf), file2read)) > 0) {
      send(conn_sock_fd, buf, num_read, 0); // Make appropriate send(...) call
    }
    close(conn_sock_fd);
    fclose(file2read);
    printf("Done sending file %s\n", filename);

    /*//---------- Checkpoint-5: If you've completed until here then you can test the whole functionality once ----------//

    //---------- Checkpoint-6: UNCOMMENT the line below to test forever loop ----------//
    //loop = 1;*/
  } while(loop);

}
