#include<iostream>
#include<stdio.h>
#include<cstring>

using namespace std;

class movie{
	char title[100];
	int year;
	char dct[100];
	
	public:
		void setTitle(char t[100]){strcpy(title,t);}
		void setYear(int y){year = y;}
		void setDirector(char d[100]){strcpy(dct,d);}
		void disp(){
		cout<<"\nMovie Information\n";
		cout<<"\t Title - >";puts(title);
		cout<<"\t year - >"<<year<<endl;
		cout<<"\t director - >";puts(dct);
		}
		void comp(movie x,movie q){
			if(x.year == q.year){cout<<"\n movies released the same year\n";}
			if(x.year != q.year){cout<<"\n movies did not release the same year\n";}	
			if(strcmp(x.dct,q.dct)==0){cout<<"\n movies have the same director\n\n";}
			if(strcmp(x.dct,q.dct)!=0){cout<<"\n movies dont have the same director\n\n";}
		}
}; 



int main(){
	char x1[100], x2[100], x3[100], x4[100];
	int y1,y2;
	movie m1,m2,m3;
	cout<<"enter m1 year ->";cin>>y1;m1.setYear(y1);
	cout<<"enter m1 title ->";cin>>x1;m1.setTitle(x1);
	cout<<"enter m1 director ->";cin>>x2;m1.setDirector(x2);
	cout<<"enter m2 year ->";cin>>y2;m2.setYear(y2);
	cout<<"enter m2 title ->";cin>>x3;m2.setTitle(x3);
	cout<<"enter m2 director ->";cin>>x4;m2.setDirector(x4);
	m1.disp();
	m2.disp();
	m3.comp(m1,m2);
}
