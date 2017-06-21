#include<iostream>

using namespace std;

struct student{
	char name[30];
	int id;
	float cgpa;
}s[4];

void input(student* s1){
	cout<<endl;
	cout<<"\nenter id - ";	
	cin>>(*s1).id;
	cout<<"\nenter name - ";	
	cin>>(*s1).name;
	cout<<"\nenter cgpa - ";	
	cin>>(*s1).cgpa;
}

void display(student* s1){
	cout<<"\nname - "<<(*s1).name<<"\nid   - "<<(*s1).id<<"\ncgpa - "<<(*s1).cgpa<<endl<<endl;	
}

void arrange(student* q){
	int i,j;	
	student temp,r[4];
	for (i = 0;i<4;i++){r[i] = *(q+i);}
	
	for(i=0; i<3; i++){
	for(j=3; j>=0; j--){
		if(r[j].id < r[j-1].id){
			temp = r[j];
			r[j] = r[j-1];
			r[j-1] = temp;}}}
	for (i = 0;i<4;i++){*(q+i) = r[i];}
	cout<<"\narray successfully sorted\n";
}

void search(student* q){
	int i,j,key,loc;
	cout<<"\n\t enter an id to search for - ";
	cin>>key;	
	student temp,r[4];
	for (i = 0;i<4;i++){r[i] = *(q+i);}
	
	for(i=0; i<4; i++){
	if(key == r[i].id){
	loc = i;}
	}
	cout<<"\nmatch found\nname - "<<r[loc].name<<"\nid   - "<<r[loc].id<<"\ncgpa - "<<r[loc].cgpa<<endl<<endl;
		
}


int main()
{
	student* p;
	p = s;
	int c,flag = 0;
	while (true){
	cout<<"\nwelcome to the database entry \n\t 1 - input the details\n\t 2 - display the details"
	<<"\n\t 3 - arrange the records"<<"\n\t 4 - search for a record\n\t->";
	cin>>c;
	switch(c){
	case 1:	for (int i = 0;i<4;i++){input(&s[i]);} cout<<"\n\tinput complete"; break;
	case 2: for (int i = 0;i<4;i++){display(&s[i]);}cout<<"\n\tdisplay complete"; break;	
	case 3: arrange(p); break;
	case 4: search(p);break;
	default: flag = 1;}
	if(flag == 1){cout<<"\n\tthank you";break;}	
	}
	return 0;
}
	
