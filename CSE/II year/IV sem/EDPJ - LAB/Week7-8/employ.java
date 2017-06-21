package eval_it;

import java.io.*;
import java.util.Scanner;

public class employ {
	
	static Scanner input = new Scanner(System.in);
	static FileWriter filemod1;
	static FileWriter filemod2;
	static String [] A_flush = new String [10];
	static int flush_counter = 0;
	
	public static void main(String[] args) {
		File file1 = new File("/home/student/12538/files/employee_1.txt");
		File file2 = new File("/home/student/12538/files/employee_2.txt");
		//File file1 = new File("d:/files/employee_1.txt");
		//File file2 = new File("d:/files/employee_2.txt");		
		
		int total_entries;
		
		try
		{
			filemod1 = new FileWriter(file1);
			filemod2 = new FileWriter(file2);
			String col_names = "Name  Age  Gross_Salary  Take_Home_Salary  Grade\n";
			writer(filemod1,col_names);
			writer(filemod2,col_names);
			Thread.sleep(50);
			System.out.println("Begin Input");
			System.out.print("Enter no of entries MAX 10 - ");
			total_entries = input.nextInt();
			if(total_entries>10)
			{
				System.out.println("More Than 10 entries not allowed");
				return;
			}
			all_writer(total_entries);
			filemod1.close();
			filemod2.close();
		}		
		catch(IOException e)
		{
			System.out.println("I/O Exception raised");
		}
		catch(InterruptedException e)
		{
			System.out.println("Thread Exception die");
		}
	}
	
	static void all_writer(int x)
	{
		String name;
		int age;
		double GrossSalary;
		float TakeHomeSalary;
		String Grade;
		for(int i = 1; i <= x; i++)
		{
			input.nextLine();
			System.out.print("\nInput your name - ");
			name = input.nextLine();
			System.out.print("\nInput your age - ");
			age = input.nextInt();
			System.out.print("\nInput your Gross Salaray - ");
			GrossSalary = input.nextDouble();
			System.out.print("\nInput your Take Home Salaray - ");
			TakeHomeSalary = input.nextFloat();
			System.out.print("\nInput your grade - ");
			Grade = input.next();
			
			if(Grade.equalsIgnoreCase("A"))
			{
				writer(filemod2,""+name+"  "+age+"  "+GrossSalary+"  "+TakeHomeSalary+"  "+Grade+"\n");
				A_flush[flush_counter++] = ""+name+"  "+age+"  "+GrossSalary+"  "+TakeHomeSalary+"  "+Grade;
			}
			else
				writer(filemod1,""+name+"  "+age+"  "+GrossSalary+"  "+TakeHomeSalary+"  "+Grade+"\n");
		}
		flush_grade_A();
	}
	
	static void flush_grade_A()
	{
		if(flush_counter==0)
			return;
		System.out.println("\nDisplaying all A grade records now\n");
		for(int i = 0; i < flush_counter; i++)
			System.out.println(A_flush[i]);
	}
	
	static void writer(FileWriter i_am_the_writer_who_shall, String this_string_into_your_file)
	{
		try
		{
			i_am_the_writer_who_shall.write(this_string_into_your_file);
		}
		catch(IOException e)
		{
			System.out.println("I/O Exception raised");
		}
	}
	
}
