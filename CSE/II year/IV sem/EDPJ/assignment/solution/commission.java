import java.util.*;

class q1
{
	double sale,cr;
	int cr1;
	void computeCommission(double a, double b)
	{
		System.out.println(a*b);
	}
	void computeCommission(double a, int b)
	{
		System.out.println(a*(b/100.0));
	}
	void computeCommission(double a)
	{
		System.out.println(a*(7.5/100));
	}
}

class commission
{
	public static void main(String args[])
	{
		q1 c = new q1();
		c.sale = 1000.34;
		c.cr = 0.56;
		c.cr1 = 34;
		c.computeCommission(c.sale,c.cr);
		c.computeCommission(c.sale,c.cr1);
		c.computeCommission(c.sale);
	}
}