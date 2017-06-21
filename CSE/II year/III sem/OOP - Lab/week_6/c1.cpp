 #include<iostream>
#include<stdio.h>

using namespace std;

class complex{
		int real,comp;	
	public:
		complex(){
			real = 0;
			comp = 0;		
		}
		complex(int a, int b){
			real = a;
			comp = b;		
		}
		complex(const complex &x){
			real = x.real;
			comp = x.comp;
		}
		void dsp(){
		cout<<" "<<real<<"+("<<comp<<")i \n";
		}
}; 

int main(){
	int r1,c1,r2,c2;
	cout<<"enter r1 c1-> ";	
	scanf("%d %d",&r1,&c1);
	complex x1(r1,c1);
	complex x2;
	complex x3(x1);
	cout<<"c1 -> ";
	x1.dsp();
	cout<<"c2 -> ";	
	x2.dsp();
	cout<<"c3 -> ";	
	x3.dsp();		
	return 0;

}
