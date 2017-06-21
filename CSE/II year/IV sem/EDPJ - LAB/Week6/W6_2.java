package eval_it;

import java.util.*;

public class W6_2 {

	public static void main(String[] args) {
		employee x = new employee();
		int foo = 0;
		while(foo == 0)
		{
			System.out.println("1.Input 2.Display 3.Exit");
			System.out.print("Enter Choice - ");
			@SuppressWarnings("resource")
			Scanner y = new Scanner(System.in);
			int z = y.nextInt();
			switch(z)
			{
				case 1: x.input(); break;
				case 2: x.display(); break;
				case 3: foo = 1; break;
			}
		}
		System.out.println("bye");
	}

}

class employee
{
	String name;
	int age;
	double g_sal;
	float th_sal;
	char grade;
	private Scanner x;
	
	void input()
	{
		try
		{
			x = new Scanner(System.in);
			System.out.print("\nName - ");
			name = x.nextLine();
			System.out.print("\nAge - ");
			age = x.nextInt();
			System.out.print("\nG_SAL - ");
			g_sal = x.nextDouble();
			System.out.print("\nTH_SAL - ");
			th_sal = x.nextFloat();
			System.out.print("\nGrade - ");
			String temp = x.next();
			grade = temp.charAt(0);		
		}
		catch(InputMismatchException e)
		{
			System.out.println("INVALID INPUT\nplease re-enter all details");
			input();		
		}
	}
	
	void display()
	{
		System.out.println("\nName - "+name+"\nAge - "+age);
		System.out.println("G_SAL - "+g_sal+"\nTH_SAL"+th_sal);
		System.out.println("Grade - "+grade);
	}
	
}
