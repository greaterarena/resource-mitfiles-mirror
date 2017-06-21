import java.util.Calendar;
import java.util.Scanner;
import java.util.GregorianCalendar;

public class hospital {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		billing test = new billing();
		test.input_Patient_Data();
		test.input_Inpatient_Data();
		test.input_Billing_Data();
		test.display_Patient_Data();
		test.display_Inpatient_Data();
		test.generate_Bill();
	}
}

class patient
{
	private String name;
	private int age;
	private long hospital_number;
	protected Scanner in = new Scanner(System.in);
	
	void input_Patient_Data()
	{
		System.out.print("Enter Patient Name - ");
		name = in.nextLine();
		System.out.print("\nEnter Patient Age - ");
		age = in.nextInt();
		System.out.print("\nPlease Wait while we assign a hospital number to the new patient");
		load();
		hospital_number = Math.round(Math.random()*10000000);
		System.out.print("\nPatient record stored");		
	}
	
	void display_Patient_Data()
	{
		System.out.print("\nFetching Patient Data");
		load();
		System.out.print("\n\nName - "+name+"\nAge - "+age);
		System.out.print("\nHospital Number - "+hospital_number);
	}
	
	static void load()
	{
		try
		{
			for(int i = 0; i < 2; i++)
			{
				Thread.sleep(500);
				System.out.print(".");
			}			
		}
		catch(InterruptedException e){}
	}
}

class inpatient extends patient
{
	private String department_name;
	protected int room_type;
	protected GregorianCalendar admission_date;
	
	void input_Inpatient_Data()
	{
		in.nextLine();
		System.out.print("\nEnter Department Name - ");
		department_name = in.nextLine();
		System.out.print("\nEnter Room Type 1.Special 2.SemiSpecial ");
		System.out.print("3.General - ");
		room_type = in.nextInt();
		System.out.print("\nEnter admission date DD MM YYYY - ");
		int d = in.nextInt();
		int m = in.nextInt();
		int y = in.nextInt();
		admission_date = new GregorianCalendar(y,m,d);
		load();
		System.out.print("\nInPatient record stored");
	}
	
	void display_Inpatient_Data()
	{
		System.out.print("\nFetching InPatient Data");
		load();
		System.out.print("\n\nDepartment Name - "+department_name+"\nRoom Type - "+room_type);
		System.out.print("\ndate of admission - "+admission_date.get(Calendar.DATE));
		System.out.println("-"+admission_date.get(Calendar.MONTH)+"-"+admission_date.get(Calendar.YEAR));
	}
}

class billing extends inpatient
{
	private GregorianCalendar discharge_date;
	private int final_Cost = 0;
	
	void input_Billing_Data()
	{
		System.out.print("\nEnter discharge date DD MM YYYY - ");
		int d = in.nextInt();
		int m = in.nextInt();
		int y = in.nextInt();
		discharge_date = new GregorianCalendar(y,m,d);
		load();
		System.out.print("\nBilling record stored");
	}
	void generate_Bill()
	{
		long days = discharge_date.getTimeInMillis() - admission_date.getTimeInMillis();
		days = days/(1000*60*60*24);
		int totaldays = (int)days;
		System.out.print("\nGenerating days");
		load();
		System.out.print("\nNumber of days - "+totaldays);
		switch(room_type)
		{
			case 1: final_Cost = 1000*totaldays;break;
			case 2: final_Cost = 500*totaldays;break;
			case 3: final_Cost = 100*totaldays;break;
		    default:System.out.println("Invalid Room Type");
		}
		System.out.println("\nTotal COst - "+final_Cost);
	}
}