#include<iostream>

using namespace std;

struct student{
	char name[30];
	int id;
	float cgpa;
};

void input(student* s1){
	cout<<"enter name - ";	
	cin.getline((*s1).name, 30);
	cout<<"\nenter id - ";	
	cin>>(*s1).id;
	cout<<"\nenter cgpa - ";	
	cin>>(*s1).cgpa;
}

void display(student* s1){
	cout<<"\nname - "<<(*s1).name<<"\nid   - "<<(*s1).id<<"\ncgpa - "<<(*s1).cgpa<<endl<<endl;	
}

void edit(student* s1){
	int ch, c;
	cout<<"would you like to edit your details 1 - yes 0 - no ->";
	cin>>ch;
	if(ch == 1){
	cout<<"enter\n\t1 - name \n\t2 - id\n\t3 - cgpa\n>>";
	cin>>c;
	switch(c){
	case 1: cout<<"enter name - ";	cin.getline((*s1).name, 30); break;
	case 2: cout<<"\nenter id - ";	cin>>(*s1).id; break;
	case 3: cout<<"\nenter cgpa - "; cin>>(*s1).cgpa;break;}
	cout<<"\ndata updated successfully\n";
	cout<<"\nname - "<<(*s1).name<<"\nid   - "<<(*s1).id<<"\ncgpa - "<<(*s1).cgpa<<endl<<endl;}
	else{cout<<"\n\tthank you for using the program";}
	
}

int main()
{
	student s1;
	input(&s1);
	display(&s1);
	edit(&s1);
	return 0;
}
	
