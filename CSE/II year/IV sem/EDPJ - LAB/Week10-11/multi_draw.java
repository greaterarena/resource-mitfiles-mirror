package app;

import java.awt.*;
import java.awt.event.*;
import java.applet.*;

@SuppressWarnings("serial")
public class multi_draw extends Applet implements ItemListener {
	String msg="";
	Choice c1;
	int type=1,x1,y1,x2,y2,width,height,flag,temp,x3,x4,y3,y4,count=1;
	int [] xarr; int [] yarr;
	public void init(){
		setSize(600,600);
		setLayout(null);
		c1 = new Choice();
		c1.add("Oval");
		c1.add("Arc");
		c1.add("Line");
		c1.add("Rectangle");
		c1.add("Polygon");
		c1.addItemListener(this);
		c1.setBounds(10, 10, 200, 20);
		add(c1);
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
				flag = 0;
				draw_me();
				}
				else
				{ showStatus("Invalid Drag");}
			}
			public void mouseClicked(MouseEvent me){
				if(type==5){
					switch(count){
					case 1:x1 = me.getX(); y1 = me.getY();showStatus("point - "+count);break;
					case 2:x2 = me.getX(); y2 = me.getY();showStatus("point - "+count);break;
					case 3:x3 = me.getX(); y3 = me.getY();showStatus("point - "+count);break;
					case 4:x4 = me.getX(); y4 = me.getY();showStatus("point - "+count);break;
					}
					count++;
					if(count==5){
						count = 1;
						int x [] = {x1,x2,x3,x4};
						 int y [] = {y1,y2,y3,y4};
						 xarr = x; yarr=y;
						 draw_me();
					}
				}
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
	public void itemStateChanged(ItemEvent ie)
	{
		String c = c1.getSelectedItem();
		switch(c){
		case "Oval":type=1;break;
		case "Arc":type=2;break;
		case "Line":type=3;;break;
		case "Rectangle":type=4;break;
		case "Polygon":type=5;break;		
		}
		showStatus("For Polygon only 4 points allowed");
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
	
	public void draw_me(){
		if(type == 4 || type == 1 || type == 3){
			normalize();
			width = x2-x1;
			height = y2-y1;
			repaint();
		}
		if(type == 2){
			normalize();
			height = y2-y1;
			int factor = height/360;
			if(height>360)
				height = (height/factor)-1;
			repaint();
		}
		if(type==5)
			repaint();
	}
	public void paint(Graphics g)
	{
		g.drawString(msg, 10, 600);
		switch(type){
		case 4: g.fillRoundRect(x1, y1, width, height, 15, 15);break;
		case 1: g.fillOval(x1, y1, width, height);break;
		case 3: g.drawLine(x1, y1, x2, y2);break;
		case 2: g.fillArc(60, 70, 200, 200,0,height);break;
		case 5: g.drawPolygon(xarr,yarr,4);break;
		}
		
	}
}

