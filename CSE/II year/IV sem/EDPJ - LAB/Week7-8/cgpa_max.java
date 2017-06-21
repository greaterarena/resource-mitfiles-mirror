
public class cgpa_max {

	static String [][] student_data =  {{"001","Einstein","1","10"},
										{"002","Newton","1","9.8"},
										{"003","Heisenberg","1","9.9"},
										{"004","Milliken","1","9.7"},
										{"005","Galileo","2","9.7"},
										{"006","Higgs","2","9.99"},
										{"007","Faraday","2","9.8"},
										{"008","Schrodinger","2","9.9"},
										{"009","Euler","3","9.97"},
										{"010","Fermat","3","9.9"},
										{"011","Plank","3","9.7"},
										{"012","Archimedes","3","9.8"},
										{"013","Darwin","4","9.96"},
										{"014","Aristotle","4","9.7"},
										{"015","Curie","4","9.8"},
										{"016","Hawking","4","9.9"},
										{"017","Tesla","5","9.95"},
										{"018","Maxwell","5","9.7"},
										{"019","Kepler","5","9.8"},
										{"020","Bohr","5","9.9"},
									  	};
	static int counter = 0;	
	static int [] row_box = new int[8];	
	static int highest_id_row;	
	static double highest_cgpa = 0.0;
	
	public static void main(String[] args) {

		try
		{
			for(int i = 1; i < 9; i++)
			{
				new ThreadMaxSem(""+i);
				Thread.sleep(50);
			}
			System.out.println("INITIATING FINAL COMPARE");
			
			
			
			for(int i = 0; i < row_box.length; i++)
			{
				if(Double.parseDouble(student_data[row_box[i]][3]) > highest_cgpa)
					{
						highest_id_row = row_box[i];
						highest_cgpa = Double.parseDouble(student_data[row_box[i]][3]);
					}				
			}
			
			System.out.println("Higest Overall CGPA  - " + student_data[highest_id_row][1]);
		}
		catch(InterruptedException e)
		{
			System.out.println("Exception in main thread please check");
		}
	}

}

class ThreadMaxSem extends Thread
{
	int highest_id_row;
	double highest_cgpa;
	String sem_track;
	int sem_flag = 0;
	
	ThreadMaxSem(String name)
	{
		super(name);
		sem_track = name;
		highest_cgpa = 0.0;
		highest_id_row = 0;
		start();
	}
	
	public void run()
	{
		for(int i = 0; i < cgpa_max.student_data.length; i++)
		{
			if(cgpa_max.student_data[i][2].equals(sem_track))
			{
				if(Double.parseDouble(cgpa_max.student_data[i][3]) > highest_cgpa)
				{
					highest_id_row = i;
					highest_cgpa = Double.parseDouble(cgpa_max.student_data[i][3]);
				}
				sem_flag = 1;
			}
		}
		
		if(sem_flag == 1)
		{
			cgpa_max.row_box[cgpa_max.counter] = highest_id_row;;
			cgpa_max.counter++;
			System.out.println("Higest CGPA in Semester - " + sem_track + " - " + cgpa_max.student_data[highest_id_row][1]);
		}
	}
}





