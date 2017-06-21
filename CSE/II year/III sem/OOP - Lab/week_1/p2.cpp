#include <iostream>

using namespace std;

int main()
{
	int a[100],n,big;
	int biggest(int a[],int);
	cout<<"Enter number count\n";
	cin>>n;
	cout<<"Enter the numbers\n";
	for(int i=0;i<n;i++)
		cin>>a[i];
	big=biggest(a,n);
	cout<<"The biggest number is "<<big<<"\n";
	return (0);
}


int biggest(int a[],int n)
{
	int s,k=a[0];
	for(int i=0;i<n;i++)
		if(a[i]>k)
			s=a[i];
	return (s);
}
