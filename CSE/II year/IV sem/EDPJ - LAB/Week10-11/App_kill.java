package app;

import java.awt.*;
import java.awt.event.*;
import java.applet.*;

@SuppressWarnings("serial")
public class App_kill extends Applet implements KeyListener,Runnable{
	Thread t = null;
	String msg = "";
	int x=200,y=200;
	boolean stop = false, ltr = true;
	
	public void init()
	{
		setBackground(Color.CYAN);
		setForeground(Color.RED);
		this.setSize(400,400);
		addKeyListener(this);					
	}
	
	public void start()
	{
		dd z = new dd(this,"tree",new Frame());		
		z.setVisible(true);
		t = new Thread(this);
		t.start();
	}
	
	public void run(){
		for(;;){
			try{
				repaint();
				Thread.sleep(65);
				if(stop)
					break;
			}catch(InterruptedException e){}
		}
	}
	
	public void paint(Graphics g) {
		char ch;
		if(!ltr){
			ch = msg.charAt(0);
			msg = msg.substring(1,msg.length());
			msg += ch;
		}
		else{
			ch = msg.charAt(msg.length()-1);
			msg = msg.substring(0,msg.length()-1);
			msg = ch+msg;
		}		
		g.drawString(msg, x, y);				
	}
	
	public void keyPressed(KeyEvent ke) {
		int key = ke.getKeyCode();
		switch(key)
		{
			case KeyEvent.VK_LEFT : ltr = false;showStatus("left");break;
			case KeyEvent.VK_RIGHT : ltr = true;showStatus("right");break;
			case KeyEvent.VK_UP : y-=3;if(y<0)y=400;showStatus("up");break;
			case KeyEvent.VK_DOWN : y+=3;if(y>400)y=0;showStatus("down");break;
			default : stop = true;showStatus(""+ke.getKeyChar());break;		
		}
	}
	public void keyReleased(KeyEvent arg0) {}
	public void keyTyped(KeyEvent arg0) {}	
}

@SuppressWarnings("serial")
class dd extends Dialog implements ActionListener {
	App_kill y;
	TextField input;
	Button submit;
	Label main;
	dd(App_kill x, String title, Frame z)
	{
		super(z,title,true);
		setSize(200,200);
		setLayout(new FlowLayout());
		y=x;
		main = new Label("Enter your message - ");
		input = new TextField(15);
		submit = new Button("Initiate the Magic");
		add(main);add(input);add(submit);
		submit.addActionListener(this);		
	}
	public void actionPerformed(ActionEvent arg0) {
				y.msg=input.getText();
				y.repaint();
				dispose();
	}
}