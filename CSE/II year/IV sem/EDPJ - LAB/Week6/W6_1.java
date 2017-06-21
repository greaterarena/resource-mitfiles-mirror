package eval_it;

interface stacker
{
	void push(int item);
	int pop();
}

class fixed implements stacker
{
	private int stck[];
	private int tos;
	
	fixed(int size)
	{
		stck = new int[size];
		tos = -1;
	}
	
	public void push(int item)
	{
		if(tos==stck.length-1)
			System.out.println("Stack Overflow");
		else
			stck[++tos] = item;
	}
	
	public int pop()
	{
		if(tos<0)
		{
			System.out.println("Stack Underflow");
			return 0;
		}
		else
			return stck[tos--];
	}
}


class dynamic implements stacker
{
	private int stck[];
	private int tos;
	
	dynamic(int size)
	{
		stck = new int[size];
		tos = -1;
	}
	public void push(int item)
	{
		if(tos==stck.length-1)
		{
			int [] temp = new int[stck.length*2];
			for(int i=0; i<stck.length;i++)
				temp[i] = stck[i];
			stck = temp;
			stck[++tos] = item;
		}
		else
			stck[++tos] = item;
	}
	public int pop()
	{
		if(tos<0)
		{
			System.out.println("Stack Underflow");
			return 0;
		}
		else
			return stck[tos--];
	}
}

public class W6_1 {


	public static void main(String args[])
	{
		fixed fix = new fixed(5);
		dynamic dyn = new dynamic(5);
		
		for(int i = 0; i < 10; i++)
		{
			dyn.push(i);
			if(i<5)
				fix.push(i);
		}
		System.out.println("Fixed stack contents - ");
		for(int i=0;i<5;i++)
			System.out.print(""+fix.pop()+" ");
		System.out.println("");
		System.out.println("Dynamic stack contents - ");
		for(int i=0;i<10;i++)
			System.out.print(""+dyn.pop()+" ");
		System.out.println("");
		fix.pop();
		dyn.pop();
	}

}

