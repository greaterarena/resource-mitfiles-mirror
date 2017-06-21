#include<iostream>
#define siz 9

using namespace std;
class intarr{
		public:
		int* x;
		int size;
	
		intarr(){
			x = new int[siz];
			size = siz;
		}
		intarr(int z[],int m){			
			x = new int[m];
			x = z;
			size = m;
		}
		intarr(const intarr &y){
			x = y.x;
			size = y.size;
		}
		intarr operator+(intarr y)
		{
			intarr z;
			if(size != y.size)
			{
				cout<<"\n\tcannot add objects of different sizes\n";
			}
			else
			{
				z.size = size;
				for(int i=0;i<size;i++)
					z.x[i] = x[i] + y.x[i];
				return z;
			}	
		}
		int operator[](int k)
		{
			int z;
			if(k >= size)
			{
				cout<<"\n\tindex not in range\n";
				return 0;
			}
			else
			{
				z = x[k];
				return z;
			}	
		}

		friend ostream & operator << (ostream &,const intarr &); 
		
		friend istream & operator >> (istream & ,intarr &);
		
		
		void search(int k){
			int i;			
			for(i=0;i<size;i++)
				if(x[i]==k)
					cout<<"\n\tMatch Found at -> "<<i+1<<endl;			
		}
		int operator==(intarr y){
			int i;
			if(size!=y.size){
				return 0;
			}
			else{
				int flag = 0;
				for(i=0;i<size;i++){
					if(x[i]==y.x[i]){}
					else{flag=1;}	}
				if(flag==1){return 0;}
				else {return 1;} 
			}
				
		}
};

ostream & operator << (ostream & customout, const intarr & y)
{
	int i;
	customout<<"\n";
	for(i=0;i<y.size;i++)
	customout<<"\t"<<y.x[i];
	customout<<"\n";
	return customout;
}

istream & operator >> (istream & in, intarr & y)
{
	cout<<"\n\t input the size -> ";
	in>>y.size;	
	for(int i = 0; i < y.size; i++){
		cout<<"\n\tenter element - "<<i<<" - ";
		in>>y.x[i];}
	return in;
}

int main(){
	intarr a;
	intarr b;
	intarr d;
	cin>>b;
	cin>>d;
	intarr c(b);
	cout<<b;
	cout<<c;
	cout<<d;
	b.search(6);
	if(b==c)cout<<"\n\tobjects equal\n";else cout<<"\n\tobjects are not equal\n";
	if(a==b)cout<<"\n\tobjects equal\n";else cout<<"\n\tobjects are not equal\n";
	if(b==d)cout<<"\n\tobjects equal\n";else cout<<"\n\tobjects are not equal\n";
	intarr z = b+d;
	cout<<z;
	cout<<"\n\tz[3] = "<<z[3]<<"\n\n";
	return 0;
} 


