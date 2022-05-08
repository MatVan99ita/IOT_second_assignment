package SerialCommunicator;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;



public class LogicsImpl implements Logics {

	private static final String REFILL = "Refill";
	private static final String REPAIR = "Repair";
	private int selfTestCount;
	private String status;
	private String operation;
	private Map<String, BeverageImpl> beverages;
	
	
	public LogicsImpl() {
		this.beverages = Map.of(
				"Chocolate", new BeverageImpl("Chocolate"),
				"Tea", new BeverageImpl("Tea"),
				"Coffee", new BeverageImpl("Coffee"));
		resetSelfTestCount();
		setStatus("Avvio");
	}
	
	@Override
	public void SendChange(String status) throws Exception {
		SerialCommChannel channel = new SerialCommChannel("COM3", 9600);
		System.out.println("Waiting Arduino for rebooting...");		
		Thread.sleep(4000);
		System.out.println("Ready.");
		channel.sendMsg(REFILL);
	}
	
	@Override
	public int getSelfTestCount() {
		return this.selfTestCount;
	}

	@Override
	public void setSelfTestCount(int selfTestCount) {
		this.selfTestCount = selfTestCount;
	}

	@Override
	public int getSpecifiedBeverageCount(String beverage) {
		return this.beverages.get(beverage).getQuantity();
	}

	@Override
	public String getStatus() {
		return this.status;
	}

	@Override
	public void makeBevarage(final String beverage) {
		this.beverages.get(beverage).makeBeverage();
	}

	@Override
	public void resetBeverageCount() {
		this.beverages.forEach((s, bev) -> bev.refill());
	}

	@Override
	public void resetSelfTestCount() {
		this.selfTestCount = 0;
	}

	@Override
	public void setStatus(String status) {
		this.status = status;
	}

	@Override
	public void servoRotate() throws Exception {
		// TODO Auto-generated method stub
		int angle = 0;
		SerialCommChannel channel = new SerialCommChannel("COM3", 9600);
		/* attesa necessaria per fare in modo che Arduino completi il reboot */
		System.out.println("Waiting Arduino for rebooting...");		
		Thread.sleep(4000);
		System.out.println("Ready.");
		
		//Rotazione singola per sistemare in caso di problemi
		for(int i = 0; i < 180; i++) {
			channel.sendMsg(""+i);
			String msg = channel.receiveMsg();
			System.out.println(msg);		
			Thread.sleep(100);
		}
	}
	
}
