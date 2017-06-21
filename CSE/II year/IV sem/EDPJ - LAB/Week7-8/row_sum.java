
public class row_sum {

	static int [][] matrix = {{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
	static int [] rowsum = new int[matrix.length];
	static int final_sum = 0;
	
	public static void main(String[] args) {
		
		try
		{
			for(int i = 0; i < matrix.length; i++)
			{
				new ThreadRowSum("" + i);
				Thread.sleep(50);
			}
			Thread.sleep(100);
			
			System.out.println("INITIATING TOTAL ROW SUM");
			
			for(int i = 0; i < rowsum.length; i++)
				final_sum += rowsum[i];
			
			Thread.sleep(50);
			
			System.out.println("Final sum - "+final_sum);
		}
		catch(InterruptedException e)
		{
			System.out.println("Main Thread has Failed");
		}	
	}

}

class ThreadRowSum extends Thread 
{
	int row_tracker;
	int sum = 0;
	
	ThreadRowSum(String name)
	{
		super(name);
		row_tracker = Integer.parseInt(name);
		System.out.println("Beginning Row Sum of Row - " + row_tracker);
		start();
	}
	
	public void run()
	{
		for(int i = 0; i < row_sum.matrix[row_tracker].length; i++)
			sum += row_sum.matrix[row_tracker][i];
		System.out.println("Row Sum for Row - " + row_tracker + " - " + sum);
		row_sum.rowsum[row_tracker] = sum;
		System.out.println("Row Sum for Row - " + row_tracker + " - is now complete");
	}
}