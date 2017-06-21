import java.io.*;

public class file_in {
	
	static void p(String s)
	{
		System.out.println(s);
	}

	public static void main(String[] args) {
		File file1 = new File("/home/student/12538/files/file1.txt");
		p(""+file1.isDirectory());
		p(""+file1.exists());
		try
		{
			FileWriter filemod1 = new FileWriter(file1);
			String source = "This is just some sample text which suddenly\nhas skipped a line";
			String source1 = "\ni wrote to that file again\nSKip that Liiiiine";
			filemod1.write(source);
			Thread.sleep(50);
			filemod1.write(source1);
			System.out.println("All done");
			filemod1.close();
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
}