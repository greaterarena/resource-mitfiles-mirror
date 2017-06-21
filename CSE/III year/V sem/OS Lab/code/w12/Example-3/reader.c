#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>    /* for S_IFIFO, file mode */
#include<fcntl.h>
main()
{
    int fd;
    char str[100];
    unlink("apipe");  /* remove named pipe if it already exists */
    mknod("apipe", S_IFIFO, 0);  /* Create named pipe */
    chmod("apipe",0660);
    fd=open("apipe", O_RDONLY);  /* open it for reading */
    while(readLine(fd,str))  /* display received message */
    printf("%s\n",str);
    close(fd);  /* close pipe */
}

int readLine(fd,str)
int fd;
char* str;
/* read a single NULL – terminated line into str from fd */
/* return 0 when the end-of-input is reached and 1 otherwise */
{
    int n;
    do  /* Read characters until NULL or end-of-input */
    {
        n=read(fd,str,1);  /* read one character */
    }
    while(n>0 && *str++ != NULL);
    return(n>0);  /* return false if end-of-input */
}
