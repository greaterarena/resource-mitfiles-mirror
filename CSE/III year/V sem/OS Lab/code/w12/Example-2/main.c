#include<unistd.h>
#define READ 0
#define WRITE 1

int main(argc, argv)int argc; char* argv [];
{
    int fd[2];
    pipe(fd);  /* create an unnamed pipe */
    if(fork() != 0)  /* Parent, writer */
    {
        close(fd[READ]);
        dup2(fd[WRITE],1);  /* Duplicate used end to stdout */
        close(fd[WRITE]);
        execlp(argv[1],argv[1],NULL);  /* Execute writer program */
        perror("connect");
    }
    else   /* Child, reader */
    {
        close(fd[WRITE]);
        dup2(fd[READ],0);  /* Duplicate used end to stdin */
        close(fd[READ]);
        execlp(argv[2], argv[2],NULL);  /* Execute reader program */
        perror("connect");
    }
}
