package app;

import java.awt.*;
import java.awt.event.*;
import java.applet.*;

@SuppressWarnings("serial")
public class calculator extends Applet implements ActionListener {
	Button [] b;
	TextField res;
	Panel p1,p2;
	float x1, x2, ans;
	int flag = 0,opflag = 0,printflag=0;
	
	public void init(){
		setSize(400,400);
		setLayout(new GridLayout(3,1,10,10));
		res = new TextField(50);
		add(res);
		p1 = new Panel();
		p2 = new Panel();
		p1.setLayout(new GridLayout(2,4,10,10));
		p2.setLayout(new GridLayout(2,4,10,10));
		b = new Button[16];
		for(int i = 0; i<=9; i++)b[i] = new Button(""+i);
		b[10] = new Button("+");
		b[11] = new Button("-");
		b[12] = new Button("*");
		b[13] = new Button("/");
		b[14] = new Button("=");
		b[15] = new Button(".");
		for(int i = 0; i<16;i++)b[i].addActionListener(this);
		p1.add(b[1]);p1.add(b[2]);p1.add(b[3]);p1.add(b[10]);p1.add(b[4]);p1.add(b[5]);p1.add(b[6]);p1.add(b[11]);
		p2.add(b[7]);p2.add(b[8]);p2.add(b[9]);p2.add(b[12]);p2.add(b[0]);p2.add(b[15]);p2.add(b[14]);p2.add(b[13]);
		add(p1);add(p2);		
	}
	
	public void print(String z){
		if(printflag==1){
			printflag = 0;
			res.setText("");
		}
		else
			res.setText(res.getText()+z);
	}
	
	public void getval(){
		x1 = Float.parseFloat(res.getText());	
		res.setText("");
	}
	
	public void getres(){
		flag = 0;
		x2 = Float.parseFloat(res.getText());
		res.setText("");
		switch(opflag){
		case 1: ans = x1+x2;break;
		case 2: ans = x1-x2;break;
		case 3: ans = x1*x2;break;
		case 4: ans = x1/x2;break;
		}
		res.setText(""+ans);
		opflag = 0;
		printflag=1;
	}
	
	public void actionPerformed(ActionEvent ae) {
		String x = ae.getActionCommand();
		if(x.equals("+")||x.equals("-")||x.equals("*")||x.equals("/")||x.equals("=")){}
		else
			print(x);
		switch(x){
		case "+": if(printflag==1)print("w");else{if(flag==1)getres();else{getval();flag = 1;opflag=1;}}break;
		case "-": if(printflag==1)print("w");else{if(flag==1)getres();else{getval();flag = 1;opflag=2;}}break;
		case "*": if(printflag==1)print("w");else{if(flag==1)getres();else{getval();flag = 1;opflag=3;}}break;
		case "/": if(printflag==1)print("w");else{if(flag==1)getres();else{getval();flag = 1;opflag=4;}}break;
		case "=": getres();break;
		}
	}
	
	
}
