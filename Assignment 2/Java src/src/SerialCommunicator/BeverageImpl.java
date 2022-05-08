package SerialCommunicator;

public class BeverageImpl implements Beverage{

	private static final int BEVERAGE_AMUOUNT = 5;
	private String beverageName;
	private int quantity;
	
	public BeverageImpl(String beverageName) {
		super();
		this.beverageName = beverageName;
		this.quantity = BEVERAGE_AMUOUNT;
	}
	

	@Override
	public void makeBeverage() {
		this.quantity = (this.quantity > 0 ? this.quantity-1: 0);
	}

	@Override
	public void refill() {
		this.quantity = BEVERAGE_AMUOUNT;
	}
	
	public int getQuantity() {
		return this.quantity;
	}

	public String getBeverageName() {
		return beverageName;
	}

}
