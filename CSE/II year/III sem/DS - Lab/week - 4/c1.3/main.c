#include<stdio.h>
int max = 100;

void push(int a[],int *top){
    int x;
    printf("Enter the element\n");
    scanf("%d",&x);
    a[++*top]=x;
}

void pop(int a[],int *top){
    printf("The deleted item =%d",a[(*top)--]);
}

void disp(int a[],int top){
    int i;
    printf("The elements of the stack are :");
    for(i=0;i<=top;i++)
    printf("%d ",a[i]);
    }
int of(int top){
    if(top==max-1){
   printf("Overflow\n");
   return 1;}
   else return 0;
}
int un(int top){
    if(top<0){
   printf("Underflow\n");
   return 1;}
   else return 0;
}


void main()
 {

 int a[100]={0},i,top=-1,max=100,n,x,r;
 printf("\n\tMENU\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
 do
  {
  printf("\nEnter your choice\n");
  scanf("%d",&n);
  switch(n)
   {
   case 1:
   r = of(top);
   if(r){}
   else
    {push(&a,&top);}
   break;

   case 2:
   r = un(top);
   if(r){}
   else
   pop(&a,&top);
   break;

   case 3:
   if(top<0)
   printf("The stack is empty\n");
   else
    disp(&a,top);
   break;

   case 4:
   break;

   default:
   printf("Invalid choice\n");
   break;
   }
  }
 while(n!=4);
 }
