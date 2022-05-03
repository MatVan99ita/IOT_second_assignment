package GUI;


import javax.swing.*;
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
    public GUI() {
    	/*
    	this.logics = new LogicsImpl(size);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
        this.setSize(50*size, 50*size);
        
        JPanel panel = new JPanel(new GridLayout(size,size));
        this.getContentPane().add(panel);
        
        ActionListener al = e -> {
        	JButton jb = (JButton) e.getSource();
        	this.logics.click();
        	this.updateView();
        	this.counter++;
        	if(logics.isOver()) {
        		this.disableAll();
        	}
        };
                
        for (int i=0; i<size; i++){
            for (int j=0; j<size; j++){
            	var pos = new Pair<>(j,i);
                final JButton jb = new JButton(" ");
                this.cells.put(pos, jb);
                jb.addActionListener(al);
                panel.add(jb);
            }
        }
        this.setVisible(true);
        this.updateView();*/
    }

    /*
	private void disableAll() {
		// TODO Auto-generated method stub
		cells.forEach((p, b) -> {
			b.setEnabled(false);
		});
	}

	private void updateView() {
		// TODO Auto-generated method stub
		if (this.cells.containsKey(this.logics.getLastCreated())) {
			this.cells.get(this.logics.getLastCreated()).setText("" + counter);
		}
	}
    */
}

