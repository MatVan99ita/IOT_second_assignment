#include <Servo.h>
#include <LiquidCrystal.h>
#include <avr/sleep.h>
#include <avr/power.h>
#include <EnableInterrupt.h>
#include "TimerOne.h"

/*Librerie con strumenti di utilità*/
#include "UtilityLib/counter.h"
#include "UtilityLib/MsgService.h"
#include "UtilityLib/Timer.h"

/*Librerie per le componenti arduino*/
#include "ComponentLib/servo_motor_impl.h"
#include "ComponentLib/lm35_impl.h"
#include "ComponentLib/ServoTimer2.h"

Servo myservo;
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
  myservo.write(0);
  delay(1500)     //va cambiato rispetto al tempo di creazione
  myservo.write(180);         //ho finito di creare
  serial.println("La bevanda e' pronta"); //deve essere scritta sul display
  }

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
sleepTimer = 10000000;
Timer1.initialize();
Avvio();
}

void loop() {
  // put your main code here, to run repeatedly:

switch(fuhnzionamento)
case 0://sleep

set_sleep_mode(SLEEP_MODE_PWR_DOWN);
sleep_enable();
sleep_mode();

}
