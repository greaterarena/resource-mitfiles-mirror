import java.util.Scanner;


public class ll2 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		lis me = new lis();
		Scanner in = new Scanner(System.in);
		int choice;
		while(true)
		{
			System.out.print("1.AddAtLast 2.DeleteAtHead 3.Display 4.Exit\n");
			System.out.print("Enter Choice - ");
			choice = in.nextInt();
			if(choice==1)
				me.AddAtLast();
			else if(choice==2)
				me.DeleteAtHead();
			else if(choice==3)
				me.display();
			else if(choice==4)
				break;
			else
				System.out.println("\nInvalid Choice");
		}
	}

}


class nod
{
	String name;
	int id;
	nod next = null;
	void print()
	{
		System.out.print("\nName - "+name+" ID - "+id);
	}
}

class lis
{
	nod head,tail;
	private Scanner in = new Scanner(System.in);
	lis()
	{
		head = tail = null;
	}
	void display()
	{
		if(isEmpty())
			return;
		nod temp = head;
		while(temp!=tail.next)
		{
			temp.print();
			temp = temp.next;
		}
		System.out.print("\n");
	}
	void AddAtLast()
	{
		nod temp = new nod();
		System.out.print("Enter ID - ");
		temp.id = in.nextInt();
		temp.name = in.nextLine();
		System.out.print("Enter Name - ");
		temp.name = in.nextLine();
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
	void DeleteAtHead()
	{
		if(isEmpty())
			return;
		head = head.next;					
	}	
}