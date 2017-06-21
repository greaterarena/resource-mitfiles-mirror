#include<iostream>
#include<stdio.h>
#include<cstring>

using namespace std;

void sort(char string[][100], int no){
	int i, j;
	char temp[100];
	for(i=0;i<no-1;i++){
		for(j=i+1;j<no;j++) {
			if(strcmp(string[i],string[j])>0){
			strcpy(temp,string[i]);
			strcpy(string[i],string[j]);
			strcpy(string[j],temp);	}}}
	for(i=0;i<no;i++){
		cout<<"\t";
		puts(string[i]);}
}


int main()
{
	char string[30][100];
	int no, i;
	cout<<"\nEnter the no of strings:";
	cin>>no;
	for(i=0;i<no; i++){
		cout<<"\nEnter string #"<<i<<" --> ";
		cin>>string[i];
	}
	sort(string, no);
	return 0;
}
	
