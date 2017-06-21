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
		void vin(int h, int m, int s){
			if(validate(&h, &m, &s)){hx=h;mx=m;sx=s;cout<<"\ntime updated successfully\n";}
			else{cout<<"\nseconds cannot be -ve\n";}
		}	
		void disp(){
			cout<<"\ntime hh:mm:ss --->  "<<hx<<" : "<<mx<<" : "<<sx<<"\n";}
		t add(t x){
			t y;
			y.hx = hx + x.hx;
			y.mx = mx + x.mx;
			y.sx = mx + x.sx;
			if(validate(&y.hx,&y.mx,&y.sx)){cout<<"\n time added \n";}
			return y;
		}	
		t sub(t x, int *q){
			t y;
			y.hx = hx - x.hx;
			y.mx = mx - x.mx;
			y.sx = mx - x.sx;
			if(validate(&y.hx,&y.mx,&y.sx)){cout<<"\n time subtracted\n";}
			else{cout<<"\nt1 cannot be subtracted from t2\n";*q = 1;}
			return y;
			
		}
		void comp(t x){
			if(hx == x.hx && mx == x.mx && sx == x.sx){cout<<"\n both given times are equal\n";}
			else{
				if(hx > x.hx){cout<<"\n t1 is greater than t2\n";}
				else{cout<<"\n t2 is greater than t1\n";}
				if(hx == x.hx){
					if(mx > x.mx) {cout<<"\n t1 is greater than t2\n";}
					else{cout<<"\n t2 is greater than t1\n";}}
					if(mx == x.mx){
						if(sx > x.sx){cout<<"\n t1 is greater than t2\n";}
						else {cout<<"\n t2 is greater than t1\n";}}}
			}
		
};

int main(){
	int h1,m1,s1,h2,m2,s2,flag=0;
	t t1,t2,t3;
	cout<<"\nenter time t1 in  H M S format -> ";		
	scanf("%d %d %d",&h1,&m1,&s1);
	t1.vin(h1,m1,s1);
	cout<<"\nenter time t2 in  H M S format -> ";		
	scanf("%d %d %d",&h2,&m2,&s2);	
	t2.vin(h2,m2,s2);
	t1.disp();
	t2.disp();
	t3 = t1.add(t2);
	t3.disp();
	t3 = t1.sub(t2,&flag);
	if(flag == 1){}
	else{t3.disp();}
	t1.comp(t2);	
	return 0;
} 
