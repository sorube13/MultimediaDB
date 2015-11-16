package inf224.orube;

import javax.swing.*;
import java.awt.event.*;
import java.awt.*;

public class MyWindow extends JFrame
					  implements ActionListener{
	
	/**
	 * MyWindow will have three buttons b1, b2 and b3
	 * and a text area that is surrounded by a scroll pane
	 */
	private static final long serialVersionUID = 1L;
	JButton b1, b2, b3;
	JTextArea text;
	JScrollPane jp;
	JMenuBar menubar;
	JMenu menu;
	JToolBar toolbar;
	MenuActions a1, a2, a3;
	
	public static void main(String argv[]){
		new MyWindow();
	}
	
	/**
	 * Constructor for MyWindow
	 * The three buttons are added, and each one calls a different action
	 * on the ActionListener
	 */
	public MyWindow(){
		//Buttons
		Panel p = new Panel();
		setLayout(new BorderLayout());
		b1 = new JButton("Add Line 1");
		b2 = new JButton("Add Line 2");
		b3 = new JButton("EXIT");
		p.add(b1);
		p.add(b2);
		p.add(b3);
		this.add(p, BorderLayout.SOUTH);
		//Text Area and Scroll
		text = new JTextArea(10, 50);
		jp = new JScrollPane(text);
		add(jp, BorderLayout.CENTER);
		
		//New Actions for Menu and ToolBar
		a1 = new MenuActions("Add Line 1");
		a2 = new MenuActions("Add Line 2");
		a3 = new MenuActions("Exit");
		
		//Create Menu with actions
		menubar = new JMenuBar();
		menu = new JMenu("Menu");
		menubar.add(menu);
		menu.add(a1);
		menu.add(a2);
		menu.add(a3);
		this.setJMenuBar(menubar);
		
		//Create ToolBar with actions
		toolbar = new JToolBar("ToolBar");
		toolbar.add(a1);
		toolbar.add(a2);
		toolbar.add(a3);
		add(toolbar, BorderLayout.NORTH);
		
		// Add Listeners to buttons
		b1.addActionListener(this);
		b2.addActionListener(this);
		b3.addActionListener(this);
		
		setLocationByPlatform(true);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		pack();
		setVisible(true);
	}
	
	/**
	 * There are three possible actions depending on the button pressed
	 * Button 1: Writes a new line with "Hello Button 1" in the text area
	 * Button 2: Writes a new line with "Hello Button 2" in the text area
	 * Button 3: Exits program.
	 */
	@Override
	public void actionPerformed(ActionEvent e) {
		if(e.getSource()==b1){
			text.append(" \nHELLO BUTTON 1");
		}else if(e.getSource()==b2){
			text.append(" \nHELLO BUTTON 2");
		}else if(e.getSource()==b3){
			System.exit(0);
		}
		
	}
	
	public class MenuActions extends AbstractAction
	  {
		private static final long serialVersionUID = 1L;

		public MenuActions(String name)
	    {
	      super(name);
	    }
	 
	    public void actionPerformed(ActionEvent e)
	    {
	    	if(e.getActionCommand()=="Add Line 1"){
				text.append(" \nHELLO BUTTON 1");
			}else if(e.getActionCommand()=="Add Line 2"){
				text.append(" \nHELLO BUTTON 2");
			}else if(e.getActionCommand()=="Exit"){
				System.exit(0);
			}
	    }
	  }
	

	
	

}
