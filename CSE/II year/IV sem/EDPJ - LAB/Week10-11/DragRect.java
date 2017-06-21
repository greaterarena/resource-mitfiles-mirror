package app;

import java.awt.*;
import java.awt.event.*;
import java.applet.*;

@SuppressWarnings("serial")
public class DragRect extends Applet {
	int flag,x1,y1,x2,y2,width,height,temp;
	public void init(){
		setSize(600,600);
		addMouseListener(new MouseAdapter(){
			public void mousePressed(MouseEvent me)
			{
				x1 = me.getX();
				y1 = me.getY();
				showStatus("Mouse pressed - " + x1 + " " + y1);
			}
			public void mouseReleased(MouseEvent me)
			{
				if(flag == 1){
				x2 = me.getX();
				y2 = me.getY();		
				showStatus("Mouse Released - " +x2+ " " +y2);
				flag = 0;
				draw_my_rect();
				}
				else
				{ showStatus("Invalid Drag");}
			}
		});		
		addMouseMotionListener(new MouseMotionAdapter(){
			public void mouseDragged(MouseEvent me)
			{
				flag = 1;
				showStatus("Mouse dragged - " + me.getX() + " " +me.getY());
			}
		});
	}
	
	public void draw_my_rect(){
		normalize();
		width = x2-x1;
		height = y2-y1;
		showStatus("Area of drawn Rectangle = "+(width * height));
		repaint();
	}
	
	public void normalize(){
		if (x1>x2){
			temp = x1;
			x1 = x2;
			x2 = temp;	
		}
		if (y1>y2){
			temp = y1;
			y1 = y2;
			y2 = temp;	
		}
	}
	
	public void paint(Graphics g)
	{
		g.fillRect(x1, y1, width, height);
	}
	
}