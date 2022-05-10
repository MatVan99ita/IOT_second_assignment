//#include <Servo.h>
//#include <LiquidCrystal.h>
#include <LiquidCrystal_I2C.h> 
#include <Ultrasonic.h>
#include <avr/sleep.h>
#include <avr/power.h>
#include <EnableInterrupt.h>
#include "TimerOne.h"
#include "ServoTImer2.h"

// TODO       AGGIUNGERE millis() per i vari timer

/*Librerie con strumenti di utilità*/
#include "counter.h"
#include "MsgService.h"
//#include "Timer.h"

/*Librerie per le componenti arduino*/
#include "servo_motor_impl.h"
#include "lm35_impl.h"
//#include "ComponentLib/ServoTimer2.h"

#include "bevandaImpl.h"

#define echoPin 8
#define trigPin 7
#define pirPin 4
#define servoPin 5
#define buttonUp  1                   //////////////////
#define buttonDown  2                 /////////////////
#define buttonMake  0



const int buttonUp = 1                   //////////////////
const int buttonDown = 2                 /////////////////
const int buttonMake = 0
int buttonUpState=0;
int buttonDownState=0;
int servo_pin = 10;
ServoMotor* pMotor;
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27,20,4); 
int POT_PIN = A0;
int TMP_PIN = A1;
int SDA_PIN = A4;
int SCL_PIN = A5;



long int CurrentTime = 0;
long int CurrentTimeCheck = 0;
long int previousTime = 0;
long int CheckTime = 0;
long int Timeout = 0;
long int TimeoutInit = 0;


int servo_pos = 0;
int servo_delta = 1;

Ultrasonic ultrasonic(7,8); //(trig, echo)

int zucchero;
long int sleepTimer 40000000;
volatile int funzionamento;
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

  //abilito i pulsanti
  
  
} */


/*void start_sleep()
{
  if(detectedStatus == false)
      {
        Timer1.detachInterrupt();
        funzionamento = 2;
      }
  else{
        Timer1.detachInterrupt();
        Avvio();
    }
  
  } */


void Zucchero(){
  int newValue = analogRead(POT_PIN);
  zucchero = newValue/256 ; //assegno un valore tra 0 e 3
}


void SelezioneBevanda()

    if(bevanda.beverage && bevanda.beverage && bevanda.beverage == 0)
    {
      funzionamento=0;
      serial.println("assistance required");
      break;
      }

    //abilita bottoni

    buttonUpState = digitalRead(buttonUp);
    buttonDownState = digitalRead(buttonDown);

    if (buttonUpState == HIGH) {
      if(i=3)
      {
        i=1;
      }
      else
      {
      i++;
      }
    }
    if (buttonDownState == HIGH) {
      if(i=1)
      {
        i=3;
      }
      else
      {
        i--;
      }

      
      }
    
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
  buttonUpState = digitalRead(buttonMake);
  
if(bevanda.beverage==0)
{
  serial.println("bevanda non disponibile");
  }
else{
  Creazione();
    }
}


void Creazione(){

  serial.print("Making a ....");
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
  
  pMotor->on();
  for (int i = 0; i < 180; i++) {
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
  Serial.print("La bevanda e' pronta"); //deve essere scritta sul display
  delay(1000);
  TimeoutInit = millis();
  Serial.ptint("ritirare la bevanda");
  RitiroBevanda();
  /*
  myservo.write(0);
  delay(1500);     //va cambiato rispetto al tempo di creazione
  myservo.write(180);         //ho finito di creare*/
}

void RitiroBevanda(){

pMotor->setPosition(0);
TimeOut= millis();
if(ultrasonic.distanceRead()>=40)
{
  serial.println("bevanda ritirata");
  }
else if(ultrasonic.distanceRead()<40)
   {
    if(TimeOut - TimeoutInit >60000)
      {
      Serial.print("Nessuno e' stato rilevato");
      
      }
     else{
        RitiroBevanda();
      }
   }
}

void Sleep(){
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_enable();
  sleep_mode();
}


void Check(){
  int temperatura = analogRead(//pinTemperatura);
  int value_in_mV = 4.8876 * value; 
  double value_in_C = ( value_in_mV - 500) * 0.1;
  pMotor->on();
  for (int i = 0; i < 180; i++) {
    Serial.println(pos);
    pMotor->setPosition(pos);
    // delay(15);            
    pos += servo_delta;
  }
  if(value_in_C < 17 || value_in_C > 24)
  {
    pMotor->setPosition(0);
    pMotor->off();
    lcd.print("Assistance Required");
    Assistenza();
  }
  pMotor->on();
  for (int i = 180; i >= 1; i++)
  {
    pMotor->setPosition(pos);
    pos += servo_delta;
    }
   pMotor->off();
  
  if(value_in_C < 17 || value_in_C > 24)
  {
    lcd.print("Assistance Required");
    Assistenza();
  }
}



void setup() {
  // put your setup code here, to run once:

  pinMode(//PIR_PIN,INPUT);
  Serial.print("Calibrating sensor... ");
  for(int i = 0; i < CALIBRATION_TIME_SEC; i++){
  int detectedStatus = false;

  previousTime = millis();
  CheckTime = millis();
  
 /* int current = digitalRead(PIR_PIN);
  if (current != detectedStatus ){
    detectedStatus = current;
    if (current) {
      Serial.println("detected!");  
    } else {
      Serial.println("no more detected.");
    }
  }
*/
    
  funzionamento=1;
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
  //Timer1.initialize();
  //randomSeed(analogRead(0));
  Avvio();
}

void loop() {
  // put your main code here, to run repeatedly:
  noInterrupts();
  switch(funzionamento){
    case 0://assistenza
      Assistenza();
      break;
    case 1:
      
      CurrentTime = millis();
      CurrentTimeCheck=millis();
      
      if(detectedStatus==true)
      {
        CurrentTime = millis();
      }
      
      if(CurrentTime-PreviousTime>=40000)
      {
        PreviousTime=CurrentTime;
        funzionamento=2;
      }
        
      if(CurrentTimeCheck-CheckTime>=180000)
      {
        CheckTime=CurrentTimeCheck;
        Check();
      }
    SelezioneBevanda();

      break;
    case 2://sleep
    
        sleep();
    
      break;
  };
}
