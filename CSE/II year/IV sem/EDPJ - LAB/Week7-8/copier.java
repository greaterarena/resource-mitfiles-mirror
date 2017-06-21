package eval_it;

import java.io.*;

public class copier {

	public static void main(String[] args) throws IOException {
		File main = new File("/home/student/12538/files/Placed.txt");
		File byter = new File("/home/student/12538/files/readbyte.txt");
		File charr = new File("/home/student/12538/files/readchar.txt");
		FileInputStream byte_in = new FileInputStream(main);
		FileOutputStream byte_out = new FileOutputStream(byter);
		byte_copier(byte_in,byte_out);
		FileReader char_in = new FileReader(main);
		FileWriter char_out = new FileWriter(charr);
		char_copier(char_in,char_out);
		byte_in.close();
		byte_out.close();
		char_in.close();
		char_out.close();		
	}
	
	public static void byte_copier(FileInputStream in, FileOutputStream out) throws IOException
	{
		byte [] temp = new byte[in.available()];
		while(in.available()!=0)
		{
			in.read(temp);
			out.write(temp);			
		}
		System.out.println("Byte Stream copy complete");
		return;
	}
	
	public static void char_copier(FileReader in, FileWriter out) throws IOException
	{
		int temp;
		while((temp = in.read()) != -1)
		{
			out.write(temp);			
		}
		System.out.println("Char Stream copy complete");
		return;
	}
}
