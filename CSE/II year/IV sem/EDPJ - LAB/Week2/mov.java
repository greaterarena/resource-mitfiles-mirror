import java.util.*;

class mov
{
	public static void main(String args[])
	{
		Movie m1 = new Movie();
		Movie m2 = new Movie();
		getInput(m1);
		getInput(m2);
		m1.display();
		m2.display();
		Movie.comp(m1,m2);
	}
	static void getInput(Movie x)
	{
		Scanner in = new Scanner(System.in);
		String title, nod;
		int year;
		System.out.print("Enter Title - ");
		title = in.nextLine();
		x.setTitle(title);	
		System.out.print("Enter Year - ");
		year = in.nextInt();
		nod = in.nextLine();
		x.setYear(year);	
		System.out.print("Enter Director's Name - ");
		nod = in.nextLine();
		x.setDirector(nod);	
	}
}

class Movie
{
	private String title,nod;
	private int year;
	Movie()
	{
		title = "o";
		nod = "o";
		year = 1999;
	}
	void setTitle(String x)
	{	
		title = x;
	}
	void setYear(int x)
	{	
		year = x;
	}
	void setDirector(String x)
	{	
		nod = x;
	}
	void display()
	{	
		System.out.println("Movie information\nTitle - "+title+"\nYear - "+year+"\nDirector - "+nod);
	}
	static void comp(Movie a, Movie b)
	{
		System.out.println("Comparing Movies");		
		if(a.year==b.year)
			System.out.println("Released same year");
		else
			System.out.println("Did not release the same year");
		if(a.nod.equals(b.nod))
			System.out.println("Have Same directors");
		else
			System.out.println("Directors different");
	}	
}
