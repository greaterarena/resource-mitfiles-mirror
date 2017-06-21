package app;

import java.awt.*;
import java.awt.event.*;
import java.applet.*;


@SuppressWarnings("serial")
public class Multi_control extends Applet implements ActionListener, ItemListener, AdjustmentListener{
	
	Button check,lists,rest;
	Checkbox [] ck;
	CheckboxGroup cgk;
	Panel p1,p2,p3,p4,p5,p6,p7,p8;
	Choice c1;
	List c2;
	TextField t1,t2,t3,t4;
	TextArea ta1;
	Scrollbar s1,s2;
	
	public void init(){
		
		setLayout(new GridLayout(2,2));
		genpanel1();
		genpanel2();
		genpanel3();
		genpanel4();
		add(p1);	
		add(p2);
		add(p3);
		add(p4);
		p2.setVisible(false);		
		p3.setVisible(false);
		p4.setVisible(false);
		this.setSize(1000, 650);
	}
	
	public void genpanel1()
	{
		check = new Button("Check/Radio Boxes");
		lists = new Button("Lists");
		rest  = new Button("TextControls and Scroll");
		p1 = new Panel();
		p1.setLayout(new GridLayout(1,3,10,10));
		p1.add(check);
		p1.add(lists);
		p1.add(rest);
		check.addActionListener(this);
		lists.addActionListener(this);
		rest.addActionListener(this);	
	}
	
	public void genpanel2()
	{
		p2 = new Panel();
		p2.setLayout(new GridLayout(1,2,10,10));
		p5 = new Panel();
		p5.setLayout(new GridLayout(3,1,10,10));
		p2.add(p5);
		ck = new Checkbox[5];
		cgk = new CheckboxGroup();
		for(int i = 0; i<5; i++)
		{
			if(i>1)
				ck[i] = new Checkbox("CheckBox - "+i,cgk,true);
			else
				ck[i] = new Checkbox("CheckBox - "+i);
			ck[i].addItemListener(this);
		}
			
		t1 = new TextField(40);
		t2 = new TextField(40);
		t1.setEditable(false);
		t2.setEditable(false);
		p5.add(ck[0]);
		p5.add(ck[1]);
		p5.add(t1);
		p6 = new Panel();
		p6.setLayout(new GridLayout(4,1,10,10));
		p6.add(ck[2]);
		p6.add(ck[3]);
		p6.add(ck[4]);
		p6.add(t2);
		p2.add(p6);		
	}
	
	public void genpanel3()
	{
		p3 = new Panel();
		p3.setLayout(new GridLayout(1,2,10,10));
		p7 = new Panel();
		p7.setLayout(new GridLayout(2,1,10,10));
		p8 = new Panel();
		p8.setLayout(new GridLayout(2,1,10,10));
		c1 = new Choice();
		c1.add("Choice 1");
		c1.add("Choice 2");
		c1.add("Choice 3");
		t3 = new TextField();
		t3.setEditable(false);
		c1.addItemListener(this);
		p7.add(c1);
		p7.add(t3);
		p3.add(p7);
		c2 = new List();
		c2.add("Choice 1");
		c2.add("Choice 2");
		c2.add("Choice 3");
		c2.addItemListener(this);
		t4 = new TextField();
		t4.setEditable(false);
		p8.add(c2);
		p8.add(t4);
		p3.add(p8);
	}
	
	public void genpanel4()
	{
		p4 = new Panel();
		p4.setLayout(new GridLayout(1,3,10,10));
		s1 = new Scrollbar(Scrollbar.VERTICAL,0,10,0,1024);
		s2 = new Scrollbar(Scrollbar.HORIZONTAL,0,10,0,1024);
		p4.add(s1);		
		p4.add(s2);
		s1.addAdjustmentListener(this);
		s2.addAdjustmentListener(this);
		ta1 = new TextArea(5,50);
		ta1.setEditable(false);
		p4.add(ta1);
	}
	
	public void adjustmentValueChanged(AdjustmentEvent ae)
	{
		String t = "Scrollbar Values\n\nVertical Value - "+s1.getValue();
		t += "\n\nHorizontal Value - "+s2.getValue();
		ta1.setText(t);
	}
	
	public void itemStateChanged(ItemEvent ie){
		boolean x = ck[0].getState();
		boolean y = ck[1].getState();
		String z = "Checkbox 1 - "+x+" Checkbox 2 - "+y;
		t1.setText(z);
		String w = "Selected - "+cgk.getSelectedCheckbox().getLabel();
		t2.setText(w);
		String u = "Selected - "+c1.getSelectedItem();
		t3.setText(u);
		String v = "Selected - "+c2.getSelectedItem();
		t4.setText(v);
	}
		
	public void actionPerformed(ActionEvent ae){
		showStatus(ae.getActionCommand());
		if(ae.getActionCommand()=="Check/Radio Boxes"){
			//this.add(p2);
			p2.setVisible(true);
			p3.setVisible(false);
			p4.setVisible(false);
		}
		if(ae.getActionCommand()=="Lists"){
			p3.setVisible(true);
			p2.setVisible(false);
			p4.setVisible(false);
		}	
		if(ae.getActionCommand()=="TextControls and Scroll"){
			p3.setVisible(false);
			p2.setVisible(false);
			p4.setVisible(true);
		}	
	}	
}