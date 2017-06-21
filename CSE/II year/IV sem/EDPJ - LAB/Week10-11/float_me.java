package app;

import java.awt.*;
import java.awt.event.*;
import java.applet.*;

@SuppressWarnings("serial")
public class float_me extends Applet implements ActionListener{
	
	TextField t1,t2;
	TextArea ta1;
	Label l1,l2;
	Button b1;
	float x1,x2,p1,p2,p3,p4;
	
	public void init(){
		setSize(600,200);
		l1 = new Label("Enter X1");
		l2 = new Label("Enter X2");
		t1 = new TextField(15);
		t2 = new TextField(15);
		b1 = new Button("Calculate");
		b1.addActionListener(this);
		ta1 = new TextArea(5,50);
		add(l1);add(t1);add(l2);add(t2);add(b1);add(ta1);
	}
	
	public void actionPerformed(ActionEvent ae){
		x1 = Float.parseFloat(t1.getText());
		x2 = Float.parseFloat(t2.getText());
		p1 = x1+x2; p2 = x1-x2; p3 = x1*x2; p4 = x1/x2;
		String z = "Sum - " + p1 + "\nDifference - " + p2 + "\nProduct - " + p3 + "\nQuotient - " + p4;
		ta1.setText(z);
	}
}
