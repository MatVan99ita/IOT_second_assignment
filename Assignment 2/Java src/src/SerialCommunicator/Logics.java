package SerialCommunicator;


public interface Logics {
	

	
	/**
	 * Example made for seding led input to serial port communication
	 * 0 = Refill
	 * 1 = Repair
	 * @throws Exception
	 */
	void RefillOrRepair(int operation) throws Exception;
	
	void servoRotate() throws Exception;

	public int getSelfTestCount();

	public void setSelfTestCount(int selfTestCount);
	
	/**
	 * 0: Cioccolata <br>
	 * 1: Caffè <br>
	 * 2: Tè <br>
	 */
	public int getSpecifiedBeverageCount(String beverage);

	public String getStatus();
	
	public void makeBevarage(String beverage, int quantity);
	
	public void resetBeverageCount();
	
	public void resetSelfTestCount();
	
	/**
	 * Modificato dall'arduino
	 */
	public void setStatus(String status);

}
