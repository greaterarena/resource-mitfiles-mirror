import java.util.*;

class arr2d
{
	public static void main(String args[])
	{
		array one = new array();
		array two = new array();
		array three = new array();
		one.read();
		two.read();
		one.display();
		two.display();
		three.sum(one, two);
	}
}

class array
{
	private int a[][];
	void read()
	{	
		System.out.print("Enter no of rows - ");
		Scanner in = new Scanner(System.in);
		int row = in.nextInt();
		System.out.print("\nEnter no of columns - ");
		int col = in.nextInt();
		a = new int[row][col];
		System.out.println("Enter the elements");
		for(int i=0;i<row;i++)
			for(int j=0;j<col;j++)
				a[i][j] = in.nextInt();
		System.out.println("array generated");
	}
	void display()
	{	
		System.out.println("Array - ");
		for(int i=0;i<a.length;i++)
		{
			for(int j=0;j<a[i].length;j++)
				System.out.print(a[i][j]+" ");
			System.out.println();	
		}	
	}
	void sum(array a1, array a2)
	{
		if(a1.a.length!=a2.a.length || a1.a[0].length!=a2.a[0].length)
		{
			System.out.println("addition not possible");
			return;
		}	
		else
		{
			a = new int[a1.a.length][a1.a[0].length];
			for(int i=0;i<a1.a.length;i++)
				for(int j=0;j<a1.a[0].length;j++)
					a[i][j] = a1.a[i][j] + a2.a[i][j];
			display();
			return;
		}
	 
	}
}
