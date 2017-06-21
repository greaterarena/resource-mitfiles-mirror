#include<iostream>

using namespace std;

void sortr(int &x, int &y){
	int temp;
	temp = x;
	x = y;
	y = temp;	
}

void sortp(int *x, int *y){
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;

}

int main(){

 	int x,y;
	cin>>x>>y;
	cout <<"\n\ninput x y-> "<<x<<" "<<y;
	sortr(x, y);
	cout <<"\n\nreference sorted x y-> "<<x<<" "<<y;
	sortr(x,y);
	cout <<"\n\ninput x y-> "<<x<<" "<<y;
	sortp(&x, &y);
	cout <<"\n\npointer sorted x y-> "<<x<<" "<<y<<endl<<endl;
}
