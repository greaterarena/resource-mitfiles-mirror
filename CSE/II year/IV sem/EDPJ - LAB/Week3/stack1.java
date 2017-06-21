import java.util.Scanner;

public class stack1 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Stack s1 = new Stack();
		Scanner in = new Scanner(System.in);
		int choice;
		while(true)
		{
			System.out.print("\n1.Push 2.Pop 3.DisplayFromTop\n");
			System.out.print("4.DisplayFromBottom 5.StackTop 6.Exit\nEnter Choice - ");
			choice = in.nextInt();
			if(choice==1)
				s1.push();
			else if(choice==2)
				s1.pop();
			else if(choice==3)
				s1.displayFromTop();
			else if(choice==4)
				s1.displayFromBot();
			else if(choice==5)
				s1.stackTop();
			else if(choice==6)
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
	void displayFromTop()
	{
		if(IsEmpty())
			return;
		int temp = tos;
		while(temp!=0)
			System.out.print(dat[--temp]+" ");
	}
	void displayFromBot()
	{
		if(IsEmpty())
			return;
		int temp = 0;
		while(temp!=tos)
			System.out.print(dat[temp++]+" ");
	}
	void stackTop()
	{
		if(IsEmpty())
			return;
		System.out.println("\nTop Element - "+dat[tos-1]);
	}
	boolean IsFull()
	{
		if(tos==dat.length)
		{
			System.out.println("\nStack Overflow");
			return true;
		}
		else
			return false;
	}
	boolean IsEmpty()
	{
		if(tos==0)
		{
			System.out.println("\nStack Underflow");
			return true;
		}
		else
			return false;
	}
	void push()
	{
		if(IsFull())
			return;
		System.out.print("Enter Element - ");
		int temp = in.nextInt();
		dat[tos++]=temp;
	}
	void pop()
	{
		if(IsEmpty())
			return;
		int temp = dat[--tos];
		System.out.println("\nPopped Element - "+temp);		
	}	
}