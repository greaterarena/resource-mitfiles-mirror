package app;

import java.awt.*;
import java.awt.event.*;
import java.applet.*;

@SuppressWarnings("serial")
public class mult extends Applet implements ActionListener{
	
	TextField input;
	Button submit;
	Label main;
	Frame mgc;
	String msg;
	boolean check = false;
	public void init()
	{
		main = new Label("Enter a Number - ");
		input = new TextField(15);
		submit = new Button("Generate Tables");
		add(main);
		add(input);
		add(submit);
		submit.addActionListener(this);
	}
	
	public void actionPerformed(ActionEvent ae)
	{
		msg = input.getText();
		showStatus("Generating Tables for - "+msg);	
		try{int q = Integer.parseInt(msg);
			mgc = new mxt(q);
			mgc.setSize(200,200);
			mgc.setVisible(true);}
		catch(NumberFormatException e){showStatus("Enter a Number only");}
	}	
}

@SuppressWarnings("serial")
class mxt extends Frame{
	int num;
	String gen = "";
	final Frame y;
	mxt(int x)
	{
		super(""+x);
		num = x;
		y = this;
		addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent we)
			{
				y.setVisible(false);
			}
		});
		for(int i=1;i<=10;i++){
			gen += ""+num+" x "+i+" = "+(num*i)+"\n";
		}
		TextArea Text = new TextArea(gen,10,10);
		add(Text);
	}
}