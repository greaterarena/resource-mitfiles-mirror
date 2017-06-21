import java.util.*;

public class mat {
	static private Scanner kill = new Scanner(System.in);
	static int [][] mat1; static int [][] mat2;
	static int [][] mat3;
		public static void main(String args[]){
			nprint("enter the size of the matrix 1 - ");
			mat1 = new int[kill.nextInt()][kill.nextInt()];
			nprint("enter the size of the matrix 2 - ");
			mat2 = new int[kill.nextInt()][kill.nextInt()];
			print("Matrix created begin input now");
			input(mat1);
			input(mat2);
			print(mat1);
			print(mat2);
			if(check(mat1,mat2)){
				dispatch();
			}
			else{
				return;
			}
		}
		
	static public void dispatch(){
		mat3 = new int[mat1.length][mat2[0].length];
		for(int i =0;i<mat3.length;i++)
			new magic(i);
		try{Thread.sleep(2000);}
		catch(Exception e){}
		print(mat3);
	}
		
	static public void print(String x){
		System.out.println(x);
	}
	
	static public void print(int[][] x){
		print("");
		for(int i=0;i<x.length;i++){
			for(int j=0;j<x[i].length;j++){
				nprint(""+x[i][j]+" ");
			}
			print("");
		}
	}
	static public void nprint(String x){
		System.out.print(x);
	}
	static public void input(int[][] x){
		for(int i=0;i<x.length;i++){
			for(int j=0;j<x[i].length;j++){
				nprint("r-"+i+"-c-"+j+" = ");
				x[i][j] = kill.nextInt();
			}
		}
		print("all done");
	}
	
	static public boolean check(int[][] x, int[][] y){
		try{
			if(x[0].length!=y.length)
				throw new mulexp();
			else{
				print("\nMultiplication possible dispatch threads");
				return true;
			}
		}
		catch(mulexp e){
			print("" + e);
			return false;
		}	
	}
}

class mulexp extends Exception{
	
	public String toString(){
		return "\nmultiplication not possible";
	}
}

class magic extends Thread{
	int i,k,jlim,m,j;
	magic(int x){
		super(""+x);
		i = x;
		jlim = mat.mat2[0].length;
		m = mat.mat2.length;
		j = 0;
		start();
	}
	
	public void run(){		
		int temp;
		while(j != jlim){
			temp = 0;
			for(k = 0;k<m;k++)
				temp += mat.mat1[i][k] * mat.mat2[k][j];
			mat.mat3[i][j] = temp;
			j++;
		}
		mat.print("Thread - "+i+" - done");
	}

}