#include<iostream>
#include<string>
using namespace std;
class bacc{
		string name;
		long int acno;
		int type;
		float balance;
		static int roi;
	public:
		int min(float x){
			if(x>10000.00)
				return 1;
			return 0;		
		}	
		bacc(){
			name = "**-ENTER-NAME-**";
			acno = 9999;
			type = 0;
			balance = 10000.00;
		}
		bacc(string x, int a, int b, float c){
			if(min(c)){			
			name = x;
			acno = a;
			type = b;			
			balance = c;}
			else
			cout<<"\nentered balance less than minimum balance 10000 rs please re register\n";
		}
		bacc(const bacc &x){
			name = x.name;
			acno = x.acno;
			type = x.type;
			balance = x.balance;
		}
		void inbal(int x){
			balance += balance + x;
		}
		void draw(int x){
			if(min(balance)){
				balance -= x;
				cout<<"\namount dispensed\n";			
			}
			else
				cout<<"\ncannot withdraw balance low\n";		
		}
		void display(){
			cout<<"\nname - "<<name<<"\nacno - "<<acno<<"\ntype - "<<type<<"\nbalance - "<<balance<<endl;
		}
		static int ratoi(){
		        cout<<"\nrate of interest "<<roi<<endl;
	        }
};

int bacc::roi = 3;

int main(){
	bacc empty;
	string x;
	int a, b;
	float c;
	cout<<"\n\t enter name - ";
	getline(cin,x);
	cout<<"\n\t enter acno - ";
	cin>>a;
	cout<<"\n\t enter type 1 - savings - 2 - current - ";
	cin>>b;	
	cout<<"\n\t enter initial deposit - ";	
	cin>>c;
	bacc a1(x,a,b,c);
	bacc a2(a1);
	empty.display();
	a1.display();
	a2.display();
	a2.ratoi();
	return 0;
}
