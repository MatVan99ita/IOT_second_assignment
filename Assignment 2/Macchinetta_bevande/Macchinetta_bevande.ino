//#include <Servo.h>
//#include <LiquidCrystal.h>
#include <LiquidCrystal_I2C.h> 
#include <Ultrasonic.h>
#include <avr/sleep.h>
#include <avr/power.h>
#include <EnableInterrupt.h>
#include "TimerOne.h"

/*Librerie con strumenti di utilità*/
#include "counter.h"
#include "MsgService.h"
//#include "Timer.h"

/*Librerie per le componenti arduino*/
#include "servo_motor_impl.h"
#include "lm35_impl.h"
//#include "ComponentLib/ServoTimer2.h"

#include "bevandaImpl.h"

int servo_pin = 10;
ServoMotor* pMotor;
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27,20,4); 
int POT_PIN = A1;

int servo_pos = 0;
int servo_delta = 1;

Ultrasonic ultrasonic(/*da aggiungere i pin*/); //(trig, echo)

int zucchero;
long int sleepTimer;
int funzionamento = 0;
BevandaImpl* Chocolate;
BevandaImpl* Tea;
BevandaImpl* Coffee;

void Avvio(){
  lcd.setCursor(2, 1); // Set the cursor on the third column and first row.  
    //lcd.begin(16, 2);
  lcd.print("Benvenuto, seleziona la tua bevanda");
  delay(5000);
  lcd.clear();
  lcd.setCursor(2, 1); // Set the cursor on the third column and first row.
}

void Zucchero(){
  int newValue = analogRead(POT_PIN);
  zucchero = newValue/256 ; //assegno un valore tra 0 e 3
}


void SelezioneBevanda()

    if(bevanda.beverage && bevanda.beverage && bevanda.beverage == 0)
    {
      funzionamento=0;
      serial.println("assistance required");
      loop();
      }

    //abilita bottoni
    
    if(i==1)
    {
      serial.println("Cioccolato");
      }
    else if(i==2)
    {
      serial.println("Tea");
      }
    else if(i==3)
    {
      serial.println("Caffè");
      }


//quando viene premuto make
if(bevanda.beverage==0)
{
  serial.println("bevanda non disponibile");
  SelezioneBevanda();
  }
else{Creazione()}
}


void Creazione(){

  serial.println("Making a ....");
  
  pMotor->on();
  for (int i = 0; i < 181; i++) {
    Serial.println(servo_pos);
    pMotor->setPosition(servo_pos);         
    // delay(15);
    lcd.print(String("Rotazione: ") + servo_pos);
    lcd.setCursor(2, 1);
    servo_pos += servo_delta;
  }
  pMotor->off();
  servo_pos -= servo_delta;
  servo_delta = -servo_delta;
  Serial.println("La bevanda e' pronta"); //deve essere scritta sul display
  delay(1000);  
  /*
  myservo.write(0);
  delay(1500);     //va cambiato rispetto al tempo di creazione
  myservo.write(180);         //ho finito di creare*/
}

void RitiroBevanda(){
serial.ptintln("ritirare la bevanda");
if(ultrasonic.distanceRead()>=40)
{
  serial.println("bevanda ritirata");
  pMotor->setPosition(0);
  }
else if(ultrasonic.distanceRead()<40 && //timeoutCounter>tempotimeout)
  pMotor->setPosition(0);
}

void Assistenza(){
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_enable();
  sleep_mode();
}

void setup() {
  // put your setup code here, to run once:

  Chocolate = new BevandaImpl();
  Tea = new BevandaImpl();
  Coffee = new BevandaImpl();
  Serial.begin(9600);
  pMotor = new ServoMotorImpl(servo_pin);
  servo_pos = 0;
  servo_delta = 1;
  lcd.init();
  lcd.backlight();
  sleepTimer = 10000000;
  Timer1.initialize();
  Avvio();
}

void loop() {
  // put your main code here, to run repeatedly:
  switch(funzionamento){
    case 0://assistenza
      Assistenza();
      break;
    case 1:
      SelezioneBevanda()
      break;
    case 2://sleep
      break;
  };
}
