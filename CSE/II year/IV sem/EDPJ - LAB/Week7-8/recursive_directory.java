package eval_it;

import java.io.*;

public class recursive_directory {

	static File f1; 
	static int count = 1;
	
	public static void main(String[] args)
	{
		f1 = new File("/home/student");
		System.out.println(f1.getName());
		go_fetch(f1);
	}
	
	static void go_fetch(File x)
	{		
		if(!x.isDirectory())
		{
			System.out.print("|");
			for(int i=0;i<count;i++)
				System.out.print("--");
			System.out.println(x.getName());
			return;
		}
		else
		{
			String [] temp = x.list();
			if(temp.length==0)
				return;
			for(int i =0;i<temp.length;i++)
			{
				File exp = new File(x.getAbsolutePath()+"/"+temp[i]);
				if(exp.isDirectory())
				{
					System.out.print("|");
					for(int j=0;j<count;j++)
						System.out.print("--");
					System.out.println(exp.getName());
				}				
				count++;
				go_fetch(exp);
				count--;
			}
		}
	}
}
