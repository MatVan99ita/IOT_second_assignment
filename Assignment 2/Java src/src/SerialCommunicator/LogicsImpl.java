package SerialCommunicator;

import java.util.HashMap;
import java.util.Map;

public class LogicsImpl implements Logics {
	

	private int selfTestCount;
	
	private Map<String, Integer> beverageCount = new HashMap<>(3);
	private String status;
	private static final int beverageQuantity = 100;
	
	public LogicsImpl() {
		this.beverageCount = Map.of("Chocolate", beverageQuantity, "Cafe", beverageQuantity, "Tea", beverageQuantity); 
		resetSelfTestCount();
		setStatus("Avvio");
	}

	@Override
	public void Blink() throws Exception {
		// TODO Auto-generated method stub
		SerialCommChannel channel = new SerialCommChannel("COM3", 9600);
		/* attesa necessaria per fare in modo che Arduino completi il reboot */
		System.out.println("Waiting Arduino for rebooting...");		
		Thread.sleep(4000);
		System.out.println("Ready.");

		
		while (true){
			channel.sendMsg("1");
			String msg = channel.receiveMsg();
			System.out.println(msg);		
			Thread.sleep(500);
		
			channel.sendMsg("0");
			msg = channel.receiveMsg();
			System.out.println(msg);
			Thread.sleep(500);

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
		return this.beverageCount.get(beverage).intValue();
	}

	@Override
	public String getStatus() {
		return this.status;
	}

	@Override
	public void makeBevarage(final String beverage, final int quantity) {
		Map<String, Integer> tmp = new HashMap<>(this.beverageCount);
		tmp.merge(beverage, -1, Integer::sum);
		this.setBeverageMap(tmp);
	}
	
	private void setBeverageMap(Map<String, Integer> map) {
		this.beverageCount = map;
	}

	@Override
	public void resetBeverageCount() {
		this.setBeverageMap(Map.of("Chocolate", beverageQuantity, "Cafe", beverageQuantity, "Tea", beverageQuantity)); 
	}

	@Override
	public void resetSelfTestCount() {
		this.selfTestCount = 0;
	}

	@Override
	public void setStatus(String status) {
		this.status = status;
	}
	
}
