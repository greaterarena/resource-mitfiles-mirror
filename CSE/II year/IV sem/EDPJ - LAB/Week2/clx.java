import java.util.*;

class clx
{
	public static void main(String args[])
	{
		Complex c1 = new Complex();
		Complex c2 = new Complex();
		Complex c3 = new Complex();
		c1.read();
		c1.display();
		c2.read();
		c2.display();
		c3 = c1.add(c2);
		c3.display();	
		c3 = c1.sub(c2);
		c3.display();	
	}
}

class Complex
{
	int r,i;
	void read()
	{	
		System.out.print("Enter real part - ");
		Scanner in = new Scanner(System.in);
		r = in.nextInt();
		System.out.print("Enter imaginary part - ");
		i = in.nextInt();
		System.out.println("number stored");
	}
	void display()
	{	
		System.out.println(r+" + "+i+"i");
	}
	Complex add(Complex y)
	{
		Complex temp = new Complex();
		temp.r = r + y.r;
		temp.i = i + y.i;
		System.out.println("Addition Successful");
		return temp;
	}
	Complex sub(Complex y)
	{
		Complex temp = new Complex();
		temp.r = r - y.r;
		temp.i = i - y.i;
		System.out.println("Subtraction Successful");
		return temp;
	}
}
