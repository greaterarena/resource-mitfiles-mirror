package eval_it;

import java.io.*;

public class cpp_multithreaded_reader
{
	static int line_count = 0;
	public static void main(String[] args) throws IOException
	{
		File x = new File("/home/student/12538/files/readme.txt");	
		RandomAccessFile f1 = new RandomAccessFile(x,"r");
		RandomAccessFile f2 = new RandomAccessFile(x,"r");
		System.out.println("Displaying contents of file - "+ x.getName());
		while(f1.getFilePointer()!=f1.length())
		{
			System.out.println(f1.readLine());
			line_count++;
		}			
		System.out.println("\nBegin search for .cpp files - ");
		new threader("1",f1);
		new threader("2",f2);
	}
}

class threader extends Thread
{
	RandomAccessFile f1;
	threader(String x,RandomAccessFile t)
	{
		super(x);
		f1=t;		
		start();
	}
	
	public void run()
	{
		try{
			if(Integer.parseInt(this.getName())==1)
				f1.seek(0);
			if(Integer.parseInt(this.getName())==2)
				f1.seek(f1.length()/2);}
			catch(IOException e){}
		for(int i = 0; i<cpp_multithreaded_reader.line_count/2+1; i++)
		{
			try{String temp = f1.readLine();
			if(temp.endsWith(".cpp"))
				System.out.println(temp);}catch(IOException e){}
			catch(NullPointerException e){}
		}	
	}
} 
