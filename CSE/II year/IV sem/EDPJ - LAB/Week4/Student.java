import java.util.Scanner;
import java.util.Calendar;
import java.util.GregorianCalendar;

public class Student {

	/**
	 * @param args
	 */
	
	static data[] x = new data[5];	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
			System.out.print("\n*****************INPUT BEGIN***********\n");
			set_data();
			System.out.print("\n*****************SAMPLE PRINT***********\n");
			disp();
			System.out.print("\n*****************SORT SEM***********\n");
			sort_S(x);
			disp();
			System.out.print("\n*****************SORT NAME***********\n");
			sort_N(x);
			disp();
			System.out.print("\n*****************LIST NAME - S***********\n");
			begin_S();
			System.out.print("\n*****************LIST NAIK***********\n");
			naik_in();
			System.out.print("\n*****************INITIAL SPLIT***********\n");
			splitkill();
			disp();
	}
	
	static void disp()
	{
		int i = 0;
		while(i<x.length)
		{
			x[i].display();
			i++;
		}
	}
	
	static void set_data()
	{
		int i = 0;
		while(i!=x.length)
		{	
			x[i] = new data();
			x[i].input();
			i++;
		}
		disp();	
	}
	
	static void splitkill()
	{  
		for(int i=0;i<x.length;i++)
		{
			String new_name="";
			String temp[]=x[i].f_name.split(" ");
			for(int j=0; j<temp.length-1;j++)
			{
				new_name += temp[j].charAt(0)+".";
			}
			new_name += temp[temp.length-1];
			x[i].f_name = new_name;
		}
	}
	

	static void naik_in()
	{
		for(int i=0;i<x.length;i++)
		{
			if((x[i].f_name.contains("Naik"))||(x[i].f_name.contains("naik")))
				System.out.println(x[i].f_name);
		}
	}
	
	static void begin_S()
	{
		for(int i=0;i<x.length;i++)
		{
			if((x[i].f_name.charAt(0)=='S')||(x[i].f_name.charAt(0)=='s'))
				x[i].display();
		}
	}
	
	static void sort_N(data x[])
	{
		int n=x.length;
		for(int i=0;i<n-1;i++)
		{
			for(int j=0;j<n-i-1;j++)
			{
				if(x[j].f_name.compareToIgnoreCase(x[j+1].f_name)>0)
				{
					data temp=x[j];
					x[j]=x[j+1];
					x[j+1]=temp;
				}
			}
		}
	}
	
	static void sort_S(data x[])
	{
		int l = x.length;
		for(int i=0;i<l-1;i++)
		{
			for(int j=0;j<l-i-1;j++)
			{
				if(x[j].sem>x[j+1].sem)
				{
					data temp=x[j];
					x[j]=x[j+1];
					x[j+1]=temp;
				}
				else
					if(x[j].sem==x[j+1].sem)
					{
						if(x[j].cgpa>x[j+1].cgpa)
						{
							data temp= x[j];
							x[j]=x[j+1];
							x[j+1]= temp;
						}
					}
			}			
		}
	}
}

class data
{
	int reg_no;
	String f_name;
	GregorianCalendar doj;
	short sem;
	float gpa,cgpa;
	static int count = 0;
	private Scanner sc=new Scanner(System.in);
	void input()
	{
		System.out.print("\nEnter Name - ");
		f_name = sc.nextLine();
		System.out.print("\nEnter Date YYYY MM DD - ");
		int y = sc.nextInt();
		int m = sc.nextInt();
		int d = sc.nextInt();
		System.out.print("\nEnter Semester - ");
		sem = sc.nextShort();
		System.out.print("\nEnter GPA - ");
		gpa = sc.nextFloat();
		System.out.print("\nEnter CGPA - ");
		cgpa = sc.nextFloat();
		doj = new GregorianCalendar(y,m,d);
		String regno_Set = (doj.get(Calendar.YEAR)%100) + "" +(reg_no%10);
		reg_no = Integer.parseInt(regno_Set);
		System.out.println("\nSuccessful");		
	}
	data()
	{
		f_name = "";
		doj = new GregorianCalendar(2014,01,01);
		sem = 0;
		gpa = cgpa = 0;
		count++;
		String regno_Set = (doj.get(Calendar.YEAR)%100) + "" +count;
		reg_no = Integer.parseInt(regno_Set);		
	}
	data(String name,int y, int m, int d,short sem1, float gpa1, float cgpa1)
	{
		f_name = name;
		doj = new GregorianCalendar(y,m,d);
		sem = sem1;
		gpa = gpa1;
		cgpa = cgpa1;
		count++;
		String regno_Set = (doj.get(Calendar.YEAR)%100) + "" +count;
		reg_no = Integer.parseInt(regno_Set);
	}
	data(data x)
	{
		f_name = x.f_name;
		doj = x.doj;
		sem = x.sem;
		gpa = x.gpa;
		cgpa = x.cgpa;
		count++;
		String regno_Set = (doj.get(Calendar.YEAR)%100) + "" +count;
		reg_no = Integer.parseInt(regno_Set);
	}
	void display()
	{
		System.out.print("\nName - "+f_name+"\nReg_no - "+reg_no);
		System.out.print("\nSemester - "+sem+"\nGPA  - "+gpa);
		System.out.print("\nCGPA - "+cgpa);
		System.out.print("\nDate Joined - "+doj.get(Calendar.DATE));
		System.out.print("-"+doj.get(Calendar.MONTH)+"-");
		System.out.println(doj.get(Calendar.YEAR));
	}
}
