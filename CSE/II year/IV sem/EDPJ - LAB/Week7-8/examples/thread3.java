
public class thread3 {
	
	public static void main(String[] args) {
		
		new ThreadExtender();
		Thread main = Thread.currentThread();
		main.setName("Main");
		System.out.println("Main Thread - " + main);
		try
		{
			for(int i = 5; i > 0; i--)
			{
				System.out.println("Main Print - " + i);
				Thread.sleep(500);
			}
		}
		catch(InterruptedException e)
		{
			System.out.println("Thread " + main.getName() + " raised exception");
		}
		System.out.println("Main has Died");		
	}

}

class ThreadExtender extends Thread
{
	ThreadExtender()
	{
		super("Active");
		System.out.println("Child Thread - " + this);
		start();
	}
	
	public void run()
	{
		try 
		{
			for(int i = 5; i > 0; i--)
			{
				System.out.println("Child Print - " + i);
				Thread.sleep(100);
			}				
		}
		catch(InterruptedException e)
		{
			System.out.println("somethings wrong here child");
		}
		System.out.println("Child has Died");
	}
}