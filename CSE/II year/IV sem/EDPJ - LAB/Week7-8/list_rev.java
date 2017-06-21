package eval_it;

import java.io.*;

public class list_rev {

	public static void main(String[] args) throws IOException {
		File x = new File("/home/student/12538/files/Placed.txt");
		RandomAccessFile f1 = new RandomAccessFile(x,"r");
		list l1 = new list();
		list l2 = new list();
		while(f1.getFilePointer()!=f1.length())
		{
			String temp = f1.readLine();
			String temp1 []=temp.split("");
			String temp2 = "";
			String temp3;
			for(int i = 0; i < temp1.length; i++)
				l2.insert(temp1[i]);
			try{while((temp3 = l2.give_back()) !=  null)
			{
				temp2 += temp3;
			}}
			catch(NullPointerException e){}
			l1.insert(temp2);
		}		
			
		String temp;
		FileWriter f2 = new FileWriter(x);
		
		
		try{
			while((temp = l1.give_back()) !=  null)
			{
				f2.write(temp+"\n");
			}
		}
		catch(NullPointerException e){}
		
		
		f1.close();
		f2.close();
		System.out.println("all done");
	}

}


class list_node
{
	String data;
	list_node next;
}

class list
{
	list_node head = null;
	list_node tail = null;

	public void insert(String x)
	{
		list_node temp = new list_node();
		temp.data = x;
		if(head == null && tail == null)
		{
			head = tail = temp;
		}
		else
		{
			temp.next = head;
			head = temp;
		}
	}
	
	public String give_back() throws NullPointerException
	{
		String temp = head.data;
		head = head.next;	
		return temp;		
	}
}