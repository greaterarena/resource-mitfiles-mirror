import java.util.Scanner;


public class stlst {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		lerd me = new lerd();
		Scanner in = new Scanner(System.in);
		int choice;
		while(true)
		{
			System.out.print("1.Push 2.Pop 3.Display 4.Exit\n");
			System.out.print("Enter Choice - ");
			choice = in.nextInt();
			if(choice==1)
				me.push();
			else if(choice==2)
				me.pop();
			else if(choice==3)
				me.display();
			else if(choice==4)
				break;
			else
				System.out.print("\nInvalid Choice");
		}
	}

}

class nerd
{
	int x;
	nerd next = null;
}

class lerd
{
	nerd head,tail;
	private Scanner in = new Scanner(System.in);
	lerd()
	{
		head = tail = null;
	}
	void display()
	{
		if(isEmpty())
			return;
		nerd temp = head;
		while(temp!=tail.next)
		{
			System.out.print(temp.x+" ");
			temp = temp.next;
		}
		System.out.print("\n");
	}
	void push()
	{
		nerd temp = new nerd();
		System.out.print("Enter element - ");
		temp.x = in.nextInt();
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
	void pop()
	{
		if(isEmpty())
			return;
		System.out.println("Popped element - "+head.x);
		head = head.next;					
	}	
}