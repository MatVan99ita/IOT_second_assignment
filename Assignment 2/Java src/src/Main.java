import GUI.GUI;


/**
 * ######### COMPONENTI ######### <br>
 *	3 bottoni: UP, DOWN (<- selezione delle opzioni), MAKE(<- per avviare) <br>
 *	Potenziometro (per lo zucchero) <br>
 *	Display I(^2)C (per simulare lo schermo della macchinetta) <br>
 *	<br>
 *	• Componenti aggiuntivi • <br>
 *	Pir (sensore di movimento) 	-> per vedere se c'è qualcuno in attesa <br>
 *	Sonar  						-> usato assieme al pir per individuare le persone <br>
 *	Servo motore 				-> simulare il make della bevanda <br>
 *	Coso tenperatura analogico	-> per la temperatura della macchina che deve rimanere nel range <br>
 *	
 *	############################## <br>
 *  <br>
 *	######### FUNZIONAMENTO TEORICO ######### <br>
 *	
 *	Ci sono 3 bevande: Caffè, te e cioccolata che possono essere fatti fino a N volte prima di dover essere refillata <br>
 *	
 *	Va in sleep dopo T(io consiglierei dai 5 ai 10 secondi) tempo che non sta facendo nulla <br>
 *	
 *	A livello applicativo(cioè java), bisogna monitorare lo stato della macchina per refillarla quando vuota o "ripararla" quando guasta <br>
 *	
 *	############################## <br>
 *	<br>

 */
public class Main {
	public static void main(String[] args) {

    	
        new GUI(10, args);
        
        //Logics logics = new LogicsImpl();
        //logics.Blink();
    }
}
