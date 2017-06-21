package app;

import java.awt.*;
import java.awt.event.*;
import java.applet.*;

@SuppressWarnings("serial")
public class MenuDialog extends Applet {
	framy f;
	public void init(){
		f = new framy("fraaam");
		setSize(200,200);
		f.setSize(300,300);
		f.setVisible(true);
	}
	public void start(){
		f.setVisible(true);
	}
	public void stop(){
		f.setVisible(false);
	}
}

@SuppressWarnings("serial")
class framy extends Frame implements ActionListener,ItemListener{
	CheckboxMenuItem c1,c2;
	dial poppy;
	framy me;
	framy(String title){
		super(title);
		me = this;
		poppy = new dial(this,"Message");
		MenuBar mbar = new MenuBar();
		setMenuBar(mbar);
		Menu file = new Menu("File");
		@SuppressWarnings("unused")
		MenuItem item1,item2,item3,item4;
		file.add(item1 = new MenuItem("New"));
		file.add(item2 = new MenuItem("Open"));
		file.add(item3 = new MenuItem("-"));
		file.add(item4 = new MenuItem("Close"));
		mbar.add(file);
		Menu subby = new Menu("Submenu");
		Menu edit = new Menu("Edit");
		c1 = new CheckboxMenuItem("Ed Sheeran");
		c2 = new CheckboxMenuItem("Sunburn");
		subby.add(c1);subby.add(c2);
		edit.add(subby);
		mbar.add(edit);		
		addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent we){
				me.setVisible(false);
			}
		});
		item1.addActionListener(this);
		item2.addActionListener(this);
		item4.addActionListener(this);
		c1.addItemListener(this);
		c2.addItemListener(this);
	}
	@Override
	public void itemStateChanged(ItemEvent arg0) {
		poppy.main.setText("Ed Sheeran - "+c1.getState()+" Sunburn - "+c2.getState());poppy.setVisible(true);	
	}
	@Override
	public void actionPerformed(ActionEvent ae) {
		String x = ae.getActionCommand();
		if(x.equals("New")){poppy.main.setText("New Selected");poppy.setVisible(true);}
		if(x.equals("Open")){poppy.main.setText("open Selected");poppy.setVisible(true);}
		if(x.equals("Close")){this.setVisible(false);}
		
	}
}

@SuppressWarnings("serial")
class dial extends Dialog implements ActionListener {
	Button submit;
	Label main;
	dial(Frame z, String title)
	{
		super(z,title,true);
		setSize(200,200);
		setLayout(new FlowLayout());
		main = new Label("");		
		submit = new Button("Close Me");
		add(main);add(submit);
		submit.addActionListener(this);		
	}
	public void actionPerformed(ActionEvent arg0) {				
		dispose();
	}
}