#include<iostream>
#include<stdio.h>

using namespace std;

class complex{
		int real,comp;	
	public:
		void vin(int y, int z){
			real = y;
			comp = z;
		}
		void dsp(){
		cout<<" "<<real<<"+("<<comp<<")i \n";
		}	
		complex add(complex x1){
			complex r;
			r.real = real+x1.real;
			r.comp = comp+x1.comp; 
			return r;
		}
		complex sub(complex x1){
			complex r;
			r.real = real-x1.real;
			r.comp = comp-x1.comp; 
			return r;
		}
}; 

int main(){
	complex x1,x2,x3;
	int r1,c1,r2,c2;
	cout<<"enter r1 c1 r2 c2 -> ";	
	scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
	x1.vin(r1,c1);
	x2.vin(r2,c2);
	cout<<"c1 -> ";
	x1.dsp();
	cout<<"c2 -> ";	
	x2.dsp();
	x3 = x1.add(x2);
	cout<<"addition -> ";
	x3.dsp();
	x3 = x1.sub(x2);
	cout<<"subtraction -> ";
	x3.dsp();
		
	return 0;

}
