#include<iostream>
using namespace std;

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

template <class T>
void Stack_Menu(Stack <T> ob)
{
	int ch;
	bool flag=true;
	while(flag)
	{
		cout<<"\n1. Push\n2. Pop\n3. Display\n4. Exit\n\nEnter Choice :: ";
		cin>>ch;
		switch(ch)
		{
			case 1:ob.push();
				break;
			case 2:ob.pop();
				break;
			case 3:ob.display();
				break;
			default:flag=false;
		}
	}
}

int main()
{
	int ch;
	bool flag=true;
	while(true)
    {
        cout<<"Choose Stack Type :: \n";
        cout<<"\n1. Integer\n2. Character\n3. Double\n4. Exit\n\nEnter Choice :: ";
        cin>>ch;
        Stack<int>i;
        Stack<double>d;
        Stack<char>c;
        switch(ch)
        {
            case 1:Stack_Menu(i);
                break;
            case 2:Stack_Menu(c);
                break;
            case 3:Stack_Menu(d);
                break;
            default: flag=false;
        }
    }
	return 1;
}
