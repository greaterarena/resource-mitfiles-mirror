#include<iostream>
#include<stdio.h>

using namespace std;

class t{
		int hx,mx,sx;
	public:
		int validate(int* h, int* m, int* s){
			int flag = 0;			
			if(*s > 60){
				int x = *s%60; 
				int y = *s/60;
				*m += y;
				*s = x;
			}
			if(*s < 0){flag = 1;}
			if(*m >60){
				int x = *m%60; 
				int y = *m/60;
				*h += y;
				*m = x;
			}			
			if(*h > 24){while(*h>24)*h -= 24;}
			if(*h < 0){while(*h<0)*h += 24;}
			if(flag == 1){return 0;}
			if(flag != 1){return 1;}
		}	
		t(){
			hx = 0;
			mx = 0;
			sx = 0;
			cout<<"\ntime recorded\n";
		}	
		t(int h, int m, int s){
			if(validate(&h, &m, &s)){hx=h;mx=m;sx=s;cout<<"\ntime recorded\n";}
			else{cout<<"\nseconds cannot be -ve\n";}
		}
		t(const t &x){
			hx = x.hx;
			mx = x.mx;
			sx = x.sx;
			cout<<"\ntime recorded\n";
		}	
		void disp(){
			cout<<"\ntime hh:mm:ss --->  "<<hx<<" : "<<mx<<" : "<<sx<<"\n";}
};

int main(){
	int h1,m1,s1,flag=0;
	cout<<"\nenter time t1 in  H M S format -> ";		
	scanf("%d %d %d",&h1,&m1,&s1);
	t t1(h1,m1,s1);
	t t2;
	t t3(t1);
	t1.disp();
	t2.disp();
	t3.disp();
	return 0;
}  
