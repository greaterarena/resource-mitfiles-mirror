
public class thread5 {
	
	public static void main(String[] args) {
		
		new ThreadExtenderMultiple("Imagine");
		new ThreadExtenderMultiple("Dragons");
		new ThreadExtenderMultiple("Radioactive");
		
		Thread main = Thread.currentThread();
		main.setName("Main");
		System.out.println("Main Thread - " + main);
		try
		{
			for(int i = 5; i > 0; i--)
			{
				System.out.println("Main Print - " + i);
				Thread.sleep(200);
			}
		}
		catch(InterruptedException e)
		{
			System.out.println("Thread " + main.getName() + " raised exception");
		}
		System.out.println("Main has Died");		
	}

}

class ThreadExtenderMultiple extends Thread
{
	ThreadExtenderMultiple(String name)
	{
		super(name);
		System.out.println("Child Thread - " + this);
		start();
	}
	
	public void run()
	{
		try 
		{
			for(int i = 5; i > 0; i--)
			{
				System.out.println("Child Print - " + this.getName() + " - " + i);
				Thread.sleep(100);
			}				
		}
		catch(InterruptedException e)
		{
			System.out.println("somethings wrong here child - " + this.getName() + " - has raised an exception");
		}
		System.out.println("Child - " + this.getName() + " - has Died");
	}
}