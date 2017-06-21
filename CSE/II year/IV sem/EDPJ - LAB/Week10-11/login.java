package app;

import java.awt.*;
import java.awt.event.*;
import java.applet.*;

@SuppressWarnings("serial")
public class login extends Applet implements ActionListener{
	
	TextField t1,t2,t3;
	Label l1,l2;
	Button b1;
	
	public void init(){
		setSize(900,80);
		l1 = new Label("Enter UserName");
		l2 = new Label("Enter Password");
		t3 = new TextField(100);
		t1 = new TextField(15);
		t2 = new TextField(15);
		b1 = new Button("Check");
		b1.addActionListener(this);
		t2.setEchoChar('*');
		t3.setEditable(false);
		add(l1);add(t1);add(l2);add(t2);add(b1);add(t3);
	}
	
	public void actionPerformed(ActionEvent ae){
		showStatus("Username - root Password - l33t");
		if(t1.getText().equalsIgnoreCase("root") && t2.getText().equalsIgnoreCase("l33t"))
			t3.setText("Authentication Data Correct");
		else
			t3.setText("Wrong Data Initiating Self Destruct");
	}

}
