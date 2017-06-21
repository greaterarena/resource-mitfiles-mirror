#include<stdio.h>
#include<fcntl.h>
main()
{
    int fd, messageLen,i;
    char message[100];
    /* prepare message */
    sprintf(message, "Hello from PID %d", getpid());
    messageLen = strlen(message) + 1;
    do  /* keep trying to open the file  until successful */
    {
        fd= open("apipe",O_WRONLY); /* open named pipe for writing */
        if(fd == -1)
        sleep(1);  /* Try again in 1 sencond */
    }

    while(fd==-1);
    for(i=1; i<=3; i++)  /* send three messages */
    {
        write(fd, message, messageLen);  /* write message down pipe */
        sleep(3);  /* pause a while */
    }
    close(fd);  /* close pipe descriptor */
}
