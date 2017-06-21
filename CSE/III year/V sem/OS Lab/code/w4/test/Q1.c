#include<fcntl.h>

int main()
{
	int fd1, fd2, rd, wr;
	char buf[100];
	int BUFFER_SIZE=100;
	fd1=open("file1.txt", O_CREAT | O_RDONLY, 0600);
	rd=read(fd1,buf,BUFFER_SIZE);
	fd2=open("file2.txt", O_CREAT | O_RDWR, 0600);
	wr=write(fd2, buf, rd);
	int cl1=close(fd1);
	int cl2=close(fd2);
}
