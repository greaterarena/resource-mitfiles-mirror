import java.util.*;

class arr1d
{
	public static void main(String args[])
	{
		array one = new array();
		one.read();
		System.out.print("Enter the key to be searched - ");
		Scanner in = new Scanner(System.in);
		int key = in.nextInt();
		one.search(key);	
	}
}

class array
{
	private int a[];
	void read()
	{	
		System.out.print("Enter size of array - ");
		Scanner in = new Scanner(System.in);
		a = new int[in.nextInt()];
		System.out.println("Enter the elements");
		for(int i=0;i<a.length;i++)
			a[i] = in.nextInt();
		System.out.println("array generated");
	}
	void display()
	{	
		System.out.print("Array - ");
		for(int i=0;i<a.length;i++)
			System.out.print(a[i]+" ");
		System.out.println("");		
	}
	void search(int key)
	{
		for(int i=0;i<a.length;i++)
			if(a[i]==key)
			{
				System.out.println("Match Found at - "+(i+1));
				return;
			}
		System.out.println("No Match");
	}
}
