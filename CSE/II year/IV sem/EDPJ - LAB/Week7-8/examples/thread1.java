
public class thread1 {

	public static void main(String[] args) {
		Thread t = Thread.currentThread();
		System.out.println("Currrent Thread - " + t);
		t.setName("Radioactive");
		System.out.println("New Name - " + t);
		try 
		{
			for(int n = 5; n > 0; n--)
			{
				System.out.println(n);
				Thread.sleep(1000);
			}
		}
		catch(InterruptedException e)
		{
			System.out.println("Radioactive interruption");
		}		
	}

}
