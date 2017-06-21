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

#define DEST_IP "127.0.0.1"
#define DEST_PORT 6893

void usage(const char *progname) {
  fprintf(stderr, "Usage: %s <server-IP> <server-port>\n", progname);
} // End usage()

int sock_and_connect(struct in_addr server_ip, int port) {
  int sock_fd = socket(AF_INET, SOCK_STREAM, 0); // Make appropriate socket(...) call
  if(sock_fd == -1) { // Check error condition
    perror("socket failed"); return -1;
  }
  struct sockaddr_in serv_addr;

  //---------- Checkpoint-1a: comment out the rest of this function to test until here ----------//

  /* blocking connect */
  serv_addr.sin_addr.s_addr = inet_addr(DEST_IP);
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(port);

  memset(&(serv_addr.sin_zero), '\0', 8);

  int res = connect(sock_fd, (struct sockaddr *)&serv_addr, sizeof(struct sockaddr));
  if(res == 0) { return sock_fd; } // connection formed
  else { perror("connect failed"); return -1; }

} // End sock_and_connect()

int main(int argc, char *argv[]) {
  if(argc != 3) {
    usage(argv[0]);
    exit(1);
  }

  // Get the IP address as an in_addr structure, from the string
  const char *server_str = argv[1];
  struct in_addr server_addr;
  if (inet_aton(server_str, &server_addr) == 0) {
    fprintf(stderr, "Invalid address: %s\n", server_str);
    exit(2);
  }

  // Get the server port from the command-line
  int server_port = atoi(argv[2]);

  //---------- Checkpoint-0: comment out the code below to test until here ----------//

  int loop = 0;
  do {
    char filename[256];
    // Get filename from STDIN
    printf("Enter filename: ");
    scanf("%s", filename);
    filename[sizeof(filename)-1] = '\0'; // For additional safety
    int filename_len = strlen(filename);

    // Make connection to server
    int sock_fd = sock_and_connect(server_addr, server_port);
    if(sock_fd == -1) {
      fprintf(stderr, "Unable to connect to server\n");
      continue;
    }
    loop=1;
    //---------- Checkpoint-2: comment out the code below to test until here ----------//

    // Send filename via TCP connection to server
    send(sock_fd, filename, 256, 0);

    //---------- Checkpoint-4: comment out the code below to test until here ----------//

    // Read file contents via TCP connection and store to local file
    char new_filename[266];
    sprintf(new_filename, "%s-dl", filename);
    FILE *local_file = fopen(new_filename, "w");
    if(local_file == NULL) {
      perror("Can't open file to write");
      close(sock_fd);
      continue;
    }
    char recv_buf[2000];
    int num_recd;
    while((num_recd = recv( sock_fd, recv_buf, 2000, 0)) > 0) {
      printf("%d bytes recvd", num_recd);
      fwrite(recv_buf, 1, num_recd, local_file);
    }
    fclose(local_file);
    close(sock_fd);
    printf("Written file %s successfully\n", new_filename);

    /*//---------- Checkpoint-5: If you've completed until here then you can test the whole functionality once ----------//

    //---------- Checkpoint-6: UNCOMMENT the line below to test forever loop ----------//
    //loop = 1;*/
  } while(loop);

} // End main()
