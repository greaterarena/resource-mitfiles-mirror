#include<iostream>
#include<string.h>
using namespace std;

class String{
		char *c;
	public:
		String(){
			c = NULL;
		}
		String(char *p){
			c = new char[strlen(p)+1];
			strcpy(c,p);
		}
		String(const String &y){		
			c = new char[strlen(y.c)+1];
			strcpy(c,y.c);
		}
		void display(){
			cout<<"\n\n data ->";
			int i=0;
			while(c[i]!='\0'){
				cout<<c[i];
				i++;}
			cout<<"\n";	
		}
		void upper(){
			int i=0;
			while(c[i]!='\0'){
				if(c[i]>=97 && c[i]<=122)
					c[i] -= 32;					
				else
					c[i] += 32;
					i++;
				}
		}
		void rev(){
			char a[strlen(c)];
			int i=0,j=0;
			while(c[i]!='\0'){
				a[i] = c[i];
				i++;
			}
			--i;
			while(i>=0){
				c[j] = a[i];
				i--;
				j++;
			}
		}
		~String(){
			delete c;
			c = NULL;
		}		
};

int main(){
	String b("atERer");
	String c(b);
	b.display();
	b.upper();	
	b.display();
	c.display();
	c.rev();
	c.display();
	return 0;
} 


