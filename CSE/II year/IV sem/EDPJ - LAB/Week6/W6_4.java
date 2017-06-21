package eval_it;

import java.util.Scanner;

public class W6_4 {
	public static void main(String[] args) {
		int foo = 0;
		stack stck = new stack(5);
		while(foo == 0)
		{
			System.out.println("1.Push 2.Pop 3.Exit");
			System.out.print("Enter Choice - ");
			@SuppressWarnings("resource")
			Scanner y = new Scanner(System.in);
			int z = y.nextInt();
			switch(z)
			{
				case 1: System.out.print("\nEnter Element - ");
						int temp = y.nextInt();
						try{stck.push(temp);}
						catch(PushException e)
						{System.out.println(e);}
						break;
				case 2: try
						{System.out.println(stck.pop());}
						catch(PopException e)
						{System.out.println(e);}
				 		break;
				case 3: foo = 1; break;
			}
		}
		System.out.println("bye");
	}
}

@SuppressWarnings("serial")
class PopException extends Exception
{
	public String toString()
	{
		return "String Underflow";
	}
}

@SuppressWarnings("serial")
class PushException extends Exception
{
	public String toString()
	{
		return "String Overflow";
	}
}

class stack
{
	private int stck[];
	private int tos;
	private PopException popex = new PopException();
	private PushException pushex = new PushException();
	
	stack(int size)
	{
		stck = new int[size];
		tos = -1;
	}
	
	public void push(int item) throws PushException
	{
		if(tos==stck.length-1)
			throw pushex;
		else
			stck[++tos] = item;
	}
	
	public int pop() throws PopException
	{
		if(tos<0)
			throw popex;
		else
			return stck[tos--];
	}
}