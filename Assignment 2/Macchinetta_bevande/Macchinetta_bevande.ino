#include <Servo.h>
#include <avr/sleep.h>
#include <avr/power.h>
#include <EnableInterrupt.h>
#include "TimerOne.h"

Servo myservo;
int zucchero;
long int sleepTimer;

void Avvio(){
  Serial.println("Qui scrivo il messaggio di avvio (va messo su display)");
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
}

void loop() {
  // put your main code here, to run repeatedly:

switch(fuhnzionamento)
case 0://sleep

set_sleep_mode(SLEEP_MODE_PWR_DOWN);
sleep_enable();
sleep_mode();

}
