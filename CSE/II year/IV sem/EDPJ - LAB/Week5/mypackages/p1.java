package mypackages;

import java.util.*;

public class p1
{

	public int max(int a, int b, int c)
	{
		if(a>b && a>c)
			return a;
		else if(b>a && b>c)
			return b;
		else
			return c;
	}
	public float max(float a, float b, float c)
	{
		if(a>b && a>c)
			return a;
		else if(b>a && b>c)
			return b;
		else
			return c;
	}
	public int max(int [] x)
	{
		Arrays.sort(x);
		return (x[x.length-1]);
	}
	public int max(int [][] y)
	{
		int [] temp = new int[y.length];
		for(int [] x1:y)
		{	Arrays.sort(x1); }
		for(int i = 0; i < temp.length; i++)
			temp[i] = y[i][y[i].length-1];
		Arrays.sort(temp);
		return(temp[temp.length-1]);
	}
}
