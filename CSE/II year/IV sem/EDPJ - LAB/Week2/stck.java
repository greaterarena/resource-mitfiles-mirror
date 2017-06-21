import java.util.*;

class stck
{
	public static void main(String args[])
	{
		Stack s1 = new Stack();
		Scanner in = new Scanner(System.in);
		int choice;
		while(true)
		{
			System.out.print("\n1.Push\n2.Pop\n3.Exit\nEnter Choice - ");
			choice = in.nextInt();
			if(choice==1)
				s1.push();
			else if(choice==2)
				s1.pop();
			else if(choice==3)
				break;
			else
				System.out.print("\nInvalid Choice");
		}
	}
}

class Stack
{
	int dat [];
	int tos;
	private Scanner in = new Scanner(System.in);
	Stack()
	{
		System.out.print("Enter stack size - ");		
		dat = new int [in.nextInt()];
		tos = 0;
	}
	
	void push()
	{
		if(tos==dat.length)
		{
			System.out.println("\nStack Overflow");
			return;
		}
		System.out.print("Enter Element - ");
		int temp = in.nextInt();
		dat[tos++]=temp;
	}
	void pop()
	{
		if(tos==0)
		{
			System.out.println("\nStack Underflow");
			return;
		}
		int temp = dat[--tos];
		System.out.println("\nPopped Element - "+temp);		
	}	
}
