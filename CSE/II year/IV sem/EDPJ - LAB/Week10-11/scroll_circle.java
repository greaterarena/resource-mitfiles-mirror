package app;

import java.awt.*;
import java.awt.event.*;
import java.applet.*;

@SuppressWarnings("serial")
public class scroll_circle extends Applet implements AdjustmentListener {
	int rad;
	String msg="";
	Scrollbar x1;Panel p1;
	public void init(){
		setSize(600,600);
		setLayout(null);
		x1 = new Scrollbar(Scrollbar.HORIZONTAL,150,1,100,200);
		p1 = new Panel();
		p1.setSize(200, 50);
		p1.setLayout(new GridLayout(1,1,10,10));
		p1.add(x1);
		add(p1);
		x1.addAdjustmentListener(this);			
	}
	public void adjustmentValueChanged(AdjustmentEvent ae)
	{
		rad = x1.getValue();
		showStatus("Move Slider to generate circle");
		msg = "Radius - "+rad+"  Diameter - "+(2*rad)+"  Circumference - "+((int)(2*3.14*rad))+"  Area - "+((int)(3.14*rad*rad));
		repaint();
	}
	public void paint(Graphics g)
	{
		g.drawString(msg, 10, 600);
		g.fillOval(20, 70, 2*rad, 2*rad);
	}
}
