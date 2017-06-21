#include<iostream>
#include<cstring>

using namespace std;

int main()
{
	char p[300],q[300],r[300];
	int l=0;
	cout<<"\n\t enter the p string - > ";	
	cin.getline(p, 300);
	cout<<"\n\t enter the q string - > ";	
	cin.getline(q, 300);	
	strcpy(r, p);
	cout<<"\n\t copying p to r\n\n\t r -> ";	
	while(r[l]!='\0'){cout<<r[l]; l += 1;}cout<<"\n";l=0;
	cout<<"\n\t comparing p with q ";
	int y = strcmp(p,q);
	cout<<"\n\n\t result -> "<<y;
	cout<<"\n\n\t concatenating p and q -> "<<strcat(p, q);
	cout<<"\n\n";
	return 0;
} 
