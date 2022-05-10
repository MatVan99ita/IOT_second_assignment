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

/*Librerie per le componenti arduino*/
#include "servo_motor_impl.h"
//#include "lm35_impl.h"
//#include "ComponentLib/ServoTimer2.h"

#include "bevandaImpl.h"

#define echoPin 8
#define trigPin 7
#define pirPin 4
#define servoPin 5

const int buttonUp = 1;
const int buttonDown = 2;
const int buttonMake = 0;
int buttonUpState=0;
int buttonDownState=0;
int buttonMakeState=0;
int servo_pin = 10;
ServoMotor* pMotor;
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27,20,4); 
int POT_PIN = A0;
int TMP_PIN = A1;
int SDA_PIN = A4;
int SCL_PIN = A5;

const char CIOCCOLATO = 15;
const char TEA = 16;
const char CAFFE = 17;


int current;
int j=0;

long int CurrentTime = 0;
long int CurrentTimeCheck = 0;
long int previousTime = 0;
long int CheckTime = 0;
long int Timeout = 0;
long int TimeoutInit = 0;

int counter = 100;
int tempoCal = 1000;

int servo_pos = 0;
int servo_delta = 1;

Ultrasonic ultrasonic(7,8); //(trig, echo)

int zucchero;
volatile int funzionamento;
BevandaImpl* Chocolate;
BevandaImpl* Tea;
BevandaImpl* Coffee;


void SelezioneBevanda(){


    int newValue = analogRead(POT_PIN);
    zucchero = newValue/256 ; //assegno un valore tra 0 e 3
    buttonUpState = digitalRead(buttonUp);
    buttonDownState = digitalRead(buttonDown);
    buttonMakeState = digitalRead(buttonMake);

    if (buttonUpState == HIGH) {
      if(j=3)
      {
        j=1;
        Serial.print("Cioccolato");
      }
      else
      {
      j++;
      Serial.println(j+14);
      }
    }
    if (buttonDownState == HIGH) 
    {
      if(j=1)
      {
        j=3;
        Serial.print("Caffè");
      }
      else
      {
        j--;
        Serial.println(j+14);
      }
    }
    
    /*if(j==1)
    {
      serial.println("Cioccolato");
      }
    else if(j==2)
    {
      serial.println("Tea");
      }
    else if(j==3)
    {
      serial.println("Caffè");
    }*/


  //quando viene premuto make
  if (buttonMakeState == HIGH)
  {
    if(counter==0)
      {
        Serial.print("bevanda non disponibile");
      }
    else
       {
        Creazione();
       }
    
  }
  


}


void Creazione(){

  Serial.print("Making a ....");
  if(j==1)    {
      Serial.println("Cioccolato");
      }
    else if(j==2)
    {
      Serial.println("Tea");
      }
    else if(j==3)
    {
      Serial.println("Caffè");
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
  Serial.print("ritirare la bevanda");
  RitiroBevanda();
  /*
  myservo.write(0);
  delay(1500);     //va cambiato rispetto al tempo di creazione
  myservo.write(180);         //ho finito di creare*/
}

void RitiroBevanda(){

pMotor->setPosition(0);
pMotor->off();
Timeout= millis();
if(ultrasonic.distanceRead()>=40)
{
  Serial.print("bevanda ritirata");
  }
else if(ultrasonic.distanceRead()<40)
   {
    if(Timeout - TimeoutInit >60000)
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
  int temperatura = analogRead(TMP_PIN);
  int value_in_mV = 4.8876 * temperatura; 
  double value_in_C = ( value_in_mV - 500) * 0.1;
  pMotor->on();
  for (int i = 0; i < 180; i++) {
    Serial.println(servo_pos);
    pMotor->setPosition(servo_pos);
    // delay(15);            
    servo_pos += servo_delta;
  }
  if(value_in_C < 17 || value_in_C > 24)
  {
    pMotor->setPosition(0);
    pMotor->off();
    lcd.print("Assistance Required");
    //Assistenza();
  }
  pMotor->on();
  for (int i = 180; i >= 1; i++)
  {
    pMotor->setPosition(servo_pos);
    servo_pos += servo_delta;
    }
   pMotor->off();
  
  if(value_in_C < 17 || value_in_C > 24)
  {
    lcd.print("Assistance Required");
    //Assistenza();
  }
}



void setup() {
  // put your setup code here, to run once:

  pinMode(pirPin,INPUT);
  Serial.print("Calibrating sensor... ");
  for(int i = 0; i < tempoCal; i++){
                                                                        ///////////////////////////////////////////////////////////////////////////////////////////////
  }
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

  lcd.setCursor(2, 1); // Set the cursor on the third column and first row.  
    //lcd.begin(16, 2);
  lcd.print("Benvenuto, seleziona la tua bevanda");
  delay(5000);
  lcd.clear();
  lcd.setCursor(2, 1); // Set the cursor on the third column and first row.

  pinMode(1, INPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);

 }

void loop() {
  // put your main code here, to run repeatedly:
  switch(funzionamento){
    case 0://assistenza
      //Assistenza();
      break;
    case 1:
      
      CurrentTime = millis();
      CurrentTimeCheck=millis();

      current = digitalRead(pirPin);
      
      if(current==true)
      {
        previousTime = CurrentTime;
      }
      
      if(CurrentTime-previousTime>=40000)
      {
        previousTime=CurrentTime;
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
    
        Sleep();
    
      break;
  };
}
