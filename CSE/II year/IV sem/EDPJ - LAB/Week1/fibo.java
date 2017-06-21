import java.util.*;

class fibo
{
	public static void main(String args[])
	{
		System.out.print("Enter limit for fibonacci series - ");
		Scanner in = new Scanner(System.in);
		int temp = in.nextInt();
		fibonacci fibo = new fibonacci();
		System.out.print("\nFibonacci series - ");
		for(int a=1;a<=temp;a++)
		{
			int samp = fibo.gen(a);
			System.out.print(samp+" ");
		}
		System.out.println();
	}
}

class fibonacci
{
	int gen(int x)
	{
		if(x<=1)
			return x;
		else
		return (gen(x-1) + gen(x-2));
	}
}
