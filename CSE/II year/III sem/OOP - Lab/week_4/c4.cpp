#include<iostream>
#include<stdio.h>

using namespace std;

class stck{
	int a[100];
	

	public:

	int tos;
	int max;
	
	void push(){
   		int x;
    		printf("Enter the element\n");
    		scanf("%d",&x);
    		a[++tos]=x;
	}

	void pop(){
	    printf("The deleted item =%d",a[tos--]);
	}

	void disp(){
    		int i;
    		printf("The elements of the stack are :");
    		for(i=0;i<=tos;i++)
    		printf("%d ",a[i]);
    	}
	int of(){
		cout<<"yahoo";
    		if(tos==max-1){
   		printf("Overflow\n");
   		return 1;}
   		else return 0;
	}
	int un(){
   	 	if(tos<0){
   		printf("Underflow\n");
   		return 1;}
   		else return 0;
	}
};


int main()
 {
 	int n,x,r;
	stck s1;
	s1.max = 100;
	s1.tos = -1;
 	printf("\n\tMENU\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
 	do
 	 {
 	 printf("\nEnter your choice\n");
	  scanf("%d",&n);
	  switch(n)
	   {
	   case 1:   r = s1.of();   if(r){}   else  {s1.push();}  break;
	   case 2:   r = s1.un();   if(r){}   else  s1.pop();   break;
	   case 3:   if(s1.tos<0)   printf("The stack is empty\n");   else   s1.disp();  break;
	   case 4:   break;
	   default:   printf("Invalid choice\n");   break;
	   }
	  }
	 while(n!=4);
	return 0;
}			
