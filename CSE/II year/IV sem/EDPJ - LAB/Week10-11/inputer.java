/* PLEASE NOTE MAAM I HAVE USED SLEEP(5000) IN MAIN CODE 
 * SO THE CODE WILL TAKE 5 SECONDS TO GENERATE FINAL OUTPUT
 */

package app;

import java.applet.*;
import java.awt.*;
import java.awt.event.*;

@SuppressWarnings("serial")
public class inputer extends Applet implements ActionListener{
	int [][] matrix;
	int [] row_sum; int row_c,col_c;
	TextField x,y,inp;
	TextArea result;
	Label x1,y1,input1;
	Button begin;
	
	public void init()
	{
		x = new TextField(10);
		y = new TextField(10);
	  inp = new TextField(100);
	   x1 = new Label("Enter no of rows");
	   y1 = new Label("Enter no of columns");
	   input1 = new Label("Enter values for matrix in a space seperated fashion row wise");
	   begin = new Button("Calculate");
	   result = new TextArea(20,50);
	   add(x1); add(x);
	   add(y1); add(y);
	   add(input1); add(inp);
	   add(begin);
	   add(result);
	   begin.addActionListener(this);
	}
	
	public void actionPerformed(ActionEvent ae)
	{
		row_c = Integer.parseInt(x.getText());
		col_c = Integer.parseInt(x.getText());
		matrix = new int [row_c][col_c];
		String z = inp.getText();
		String [] spl = z.split(" "); int i,j; int q=0;
		for(i=0; i<row_c; i++)
			for(j=0; j<col_c; j++)
				matrix [i][j] = Integer.parseInt(spl[q++]);
		row_sum = new int [row_c];
		@SuppressWarnings("unused")
		calc z1 = new calc(this);
	}
}

class calc extends Thread
{
	inputer x;
	calc(inputer z)
	{
		x = z;
		this.start();
	}
	
	public void run()
	{
		for(int i = 0; i < x.row_c; i++)
			new row_calc(i,x);
		try
		{
			Thread.sleep(5000);
		}
		catch(InterruptedException e){}		
		x.result.append("Final Sum \n");		
		int temp = 0;
		for(int i = 0; i < x.row_c; i++)
			temp += x.row_sum[i];
		x.result.append("Total Sum = " + temp);		
	}	
}

class row_calc extends Thread
{
	int a; inputer y;
	row_calc(int x, inputer z)
	{
		a = x;	y = z;	this.start();
	}
	public void run()
	{
		int temp = 0;
		for(int i = 0; i<y.row_c; i++)
			temp += y.matrix[a][i];
		y.row_sum[a] = temp;
		y.result.append("Row - " + a + "done \n");
	}	
}