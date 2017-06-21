import java.util.Scanner;


public class ll3 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		li li1 = new li();
		li li2 = new li();
		li li3 = new li();
		li1.AddAtLast(1);
		li1.AddAtLast(2);
		li1.AddAtLast(7);
		li1.AddAtLast(8);
		li2.AddAtLast(3);
		li2.AddAtLast(4);
		li2.AddAtLast(5);
		li2.AddAtLast(6);
		li3.mergesort(li1,li2);
		li3.display();
	}
}

class no
{
	int x;
	no next = null;
}

class li
{
	no head,tail;
	private Scanner in = new Scanner(System.in);
	li()
	{
		head = tail = null;
	}
	void display()
	{
		if(isEmpty())
			return;
		no temp = head;
		while(temp!=tail.next)
		{
			System.out.print(temp.x+" ");
			temp = temp.next;
		}
		System.out.print("\n");
	}
	void AddAtLast(int x)
	{
		no temp = new no();
		temp.x = x;
		if(head == null && tail == null)
		{
			head = tail = temp;
		}
		else
		{
			tail.next = temp;
			tail = tail.next;
		}
	}
	boolean isEmpty()
	{
		if(head==null || tail==null)
		{
			System.out.println("List Empty");
			return true;
		}
		else
			return false;
	}
	void mergesort(li x, li y)
	{
		no x1 = x.head;
		no y1 = y.head;
		while(x1!=null)
		{	
			while(y1!=null)
			{
				if(y1.x<x1.x)
				{
					AddAtLast(y1.x);
				}
				else
				{
					AddAtLast(x1.x);
					break;
				}
				y1 = y1.next;
			}
			if(y1==null)break;	
			x1 = x1.next;
		}
		while(x1!=null)
		{
			AddAtLast(x1.x);
			x1= x1.next;
		}
	}
}