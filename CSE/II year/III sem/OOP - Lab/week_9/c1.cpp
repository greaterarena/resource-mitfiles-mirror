#include <iostream>

using namespace std;

class list
{
	struct NODE
	{
		int item;
		NODE* next;
	}*x;

	NODE* head;
	NODE* tail;	
	
	public:
	
	list()
	{
		x = new NODE;
		x->item = NULL;
		x->next = NULL;
		head = x;
		tail = x;	
	}
	~list()
	{
		head = NULL;
		tail = NULL;
		delete x;
		x = NULL;
	}
	void add_at_first(int data)
	{
		cout<<"\nAdding data at first ->"<<data<<"\n\n";		
		if(x->item==0)
		{
			x->item = data;
		}
		else
		{
			NODE* temp;
			temp = new NODE;
			temp->item = data;
			temp->next = head;
			head = temp;			
		}		
	}
	void add_at_last(int data)
	{
		cout<<"\nAdding data at last ->"<<data<<"\n\n";			
		NODE* temp;
		temp = new NODE;
		temp->item = data;
		temp->next = NULL;
		tail->next = temp;
		tail = temp;
	}
	void delete_at_head()
	{	
		if(is_empty()==0)	
		{	
			cout<<"\ndeleting data at first ->"<<head->item<<"\n\n";
			head = head->next;	
		}	
	}
	void delete_at_tail()
	{
		if(is_empty()==0)
		{		
			cout<<"\ndeleting data at last ->"<<tail->item<<"\n\n";
			tail->item = NULL;
			NODE* temp = head;		
			while(temp->next->item!=0)
				temp = temp->next;
			tail = temp;	
		}	
	}
	int is_empty()
	{
		if(head==tail&&head->item==0)
		{
			cout<<"\nlist is empty\n\n";			
			return 1;
		}		
		else
			return 0;
	}
	void display()
	{
		cout<<endl<<"list contents -> ";
		NODE* temp = head;		
		while(temp!=tail)
		{
			cout<<temp->item<<"\t";		
			temp = temp->next;
		}
		cout<<temp->item<<"\t";
		cout<<endl<<endl;
		
	}	
};

int main()
{
	list test;
	int flag = 0;	
	while(flag!=1)
	{	
		int c,d;		
		cout<<"\nMENU\n1.add_at_first\n2.add_at_last\n3.delete_at_head\n4.delete_at_tail\n5.display\n6.exit\n\n";
		cout<<"\nenter choice -> ";
		cin>>c;
		switch(c)
		{
			case 1:cout<<"\n\nenter element -> ";cin>>d;test.add_at_first(d);break;
			case 2:cout<<"\n\nenter element -> ";cin>>d;test.add_at_last(d);break;
			case 3:test.delete_at_head();break;
			case 4:test.delete_at_tail();break;
			case 5:test.display();break;
			case 6:flag=1;
			default:cout<<"\n\ninvalid choice\n";
		}
	}
	return 0;
}
