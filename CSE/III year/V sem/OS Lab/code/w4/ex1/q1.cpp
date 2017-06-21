#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <iostream>
#include <string>

using namespace std;

int main(){

	string fname1, fname2; char b;
	cout<<"Please Enter File to read from: ";
	cin>>fname1;
	int fhandle = open(fname1.c_str(),O_RDONLY,0600);
    cout<<"Please Enter Filename to write into: ";
    cin>>fname2;
    int nfhandle = open(fname2.c_str(), O_WRONLY | O_CREAT, 0700);
    while(read(fhandle,&b,1)==1)
        write(nfhandle,&b,1);
    close(fhandle);
    close(nfhandle);
	return 0;
}
