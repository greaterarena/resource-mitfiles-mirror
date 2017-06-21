class pay1
{
	double h,pph,wr,gp,np;
	void computenetpay(double h, double pph, double wr)
	{
		np = (h*pph) - (h*pph*wr);
		System.out.println(np);
	}
	void computenetpay(double h)
	{
		np = (h*5.85) - (h*5.85*0.15);
		System.out.println(np);
	}
	void computenetpay(double h, double pph)
	{
		np = (h*pph) - (h*pph*0.15);
		System.out.println(np);
	}
}

class pay
{
	public static void main(String args[])
	{
		pay1 p = new pay1();
		p.h = 10;
		p.pph = 20;
		p.wr = 0.12;
		p.computenetpay(p.h,p.pph,p.wr);
		p.computenetpay(p.h,p.pph);
		p.computenetpay(p.h);
	}
}