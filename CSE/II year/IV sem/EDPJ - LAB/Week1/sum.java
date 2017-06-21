import java.util.*;

class sum
{
	public static void main(String args[])
	{
		System.out.print("Enter a number - ");
		Scanner in = new Scanner(System.in);
		int temp = in.nextInt();
		int a = temp;
		int sum = 0;
		while(a!=0)
		{		
			sum = sum + (a%10);
			a /= 10;	
		}
		System.out.println("The sum of digits of "+temp+" = "+sum);
	}
}
