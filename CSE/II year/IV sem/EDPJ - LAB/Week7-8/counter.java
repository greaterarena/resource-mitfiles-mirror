package eval_it;

import java.io.*;

public class counter 
{
	static int line_count = 0;
	static int char_count = 0;
	static int word_count = 0;
	static int num_count = 0;
	static int num_flag = 0;
	public static void main(String[] args) throws IOException
	{
		File x = new File("/home/student/12538/files/Placed.txt");	
		RandomAccessFile f1 = new RandomAccessFile(x,"r");
		System.out.println("Displaying contents of file - "+ x.getName());
		checker(f1);
		System.out.println("\nNumber of Lines - "+line_count);
		System.out.println("\nNumber of Words - "+word_count);
		System.out.println("\nNumber of Characters - "+char_count);
		System.out.println("\nNumber of Numbers - "+num_count);
		f1.close();
	}
	static void checker(RandomAccessFile f1) throws IOException
	{
		while(f1.getFilePointer()!=f1.length())
		{
			System.out.println(f1.readLine());
			line_count++;
		}					
		f1.seek(0);
		
		while(f1.getFilePointer()!=f1.length())
		{
			int temp = f1.read();
			if(temp == 32)
			{
				word_count++;
				reset_flags();
			}
			if(temp != 32 && temp!= 10 && temp >57)
			{
				char_count++;
				reset_flags();
			}
			if(temp == 10)
			{
				reset_flags();
			}
			if(temp >= 48 && temp <=57)
			{
				num_flag++;
			}			
		}		
		word_count += line_count;
	}
	
	static public void reset_flags()
	{
		if(num_flag>0)
		{
			num_count++;
			num_flag = 0;
		}
	}	
}