#include<iostream>

using namespace std;


int check(char x[300], char y[300]){
	int len=0,flag=0;
	while(x[len]!='\0' or y[len]!='\0'){
	//int q = int(x[len]);
	if(x[len] == y[len]){flag = 0;}
	if(x[len] > y[len]){flag = 1;break;}
	if(x[len] < y[len]){flag = -1;break;}
	len += 1;
	}
	return flag;	
}

int main()
{
	char p[300],q[300];
	int z;
	cout<<"\n\t enter the first string - > ";	
	cin.getline(p, 300);
	cout<<"\n\t enter the second string - > ";	
	cin.getline(q, 300);		
	z = check(p, q);
	cout<<"\n\t result -> "<<z<<"\n\n";
	return 0;
} 
