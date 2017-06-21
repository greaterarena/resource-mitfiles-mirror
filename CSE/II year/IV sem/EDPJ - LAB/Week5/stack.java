import java.util.Scanner;


public class stack {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		stackit s1 = new stackit();
		Scanner in = new Scanner(System.in);
		int choice;
		while(true)
		{
			System.out.print("\n1.Push 2.Pop 3.DisplayFromTop\n");
			System.out.print("4.push_b 5.pop_b 6.Exit\nEnter Choice - ");
			choice = in.nextInt();
			if(choice==1)
				s1.push();
			else if(choice==2)
				s1.pop();
			else if(choice==3)
				s1.display();
			else if(choice==4)
				s1.push_b();
			else if(choice==5)
				s1.pop_b();
			else if(choice==6)
				break;
			else
				System.out.print("\nInvalid Choice");
		}
	}

}

class Stacker
{
	int dat []; 
	int tos;
	protected Scanner in = new Scanner(System.in);
	Stacker()
	{
		System.out.print("Enter stack size - ");		
		dat = new int [in.nextInt()];
		tos = 0;
	}	
	void display()
	{
		if(IsEmpty())
			return;
		int temp = 0;
		while(temp!=tos)
			System.out.print(dat[temp++]+" ");
		temp = dat.length-1;
		while(temp!=stackit.bos)
			System.out.print(dat[temp--]);
	}
	boolean IsFull()
	{
		if(tos==stackit.bos)
		{
			System.out.println("\nStack Overflow");
			return true;
		}
		else
			return false;
	}
	boolean IsEmpty()
	{
		if(tos==0 && stackit.bos==dat.length)
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

class stackit extends Stacker
{
	static int bos;
	stackit()
	{
		super();
		bos = dat.length;
	}
	void push_b()
	{
		if(IsFull())
			return;
		System.out.print("Enter Element - ");
		int temp = in.nextInt();
		dat[--bos]=temp;
	}
	void pop_b()
	{
		if(IsEmpty())
			return;
		int temp = dat[bos++];
		System.out.println("\nPopped Element - "+temp);
	}	
}