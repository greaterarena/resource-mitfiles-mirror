#include <iostream>
#include <string>

using namespace std;

class student
{
	string name;
	int id;
	public:
	student()
	{
		cout<<"\nEnter the Student ID - ";
		cin>>id;		
		cout<<"\nEnter the name of the Student - ";
		cin>>name;
		cin.ignore();		
		cout<<"\ndata recorded\n";	
	}	
	string getname()
	{
		return name;
	}	
	int getid()
	{
		return id;
	}
};

class sports : virtual public student
{
	int s_grade;
	public:
	sports()
	{
		cout<<"\nEnter the sports grade in % - ";
		cin>>s_grade;
		cout<<"\ndata recorded\n";
	}
	int getsgrade()
	{
		return s_grade;
	}
};

class exam : virtual public student
{
	int e_grade;
	public:
	exam()
	{
		cout<<"\nEnter the exam grade in % - ";
		cin>>e_grade;
		cout<<"\ndata recorded\n";
	}
	int getegrade()
	{
		return e_grade;
	}
};

class results : public sports, public exam
{
	string final;
	public:
	results()
	{
		if(getegrade()>40)
		{
			if(getsgrade()>40)
				final = "Student passed in Both Exams and Sports";
			else
				final = "Student passed in Exams but failed in Sports";
		}
		else
		{
			if(getsgrade()>40)			
			final = "Student failed in Exams but passed in sports";
		}
			
	}
	void display()
	{
		cout<<"\nresult for - "<<getname()<<" - "<<getid()<<" - "<<final<<endl<<endl;
	}
};

int main()
{
	results std1;
	std1.display();
	return 0;
}
