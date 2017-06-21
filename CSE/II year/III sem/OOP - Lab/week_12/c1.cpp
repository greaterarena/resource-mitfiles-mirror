#include<iostream>
using namespace std;

template<class T>
void fun_swap(T &a, T &b)
{
	T temp;
	temp=a;
	a=b;
	b=temp;
	cout<<"\nAfter Swap :: ";
}

int main()
{
	int n1,n2;
	char a,b;
	double p,q;

	cout<<"\n\nEnter Integers :: ";
	cin>>n1>>n2;
	fun_swap(n1,n2);
	cout<<n1<<" "<<n2;

	cout<<"\n\nEnter Characters :: ";
	cin>>a>>b;
	fun_swap(a,b);
	cout<<a<<" "<<b;

	cout<<"\n\nEnter Floating Point Numbers :: ";
	cin>>p>>q;
	fun_swap(p,q);
	cout<<p<<" "<<q;

	return 1;
}
