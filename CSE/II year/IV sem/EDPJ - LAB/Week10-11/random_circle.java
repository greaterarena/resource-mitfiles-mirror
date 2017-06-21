package app;

import java.awt.*;
import java.awt.event.*;
import java.applet.*;

@SuppressWarnings("serial")
public class random_circle extends Applet {
	int rad;
	String msg="";
	public void init(){
		setSize(600,600);
			
		addMouseListener(new MouseAdapter(){
			public void mousePressed(MouseEvent me)
			{
				rad = (int) (Math.random() * 300);
				showStatus("Click anywhere to generate circle");
				msg = "Radius - "+rad+"  Diameter - "+(2*rad)+"  Circumference - "+((int)(2*3.14*rad))+"  Area - "+((int)3.14*rad*rad);
				repaint();
			}
		});		
	}
	public void paint(Graphics g)
	{
		g.drawString(msg, 10, 10);
		g.fillOval(20, 20, 2*rad, 2*rad);
	}
}
