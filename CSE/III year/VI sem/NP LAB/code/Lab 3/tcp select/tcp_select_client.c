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
}

int sock_and_connect(struct in_addr server_ip, int port) {
  int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
  if(sock_fd == -1) {
    perror("socket failed"); return -1;
  }
  struct sockaddr_in serv_addr;

  serv_addr.sin_addr.s_addr = inet_addr(DEST_IP);
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(port);

  memset(&(serv_addr.sin_zero), '\0', 8);

  int res = connect(sock_fd, (struct sockaddr *)&serv_addr, sizeof(struct sockaddr));
  if(res == 0) { return sock_fd; }
  else { perror("connect failed"); return -1; }

}

int main(int argc, char *argv[]) {
  if(argc != 3) {
    usage(argv[0]);
    exit(1);
  }

  const char *server_str = argv[1];
  struct in_addr server_addr;
  if (inet_aton(server_str, &server_addr) == 0) {
    fprintf(stderr, "Invalid address: %s\n", server_str);
    exit(2);
  }

  int server_port = atoi(argv[2]);


  int loop = 0;
  do {
    char message[256];
    printf("Enter Message to Send: ");
    scanf("%s", message);
    message[sizeof(message)-1] = '\0';
    int message_len = strlen(message);

    int sock_fd = sock_and_connect(server_addr, server_port);
    if(sock_fd == -1) {
      fprintf(stderr, "Unable to connect to server\n");
      continue;
    }
    loop=1;
    send(sock_fd, message, 256, 0);
    close(sock_fd);
  } while(loop);
}
