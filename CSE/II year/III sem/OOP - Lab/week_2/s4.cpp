#include<iostream>

using namespace std;


char* concat(char x[300], char y[300]){
	int len=0,i=0;
	char t[600],*o;	
	while(x[len]!='\0'){
	t[i] = x[len];
	len += 1;
	i += 1;
	}
	len = 0;
	while(y[len]!='\0'){
	t[i] = y[len];
	len += 1;
	i += 1;
	}
	o=t;
	return o;
	
}

int main()
{
	char p[300],q[300],*z,l=0;
	cout<<"\n\t enter the first string - > ";	
	cin.getline(p, 300);
	cout<<"\n\t enter the second string - > ";	
	cin.getline(q, 300);		
	z = concat(p, q);
	cout<<"\n\t concatenated string -> ";
        while(z[l]!='\0'){cout<<z[l]; l += 1;}
	cout<<endl<<endl;
	return 0;
}
	
