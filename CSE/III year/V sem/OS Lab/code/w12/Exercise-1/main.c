#include <stdio.h>
#define READ 0       /* The index of the read end of the pipe */
#define WRITE  1   /* The index of the write end of the pipe */
char* phrase = "Stuff this in your pipe and smoke it";
char* phrase1 = "Stuff this in your pipe and explode it";
int main()
{
    int fd[2], bytesRead;
    char message[100];
    char message1[100];   /* Parent process’ message buffer */
    pipe(fd);  /* Create an unnamed pipe */
    if(fork() == 0)  /* child, writer */
    {
        close(fd[READ]);  /* close unused end */
        write(fd[WRITE], phrase, strlen(phrase) + 1); /* close unused end */
        write(fd[WRITE], phrase1, strlen(phrase1) + 1);  /* include NULL */
        close(fd[WRITE]);
    }
    else  /* Parent, reader */
    {
        close(fd[WRITE]); /* close unused end */
        bytesRead = read(fd[READ], message,100);
        printf("Read %d bytes: %s\n",bytesRead, message);
        bytesRead = read(fd[READ], message1,100);
        printf("Read %d bytes: %s\n",bytesRead, message1); /* send */
        close(fd[READ]);
    }
}
