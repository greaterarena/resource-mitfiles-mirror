import java.util.*;

class tmx
{
	public static void main(String args[])
	{
		Time c1 = new Time();
		Time c2 = new Time();
		Time c3 = new Time();
		c1.read();
		c1.display();
		c2.read();
		c2.display();
		c3 = c1.add(c2);
		c3.display();
		c3 = c1.sub(c2);
		c3.display();	
		c1.comp(c2);	
	}
}

class Time
{
	int h,m,s;
	void normalize()
	{
		if(s>=60)
		{
			m += s/60;
			s = s%60;
		}
		if(s<0)
		{
			m += s/60;
			s = 60 + (s%60);
		}
		if(m>=60)
		{
			h += m/60;
			m = m%60;
		}
		if(m<0)
		{
			h += m/60;
			m = 60 + (m%60);
		}
		if(h>=24)
		{
			h = h%24;
		}
		if(h<0)
		{
			h = 24 + (h%24);
		}
	}
	void read()
	{	
		System.out.print("Enter Hour - ");
		Scanner in = new Scanner(System.in);
		h = in.nextInt();
		System.out.print("Enter Minutes - ");
		m = in.nextInt();
		System.out.print("Enter Seconds - ");
		s = in.nextInt();
		System.out.println("time stored");
		normalize();
	}
	void display()
	{	
		System.out.println("Time - "+h+":"+m+":"+s);
	}
	Time add(Time y)
	{
		Time temp = new Time();
		temp.h = h + y.h;
		temp.m = m + y.m;
		temp.s = s + y.s;
		System.out.println("Time added");
		temp.normalize();
		return temp;
	}
	Time sub(Time y)
	{
		Time temp = new Time();
		temp.h = h - y.h;
		temp.m = m - y.m;
		temp.s = s - y.s;
		System.out.println("Time subtracted");
		temp.normalize();
		return temp;
	}
	void comp(Time x)
	{
		int t1 = (h*60*60)+(m*60)+s;		
		int t2 = (x.h*60*60)+(x.m*60)+x.s;	
		if(t2>t1)
			System.out.println("Time 2 is greater");	
		else if(t1>t2)
			System.out.println("Time 1 is greater");
		else if(t1==t2)
			System.out.println("both the times are equal");
	}
}
