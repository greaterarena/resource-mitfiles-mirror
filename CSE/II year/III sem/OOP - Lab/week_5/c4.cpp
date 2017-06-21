#include<iostream>
#include<string>
using namespace std; 

class customer{
		int c_id;
		string c_name;
		int c_limit;
	public:
		void c_set(){
			cout<<"\nenter cid -> ";
			cin>>c_id;
			cin.ignore();
			cout<<"\nenter name -> ";
			getline(cin,c_name);
			cout<<"\nenter credit limit -> ";
			cin>>c_limit;
			cin.ignore();
			cout<<"\ndata record successful\n";
		}
		void c_disp(){
			cout<<"\nCustomer Information ->\n\t"
			<<"Customer Id -> "<<c_id<<"\n\tName -> "<<c_name
			<<"\n\tCredit Limit -> "<<c_limit<<endl;
		}
};

int main(){
	int i;
	customer x[5];
	for(i=0;i<5;i++){
		x[i].c_set();
	}
	for(i=0;i<5;i++){
		x[i].c_disp();
	}
	return 0;
}
