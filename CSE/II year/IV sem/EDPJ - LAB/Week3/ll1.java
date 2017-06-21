import java.util.Scanner;


public class ll1 {
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		list me = new list();
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
				System.out.print("\nInvalid Choice");
		}
	}
}

class node
{
	int x;
	node next = null;
}

class list
{
	node head,tail;
	private Scanner in = new Scanner(System.in);
	list()
	{
		head = tail = null;
	}
	void display()
	{
		if(isEmpty())
			return;
		node temp = head;
		while(temp!=tail.next)
		{
			System.out.print(temp.x+" ");
			temp = temp.next;
		}
		System.out.print("\n");
	}
	void AddAtLast()
	{
		node temp = new node();
		System.out.print("Enter element - ");
		temp.x = in.nextInt();
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