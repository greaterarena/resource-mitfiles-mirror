package eval_it;

import java.util.*;

public class W6_3 {

	public static void main(String[] args) {
		data x = new data();
		data y = new data();
		try
		{
			x.input();
			y.input();
		}
		catch(studex e)
		{
			System.out.println(e);
			return;
		}
		catch(InputMismatchException e)
		{
			System.out.println("Wrong Input");
			return;
		}
		
		x.display();
		y.display();
	}

}

class data
{
	int reg_no;
	String f_name;
	GregorianCalendar doj;
	static int count = 23;
	private Scanner sc=new Scanner(System.in);
	void input() throws studex,InputMismatchException
	{
		count++;
		studex temp = new studex();
		if(count>=25)
			throw temp;
		System.out.print("\nEnter Name - ");
		f_name = sc.nextLine();
		System.out.print("\nEnter Date YYYY MM DD - ");
		int y = sc.nextInt();
		int m = sc.nextInt();
		int d = sc.nextInt();
		doj = new GregorianCalendar(y,m,d);
		String regno_Set = (doj.get(Calendar.YEAR)%100) + "";
		reg_no = Integer.parseInt(regno_Set);
		reg_no = (reg_no*100) + count;
		System.out.println("\nSuccessful");		
	}
	
	void display()
	{
		System.out.print("\nName - "+f_name+"\nReg_no - "+reg_no);
		System.out.print("\nDate Joined - "+doj.get(Calendar.DATE));
		System.out.print("-"+doj.get(Calendar.MONTH)+"-");
		System.out.println(doj.get(Calendar.YEAR));
	}
}

@SuppressWarnings("serial")
class studex extends Exception
{
	public String toString()
	{
		return "All Seats have been filled sorry";
	}
}
