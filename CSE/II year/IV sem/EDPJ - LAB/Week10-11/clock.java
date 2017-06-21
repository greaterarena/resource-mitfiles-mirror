package app;

import java.awt.*;
import java.awt.event.*;
import java.applet.*;

@SuppressWarnings("serial")
public class clock extends Applet implements ActionListener {
	int and,rad=400;
	int second,minute,hour,secang,minang,hang;
	TextField t1,t2,t3;Panel p1;Button b1;
	public void init(){
		setSize(600,600);
		setLayout(null);
		t1 = new TextField(2);
		t2 = new TextField(2);
		t3 = new TextField(2);
		b1 = new Button("Set Time");
		p1 = new Panel();
		p1.setSize(200, 50);
		p1.setLayout(new GridLayout(1,4,10,10));
		p1.add(t3);p1.add(t2);p1.add(t1);p1.add(b1);
		add(p1);
		b1.addActionListener(this);			
	}
	public void actionPerformed(ActionEvent ae)
	{
		second = Integer.parseInt(t1.getText());
		minute = Integer.parseInt(t2.getText());
		hour = Integer.parseInt(t3.getText());
		showStatus("red - seconds, blue - minutes, orange - hour");
		repaint();
	}
	
	public void translate(){
		secang = (90 - (second*6))-1;
		minang = (90 - (minute*6))-1;
		hang = (90 - (hour*30))-1;
	}
	
	public void paint(Graphics g)
	{
		g.drawOval(60,70,rad,rad);
		translate();
		g.setColor(Color.red);
		g.fillArc(60, 70, rad, rad,secang,2);
		g.setColor(Color.blue);
		g.fillArc(60, 70, rad, rad,minang,2);
		g.setColor(Color.ORANGE);
		g.fillArc(60, 70, rad, rad,hang,2);		
	}
}