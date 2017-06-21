#include<iostream>
using namespace std;

template<class T>
void quiz_arr(T *arr,T key, int n)
{
	for(int i=0;i<n;i++)
	{
		if(arr[i]==key)
		{
			cout<<"\n\nCongrats, Key Found";
			return;
		}
	}
	cout<<"\n\nSorry, Key Not Found";
}

int main()
{
	int n,i;

	cout<<"\n\nEnter Number of Elements :: ";
	cin>>n;

	int *arr1=new int[n];
	cout<<"\n\nEnter Integers : ";
	for(i=0;i<n;i++)
    {
        cin>>arr1[i];
    }
	int quest1;
	cout<<"\n\nWhat do you want to search? :: ";
	cin>>quest1;
	quiz_arr(arr1,quest1,n);

	char *arr2=new char[n];
	cout<<"\n\nEnter Characters : ";
	for(i=0;i<n;i++)
    {
        cin>>arr2[i];
    }
	char quest2;
	cout<<"\n\nWhat do you want to search? :: ";
	cin>>quest2;
	quiz_arr(arr2,quest2,n);

	double *arr3=new double[n];
	cout<<"\n\nEnter Floating Point Numbers : ";
	for(i=0;i<n;i++)
    {
        cin>>arr3[i];
    }
    double quest3;
	cout<<"\n\nWhat do you want to search? :: ";
	cin>>quest3;
	quiz_arr(arr3,quest3,n);

	return 1;
}
