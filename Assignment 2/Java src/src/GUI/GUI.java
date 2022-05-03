package GUI;


import javax.swing.*;

import SerialCommunicator.Logics;
import SerialCommunicator.Logics;
import SerialCommunicator.LogicsImpl;

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
    
    private final List<JLabel> labels;
    private List<String> beverageList = Arrays.asList("Chocolate", "Cafe", "Tea");
    
    private Logics logics;
    
    public GUI(final int size) {
    	this.logics = new LogicsImpl();
        
    	this.logics = new LogicsImpl();
    	this.setDefaultCloseOperation(EXIT_ON_CLOSE);
    	this.setSize(50*size, 50*size);
    	
    	JPanel panel = new JPanel(new GridLayout(size, size));
    	this.getContentPane().add(panel);
    	
    	JLabel state_content = new JLabel("Stato attuale: " + this.logics.getStatus());
    	JLabel chocoloate_info = new JLabel("Cioccolata: " + this.logics.getSpecifiedBeverageCount(this.beverageList.get(0)));
    	JLabel cafe_info = new JLabel("Caffè: " + this.logics.getSpecifiedBeverageCount(this.beverageList.get(1)));
    	JLabel tea_info = new JLabel("Tè: " + this.logics.getSpecifiedBeverageCount(this.beverageList.get(2)));
    	JLabel self_test_info = new JLabel("Test fatti: " + this.logics.getSelfTestCount());
    	JButton refillButton = new JButton("Refill");
    	JButton repairButton = new JButton("Repair");
    	
    	ActionListener refill = e -> {
    		this.logics.resetBeverageCount();
    		this.updateView();
    	};
		this.labels = Arrays.asList(chocoloate_info, cafe_info, tea_info);
    	
    	ActionListener repair = e -> {
    		state_content.setText("Riparazione...");
    		int quantity = this.logics.getSpecifiedBeverageCount(this.beverageList.get(0));
    		quantity+=-1;
    		this.logics.makeBevarage("Chocolate", quantity);
    		this.updateView();
    	};
    	
    	refillButton.addActionListener(refill);
    	repairButton.addActionListener(repair);
    	
    	panel.add(state_content);
    	panel.add(chocoloate_info);
    	panel.add(cafe_info);
    	panel.add(tea_info);
    	panel.add(self_test_info);
    	panel.add(refillButton);
    	panel.add(repairButton);
    	
    	this.setVisible(true);
    	this.updateView();
    }
    /**
     * Updating the view with the arduino info
     */
    private void updateView() {
    	labels.get(0).setText("Cioccolata: " + this.logics.getSpecifiedBeverageCount(this.beverageList.get(0)));
    	labels.get(1).setText("Caffè: " + this.logics.getSpecifiedBeverageCount(this.beverageList.get(1)));
    	labels.get(2).setText("Tè: " + this.logics.getSpecifiedBeverageCount(this.beverageList.get(2)));
    }
}

