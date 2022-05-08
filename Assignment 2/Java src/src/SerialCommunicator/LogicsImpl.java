package SerialCommunicator;

import java.util.HashMap;
import java.util.Map;



public class LogicsImpl implements Logics {
	private enum Status{
		REFILL("Refill"), 
		REPAIR("Repair"), 
		MAKING("Make"), 
		WAITING("Wait"),
		SELF_TEST("SelfTest"),
		IDLE("Idle");
		
		private String value;
		private Status(String value) {
			this.value = value;
		}
		
		public String getValue() {
			return this.value;
		}
	}

	private static final int BEVERAGE_AMUOUNT = 100;
	private enum Beverage{
		CHOCOLATE(BEVERAGE_AMUOUNT, "Chocolate"), 
		TEA(BEVERAGE_AMUOUNT, "Tea"),
		COFFEE(BEVERAGE_AMUOUNT, "Coffee");
		private int quantity;
		private String beverage;
		
		private Beverage(int quantity, String beverage) {
			// TODO Auto-generated constructor stub
			this.quantity = quantity;
			this.beverage = beverage;
		}
		
		public void MakeBeverage() {
			this.quantity-=1;
		}
		
		public int getBeverageQuantity() {
			return this.quantity;
		}
		
		public void refill() {
			this.quantity = BEVERAGE_AMUOUNT;
		}
		
		public String getBeverageName() {
			return this.beverage;
		}
	}
	
	private static final String REFILL = "Refill";
	private static final String REPAIR = "Repair";
	private int selfTestCount;
	Beverage beverage;
	private String status;
	private String operation;
	
	public LogicsImpl() {
		resetSelfTestCount();
		setStatus("Avvio");
	}

	@Override
	public void RefillOrRepair(String operation) throws Exception {
		// TODO Auto-generated method stub
		this.operation = operation;
		String msg;
		SerialCommChannel channel = new SerialCommChannel("COM3", 9600);
		/* attesa necessaria per fare in modo che Arduino completi il reboot */
		System.out.println("Waiting Arduino for rebooting...");		
		Thread.sleep(4000);
		System.out.println("Ready.");
		
		
		switch (operation) {
		case REFILL:
			this.setStatus(REFILL);
			channel.sendMsg(REFILL);
			msg = channel.receiveMsg();
			System.out.println(msg);
			break;
			
		case REPAIR:
			this.setStatus(REPAIR);
			channel.sendMsg(REPAIR);
			msg = channel.receiveMsg();
			System.out.println(msg);
			break;

		default:
			msg = channel.receiveMsg();
			System.out.println(msg);
			break;
		}
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
		return Beverage.valueOf(beverage).getBeverageQuantity();
	}

	@Override
	public String getStatus() {
		return this.status;
	}

	@Override
	public void makeBevarage(final String beverage) {
		Beverage.valueOf(beverage).MakeBeverage();
	}

	@Override
	public void resetBeverageCount() {
		for(Beverage beverage: Beverage.values()) {
			beverage.refill();
		}
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
