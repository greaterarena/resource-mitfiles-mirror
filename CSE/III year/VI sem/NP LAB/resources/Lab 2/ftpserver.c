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
  int sock_fd = ____; // Make appropriate socket(...) call
  if(____) { // Check error condition
    perror("socket failed"); return -1;
  }
  struct sockaddr_in serv_addr;

  //---------- Checkpoint-1a: comment out the rest of this function to test until here ----------//

  /* bind, listen */
  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = _____;
  serv_addr.sin_addr.s_addr = _____;
  serv_addr.sin_port = _____;
  if(bind(____, ____, ____) < 0) {
    perror("bind"); close(sock_fd); return -1;
  }

  //---------- Checkpoint-1b: comment out the rest of this function to test until here ----------//

  if(listen(____, SOMAXCONN) < 0) {
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
    int conn_sock_fd = _____; // Make appropriate accept(...) call
    if(conn_sock_fd < 0) {
      perror("accept");
      continue;
    }

    //---------- Checkpoint-2: comment out the code below to test until here ----------//

    strcpy(cl_str, _____); // Convert IP address to string for printing
    printf("Connection from %s:%d\n", cl_str, ntohs(_____));

    //---------- Checkpoint-3: comment out the code below to test until here ----------//

    // Read filename from client
    char filename[256];
    int recd_len = ____; // Make appropriate recv(...) call
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
      ____; // Make appropriate send(...) call
    }
    close(conn_sock_fd);
    fclose(file2read);
    printf("Done sending file %s\n", filename);

    //---------- Checkpoint-5: If you've completed until here then you can test the whole functionality once ----------//

    //---------- Checkpoint-6: UNCOMMENT the line below to test forever loop ----------//
    //loop = 1;
  } while(loop);

} // End main()
