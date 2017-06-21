#include<iostream>

using namespace std;


int glen(char x[300]){
	int len=0;	
	while(x[len]!='\0'){
	len += 1;
	}	
	return len;
}

int main()
{
	char p[300];
	cout<<"\n\t enter the string - > ";	
	cin.getline(p, 300);	
	int x = glen(p);
	cout<<"\n\t length of the string -> "<<x<<endl<<endl;
	return 0;
}
	
