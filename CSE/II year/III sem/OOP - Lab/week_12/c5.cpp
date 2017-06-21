#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

class Employee
{
	string name;
	float sal;
	string id;
	public: friend istream&operator>>(istream&,Employee&);
            friend ostream&operator<<(ostream&,Employee&);
};

istream&operator>>(istream &in,Employee &e)
{
	cout<<"\n\nName :: ";
	in>>e.name;
	cout<<"\n\nSalary :: ";
	in>>e.sal;
	cout<<"\n\nID :: ";
	in>>e.id;
	return in;
}

ostream&operator<<(ostream &out,Employee &e)
{
	out<<"\nName :: "<<e.name<<"\nSalary :: "<<e.sal<<"\nID :: "<<e.id;
	return out;
}

class Student
{
        string name;
        int rno;
        float cgpa;
        public: friend istream&operator>>(istream&,Student&);
                friend ostream&operator<<(ostream&,Student&);
};

istream&operator>>(istream &in,Student &e)
{
        cout<<"\n\nName :: ";
        in>>e.name;
        cout<<"\n\nRoll Number :: ";
        in>>e.rno;
        cout<<"\n\nCGPA :: ";
        in>>e.cgpa;
        return in;
}

ostream&operator<<(ostream &out,Student &e)
{
        out<<"\nName :: "<<e.name<<"\nRoll Number :: "<<e.rno<<"\nCGPA :: "<<e.cgpa;
        return out;
}

template<class T>
class Stack
{
	T *arr;
	int tos,capacity;
public: Stack()
		{
			tos=-1;
			capacity=10;
			arr=new T[capacity];
		}

		~Stack()
		{
			delete arr;
		}

		void pop()
		{
			if(tos==-1)
				cout<<"\n\nStack Underflow";
			else
				cout<<"\n\n"<<arr[tos--]<<" got popped";
		}

		void push()
		{
			if(tos==capacity-1)
            {
                cout<<"\n\nStack Overflow";
            }

			else
			{
				cout<<"\n\nEnter Element :: ";
				T item;
				cin>>item;
				arr[++tos]=item;
			}
		}

		void display()
		{
			if(tos==-1)
				cout<<"\n\nStack Empty";
			else
			{
			    cout<<"\n\n";
				while(tos!=-1)
					cout<<arr[tos--]<<endl;
			}
		}
};

int main()
{
	Stack<Student> s;
	Stack<Employee> e;
	int ch,choice;
	bool flag=true;
	bool flag2=true;
	cout<<"Which Kind of Stack you want to make?\n";
	cout<<"\n1. Student\n2. Employee\n\nEnter Choice :: ";
	cin>>ch;
	switch(ch)
	{
		case 1:
                while(flag)
                {
                    cout<<"\n1. Push\n2. Pop\n3. Display\n4. Exit\n\nEnter Choice :: ";
                    cin>>ch;
                    switch(ch)
                    {
                        case 1: s.push();
                                break;
                        case 2: s.pop();
                                break;
                        case 3: s.display();
                                break;
                        default: flag=false;
                    }
                }
                break;

		case 2:
                while(flag2)
                {
                    cout<<"\n1. Push\n2. Pop\n3. Display\n4. Exit\n\nEnter Choice :: ";
                    cin>>ch;
                    switch(ch)
                    {
                        case 1: e.push();
                                break;
                        case 2: e.pop();
                                break;
                        case 3: e.display();
                                break;
                        default: flag2=false;
                    }
                }
                break;
    }
}
