import mypackages.*;

class mainy
{
	public static void main(String args[])
		{
			p1 p1_obj = new p1();
			int [] x = {1,8,4,2,5,7,99,6,2,1,45,455,9};
			int [][] y = {{1,8,4},{2,5,7},{99,6,2},{1,45,785}};	
			System.out.println("\n"+p1_obj.max(5,6,9)+"\n"+p1_obj.max(5.6f,7.8f,8.9f)+"\n"+p1_obj.max(x)+"\n"+p1_obj.max(y));	
		}
}