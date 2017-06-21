#include <iostream>

using namespace std;

struct Rectangle
{
	int length;
	int breadth;
};

int main()
{
	Rectangle r1;
	int x=r1.length;
	int y=r1.breadth;
	int input(int*,int*);
	input(&x,&y);
	int displayDimensions(int,int);
	displayDimensions(x,y);
	int displayArea(int,int);
	displayArea(x,y);
	return 0;
}

int input(int *a,int *b)
{
	cout<<"Enter length and Breadth\n";
	cin>>a>>b;
	return 0;
}

int displayDimensions (int m,int n)
{
	cout<<"Length is "<<m<<"\n";
	cout<<"Breadth is "<<n<<"\n";
	return 0;
}

int displayArea (int p, int q)
{
	int r;
	r= p*q;
	cout<<"Area is "<<r<<"\n";
	return 0;
}
