package app;

import java.awt.*;
import java.awt.event.*;
import java.applet.*;

@SuppressWarnings("serial")
public class App_kill extends Applet implements ActionListener{

	TextField input;
	Button submit;
	Label main;
	String msg;
	Frame mgc;
	
	public void init()
	{
		main = new Label("Enter your message - ");
		input = new TextField(15);
		submit = new Button("Initiate the Magic");
		add(main);
		add(input);
		add(submit);
		submit.addActionListener(this);
	}
	public void actionPerformed(ActionEvent ae)
	{
		msg = input.getText();
		showStatus(msg);	
		mgc = new magic(msg);
		mgc.setSize(150,150);
		mgc.setVisible(true);
	}	
}

@SuppressWarnings("serial")
class magic extends Frame
{
	String msg;
	int flag = 0;
	int x,y=75;
	boolean kill;
	
	magic(String x)
	{
		super(x);
		final Frame y = this;
		msg = x;
		addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent we)
			{
				y.setVisible(false);
			}
		});
		addKeyListener(new KeyAdapter(){
			public void keyPressed(KeyEvent ke){
				int key = ke.getKeyCode();
				switch(key){
				case KeyEvent.VK_LEFT : flag = 1;break;
				case KeyEvent.VK_RIGHT : flag = 2;break;
				case KeyEvent.VK_UP : flag = 3;break;
				case KeyEvent.VK_DOWN : flag = 4;break;
				default : flag = 0;break;
				}		
				paint_it();
			}
		});
	}
	
	public void paint_it()
	{
		if(flag == 1){x-=3;if(x<0)x=150;if(y<0)y=150;if(y>150)y=0;}
		if(flag == 2){x+=3;if(x>150)x=0;if(y<0)y=150;if(y>150)y=0;}
		if(flag == 3){y-=3;if(y<0)y=150;if(x<0)x=150;if(x>150)x=0;}
		if(flag == 4){y+=3;if(y>150)y=0;if(x<0)x=150;if(x>150)x=0;}
		repaint();		
	}
	

	public void paint(Graphics g) {
		g.drawString(msg, x, y);				
	}
}
