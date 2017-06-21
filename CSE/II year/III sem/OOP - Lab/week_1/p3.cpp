#include <iostream>

using namespace std;

int main()
{
	int a[100],n;
	int bsort(int a[],int);
	cout<<"Enter number count\n";
	cin>>n;
	cout<<"Enter the numbers to be sorted\n";
	for(int i=0;i<n;i++)
		cin>>a[i];
	bsort(a,n);
	return 0;
}

int bsort(int a[], int n)
{
	int temp;
	for(int j=0;j<n-1;j++)
	for(int i=n-1;i>0;i--)
		if(a[i]<a[i-1])
		{
			temp=a[i];
			a[i]=a[i-1];
			a[i-1]=temp;
		}
	cout<<"Sorted elements:\n";
	for(int i=0;i<n;i++)
		cout<<a[i]<<"\t";
	cout<<"\n";
	return 0;
}

