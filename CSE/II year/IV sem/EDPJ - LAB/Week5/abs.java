import java.util.Scanner;

public class abs {

	private static Scanner z;

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		z = new Scanner(System.in);
		System.out.println("Calculate area");
		System.out.println("1. Rectangle 2. Triangle 3. Square 4. Exit");
		while(true)
		{
			System.out.println("Enter Choice - ");
			int choice = z.nextInt();
			int flag = 0;
			switch(choice)
			{
				case 1: Rectangle test = new Rectangle();
						test.area();
						break;
				case 2: Triangle test1 = new Triangle();
						test1.area();
						break;
				case 3: Square test2 = new Square();
						test2.area();
						break;
				case 4: flag = 1;
						System.out.println("Bye");
						break;
				default:System.out.println("Invalid Choice");
			}
			if(flag==1)
				break;
		}		
	}
}

abstract class Figure
{
	int x;
	int y;
	protected Scanner z = new Scanner(System.in);
	abstract void area();	
}

class Rectangle extends Figure
{
	Rectangle()
	{
		System.out.print("\nInput length and breadth -");
		x = z.nextInt();
		y = z.nextInt();
	}
	void area()
	{
		System.out.println("Area of Rectangle - "+(x*y));
	}
}
class Triangle extends Figure
{
	Triangle()
	{
		System.out.print("\nInput base and height -");
		x = z.nextInt();
		y = z.nextInt();
	}
	void area()
	{
		System.out.println("Area of triangle - "+(x*y*0.5));
	}
}
class Square extends Figure
{
	Square()
	{
		System.out.print("\nInput side -");
		x = z.nextInt();
	}
	void area()
	{
		System.out.println("Area of Square - "+(x*x));
	}
}