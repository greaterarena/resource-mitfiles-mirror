#include<stdio.h>
#include<fcntl.h>
int main()
{
	int c_write, c_read, n, pos, fd1=open("f1.txt",O_CREAT, 0600);
	char buff[10];
	long seek1;
	int fd2=open("f3.txt",O_CREAT | O_RDWR, 0600);
	printf("1. From beginning\t2. From middle\t3. From end ");	
	printf("\nEnter your choice ");
	scanf("%d",&n);
	switch(n)
	{
		case 1:	seek1=lseek(fd1,0,SEEK_SET);
	               	c_read=read(fd1,buff,10);
	               	c_write= write(fd2,buff,c_read);
			break;
	
	        case 2:	printf("\nEnter the position ");
			scanf("%d",&pos);
			seek1=lseek(fd1,pos,SEEK_SET);
			c_read=read(fd1,buff,10);
			c_write= write(fd2,buff,c_read);
			break;
	
		case 3: seek1=lseek(fd1, 0, SEEK_END);
			seek1=lseek(fd1, -10, SEEK_CUR);
			c_read=read(fd1, buff, 5);
			c_write= write(fd2, buff, c_read);
			break;
	}
	close(fd1);
	close(fd2);
	return 0;
}
