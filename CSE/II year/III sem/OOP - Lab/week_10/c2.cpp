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
		String operator+(String y)
		{
			String z;
			z.c = new char[strlen(c)+strlen(y.c)];
			strcpy(z.c,c);
			strcat(z.c,y.c);
			return z;				
		}

		friend ostream & operator << (ostream &,const String &);

		friend istream & operator >> (istream & ,String &);

		char operator[](int k)
		{
			char z;
			if(k >= strlen(c))
			{
				cout<<"\n\tindex not in range\n";
				return 0;
			}
			else
			{
				z = c[k];
				return z;
			}	
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

ostream & operator << (ostream & customout, const String &y)
{
	customout<<"\n\n\t data ->";
	int i=0;
	while(y.c[i]!='\0'){
		customout<<y.c[i];
		i++;}
	customout<<"\n";	
	return customout;
}

istream & operator >> (istream & in, String & y)
{
	cout<<"\n\t input the string -> ";
	y.c = new char[100];
	in.getline(y.c,100);	
	cout<<endl;
	return in;
}

int main(){
	String b;
	cin>>b;
	String c(b);
	cout<<b;
	b.upper();	
	cout<<b<<c;
	c.rev();
	cout<<c;
	String  z = b+c;
	cout<<z;
	cout<<"\n\n\t b[5] = "<<b[4]<<endl<<endl;
	return 0;
} 


