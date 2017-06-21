
public class thread4 {
	
	public static void main(String[] args) {
		
		new ThreadRunnableMultiple("Imagine");
		new ThreadRunnableMultiple("Dragons");
		new ThreadRunnableMultiple("Radioactive");
		
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

class ThreadRunnableMultiple implements Runnable 
{
	Thread t;
	
	ThreadRunnableMultiple(String name)
	{
		t = new Thread(this,name);
		System.out.println("Child Thread - " + t);
		t.start();
	}
	
	public void run()
	{
		try 
		{
			for(int i = 5; i > 0; i--)
			{
				System.out.println("Child Print - " + t.getName() + " - " + i);
				Thread.sleep(100);
			}				
		}
		catch(InterruptedException e)
		{
			System.out.println("somethings wrong here child " + t.getName() + " - has raised an exception");
		}
		System.out.println("Child - " + t.getName() + " - has Died");
	}	
}
