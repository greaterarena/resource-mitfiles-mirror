#include<iostream>
#define siz 20

using namespace std;
class intarr{
		int* x;
		int size;
	public:
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
		void display(){
			int i;
			cout<<"\n";
			for(i=0;i<size;i++)
				cout<<"\t"<<x[i];
			cout<<"\n";
		}
		void search(int k){
			int i;			
			for(i=0;i<size;i++)
				if(x[i]==k)
					cout<<"\n\tMatch Found at -> "<<i+1<<endl;			
		}
		void compare(intarr y){
			int i;
			if(size!=y.size){
				cout<<"\n\tObjects of inequal size not equal\n";
				return;
			}
			else{
				int flag = 0;
				for(i=0;i<size;i++){
					if(x[i]==y.x[i]){}
					else{flag=1;}	}
				if(flag==1){cout<<"\n\tObjects not equal\n"; return;}
				else {cout<<"\n\tObjects equal\n"; return;} 
			}
				
		}
};

int main(){
	intarr a;
	int e[] = {1,2,3,4,5,6,7,8,9};
	int f[] = {1,2,3,4,5,6,7,2,9};
	intarr b(e,9);
	intarr d(f,9);
	intarr c(b);
	b.display();
	c.display();
	d.display();
	b.search(6);
	b.compare(c);
	a.compare(b);
	b.compare(d);
	
	return 0;
} 


