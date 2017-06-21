 #include <iostream>

using namespace std;

class shape
{
	public:	
	double dim1;
	double dim2;	
	void getdata()
	{
		cout<<"\nEnter the two dimensions - ";
		cin>>dim1>>dim2;
		cout<<"\ndata recorded\n";
	}
	virtual void displayarea()
	{
		cout<<"yahoo";	
	}
};

class triangle : public shape 
{
	public:
	void displayarea()
	{
	cout<<"\nArea of triangle - "<<0.5*dim1*dim2<<endl<<endl;
	}
};

class rectangle : public shape 
{
	public:
	void displayarea()
	{
	cout<<"\nArea of rectangle - "<<dim1*dim2<<endl<<endl;
	}
};

int main()
{
	triangle t1;
	rectangle r1;
	int x;
	cout<<"\n1. Area of Rectangle 2. Area of Triangle - ";
	cin>>x;
	if(x==1)
	{
		r1.getdata();
		r1.displayarea();
	}
	else
	{
		t1.getdata();
		t1.displayarea();
	}
	return 0;
}


