import java.util.*;

class fact
{
	public static void main(String args[])
	{
		System.out.print("Enter a number - ");
		Scanner in = new Scanner(System.in);
		int temp = in.nextInt();
		int fact = getfact(temp);
		System.out.println("Factorial of "+temp+" = "+fact);
	}
	static int getfact(int f)
	{
		int fact = 1;
		while(f!=0)
		{
			fact = fact * f;
			f--;
		}
		return fact;
	}
}
