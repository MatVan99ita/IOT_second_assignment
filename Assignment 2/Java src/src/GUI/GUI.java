package GUI;


import javax.swing.*;

import SerialCommunicator.Logics;
import SerialCommunicator.LogicsImpl;
import SerialCommunicator.SerialCommChannel;

import java.util.*;
import java.util.List;
import java.awt.*;
import java.awt.event.ActionListener;

/**
 * ######### DETTAGLI ######### <br>
 *	LA GUI DELL'APPLICATIVO DEVE MOSTRARE <br>
 *	~ Stato della macchina: Idle, Lavoro o Assistenza <br>
 *	~ Zona informativa <br>
 *		• Il numero di bevande ancora disponibili <br>
 *		• Il numero di self test fatti dall'accensione <br>
 *	
 *	~ Un bottone per il Refill <br>
 *	~ Un bottone per il Recover della machina(per quando la temperatira non è apposto o il servo motore non va) <br>
 *	
 *	############################## <br>
 */
public class GUI extends JFrame {
    
    private static final long serialVersionUID = -6218820567019985015L;
    /*
    private final Map<Pair<Integer, Integer>, JButton> cells = new HashMap();
    private int counter = 0;
    private Logics logics;
    */
    
    //private final List<JLabel> labels;
    private static final int WIDTH = 400;
    private static final int HEIGHT = 300;
    private static final String CHOCOLATE = "Chocolate";
    private static final String TEA = "Tea";
    private static final String COFFEE = "Coffee";
    
    private DefaultListModel<String> defaultListModel;
    private Logics logics;
    JButton refillButton;
    JButton repairButton;
    JLabel state_content;
    SerialCommChannel channel;
    
    
    
    public GUI(final int size, final String args){
    	try {
			this.logics = new LogicsImpl(args);
		} catch (Exception e3) {
			// TODO Auto-generated catch block
			e3.printStackTrace();
		}
    	this.setDefaultCloseOperation(EXIT_ON_CLOSE);
    	this.setSize(WIDTH, HEIGHT);
    	
    	JPanel panel = new JPanel();
    	this.getContentPane().add(panel);
    	
    	//Creating navigable info panel
    	defaultListModel = new DefaultListModel< >();
    	defaultListModel.addElement("INFO VARIE:");
    	defaultListModel.addElement("");
    	defaultListModel.addElement("");
    	defaultListModel.addElement("");
    	defaultListModel.addElement("");
        JList<String> jList = new JList< >(defaultListModel);
        jList.setBounds(100,100,75,75);
        this.add(jList);
    	
        //Creating assistant bottom menu
    	JPanel assistantPanel = new JPanel(); // the panel is not visible in output
    	this.state_content = new JLabel("");
    	this.refillButton = new JButton("Refill");
    	this.repairButton = new JButton("Repair");
    	//this.refillButton.setEnabled(false);
    	//this.repairButton.setEnabled(false);
        assistantPanel.add(state_content); // Components Added using Flow Layout
        assistantPanel.add(this.refillButton);
        assistantPanel.add(this.repairButton);

        this.getContentPane().add(BorderLayout.SOUTH, assistantPanel);
        //this.getContentPane().add(BorderLayout.NORTH, infoArea);
    	
    	
    	ActionListener refill = e -> {
    		this.logics.resetBeverageCount();
    		try {
				this.updateView();
			} catch (Exception e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
    	};
		//this.labels = Arrays.asList(chocoloate_info, cafe_info, tea_info);
    	
    	ActionListener repair = e -> {
    		state_content.setText("Riparazione...");
    		int quantity;
			try {
				quantity = this.logics.getSpecifiedBeverageCount(this.CHOCOLATE);
				quantity+=-1;
			} catch (Exception e2) {
				// TODO Auto-generated catch block
				e2.printStackTrace();
			}
    		this.logics.makeBevarage(CHOCOLATE);
    		try {
				this.updateView();
			} catch (Exception e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
    	};
    	
    	refillButton.addActionListener(refill);
    	repairButton.addActionListener(repair);
    	this.setVisible(true);
    	try {
			this.updateView();
		} catch (Exception e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
    	
    	
    }
    /**
     * Updating the view with the arduino info
     * @throws Exception 
     */
    private void updateView() throws Exception {
    	this.state_content.setText("Stato attuale: " + this.logics.getStatus());
    	defaultListModel.set(1, "Cioccolata: " + this.logics.getSpecifiedBeverageCount(GUI.CHOCOLATE));
    	defaultListModel.set(2, "Caffè: " + this.logics.getSpecifiedBeverageCount(GUI.COFFEE));
    	defaultListModel.set(3, "Tè: " + this.logics.getSpecifiedBeverageCount(GUI.TEA));
    	defaultListModel.set(4, "Test fatti: " + this.logics.getSelfTestCount());

    	if(this.logics.getStatus() == "Assistant") {
    		this.AssistantButtonActivation();
    	}
    
    }
    
    private void AssistantButtonActivation() {
    	this.refillButton.setEnabled(true);
    	this.repairButton.setEnabled(true);
    }
}

