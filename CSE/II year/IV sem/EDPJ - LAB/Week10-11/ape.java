package app;

import java.applet.*;
import java.awt.*;
import java.awt.event.*;
import java.net.*;

@SuppressWarnings("serial")
public class ape extends Applet implements ActionListener {
	String msg = "";
	Button go_biodata;
    public void init() {
    	go_biodata = new Button("Redirect to Biodata");
    	add(go_biodata);
    	setBackground(Color.gray);
    	go_biodata.addActionListener(this);       
    }
    
    public void actionPerformed(ActionEvent ae)
    {
    	try {
            showStatus(ae.getActionCommand());  
     	   getAppletContext().showDocument(new URL("http://google.com"), "_blank");
        }
        catch (MalformedURLException ex) {
             System.out.println(ex.getMessage());
        }
    	try {Thread.sleep(700);} catch (InterruptedException e) {}
    	showStatus("click the button");
    }

}