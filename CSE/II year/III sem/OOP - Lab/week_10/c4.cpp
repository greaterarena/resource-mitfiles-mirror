#include<iostream>
#include<stdio.h>

using namespace std;

class stack{
	int a[100];


	public:

	int tos;
	int max;
	stack(){
		tos=-1;
		max=100;
	}

	stack operator++()
		{
			int x;
    		printf("Enter the element\n");
    		scanf("%d",&x);
    		a[++tos]=x;
		}

	stack operator--(int)
		{
			printf("The deleted item =%d",a[tos--]);
		}

	void disp(){
    		int i;
    		printf("The elements of the stack are :");
    		for(i=0;i<=tos;i++)
    		printf("%d ",a[i]);
    	}
	int isfull(){
    		if(tos==max-1){
   		printf("Overflow\n");
   		return 1;}
   		else return 0;
	}
	int isempty(){
   	 	if(tos<0){
   		printf("Underflow\n");
   		return 1;}
   		else return 0;
	}
};


int main()
 {
 	int n,x,r;
	stack s1;
 	printf("\n\tMENU\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
 	do
 	 {
 	 printf("\nEnter your choice\n");
	  scanf("%d",&n);
	  switch(n)
	   {
	   case 1:   r = s1.isfull();   if(r){}   else  ++s1;  break;
	   case 2:   r = s1.isempty();   if(r){}   else  s1--;   break;
	   case 3:   if(s1.tos<0)   printf("The stack is empty\n");   else   s1.disp();  break;
	   case 4:   break;
	   default:   printf("Invalid choice\n");   break;
	   }
	  }
	 while(n!=4);
	return 0;
}
