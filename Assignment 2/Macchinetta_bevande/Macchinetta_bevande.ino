//#include <Servo.h>
//#include <LiquidCrystal.h>
#include <LiquidCrystal_I2C.h> 
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



int servo_pin = 10;
ServoMotor* pMotor;
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27,20,4); 
int POT_PIN = A1;

int servo_pos = 0;
int servo_delta = 1;

int zucchero;
long int sleepTimer;
int funzionamento = 0;


void Avvio(){
  
  //lcd.begin(16, 2);
lcd.print("Benvenuto, seleziona la tua bevanda");
delay(5000);
lcd.clear();

  }

void Zucchero(){
  int newValue = analogRead(POT_PIN);
  zucchero = newValue/256 ; //assegno un valore tra 0 e 3
  }

void Creazione(){
  pMotor->on();
  for (int i = 0; i < 180; i++) {
    Serial.println(servo_pos);
    pMotor->setPosition(servo_pos);         
    // delay(15);
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

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
  pMotor = new ServoMotorImpl(servo_pin);
  servo_pos = 0;
  servo_delta = 1;
sleepTimer = 10000000;
Timer1.initialize();
Avvio();
}

void loop() {
  // put your main code here, to run repeatedly:
  int funzionamento = 1;
  switch(funzionamento){
    case 0://sleep
      set_sleep_mode(SLEEP_MODE_PWR_DOWN);
      sleep_enable();
      sleep_mode();
      break;
    case 1:
      Creazione();
      break;
  };
}
