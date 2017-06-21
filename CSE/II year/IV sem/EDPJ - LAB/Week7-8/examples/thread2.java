
public class thread2 {
	
	public static void main(String[] args) {
		new ThreadRunnable();
		Thread main = Thread.currentThread();
		main.setName("Main");
		System.out.println("Main Thread - "+main);
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
			System.out.println("somethings wrong here child");
		}
		System.out.println("Main has Died");
	}

}

class ThreadRunnable implements Runnable 
{
	Thread t;
	
	ThreadRunnable()
	{
		t = new Thread(this,"Radio");
		System.out.println("Child Thread - " + t);
		t.start();
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
