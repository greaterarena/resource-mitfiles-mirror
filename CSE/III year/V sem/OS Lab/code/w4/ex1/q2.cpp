#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <iostream>
#include <string>

using namespace std;

int main(){
    int t = 25;
	string fname1, fname2; char b[t];
	cout<<"Please Enter File to read from: ";
	cin>>fname1;
	int fhandle = open(fname1.c_str(),O_RDONLY,0600);

    int fh1 = open("f3.lol", O_WRONLY | O_CREAT, 0700);
    int fh2 = open("f4.lol", O_WRONLY | O_CREAT, 0700);
    int fh3 = open("f5.lol", O_WRONLY | O_CREAT, 0700);

    read(fhandle,b,t);
    write(fh1,b,t);

    lseek(fhandle,-t,SEEK_END);
    read(fhandle,b,t);
    write(fh2,b,t);

    lseek(fhandle,t,SEEK_SET);
    read(fhandle,b,t);
    write(fh3,b,t);


    close(fhandle);
    close(fh1);
    close(fh2);
	return 0;
}
