#include<iostream>
using namespace std;

template<class T>
void sort_arr(T *arr,int n)
{
    int i,j;
    T temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	cout<<"Values after Soritng :: ";
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
	sort_arr(arr1,n);
	for(i=0;i<n;i++)
    {
        cout<<arr1[i]<<"\t";
    }
	char *arr2=new char[n];
	cout<<"\n\nEnter Characters : ";
	for(i=0;i<n;i++)
    {
        cin>>arr2[i];
    }
	sort_arr(arr2,n);
	for(i=0;i<n;i++)
    {
        cout<<arr2[i]<<"\t";
    }
	double *arr3=new double[n];
	cout<<"\n\nEnter Floating Point Numbers : ";
	for(i=0;i<n;i++)
    {
        cin>>arr3[i];
    }
	sort_arr(arr3,n);
	for(i=0;i<n;i++)
    {
        cout<<arr3[i]<<"\t";
    }
	return 1;
}
