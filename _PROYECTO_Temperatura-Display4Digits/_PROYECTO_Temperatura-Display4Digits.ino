// Daniel Seijas Iglesias <seijasdeveloper@gmail.com>

#include <TM1637.h>
#include "DHT.h"

#define CLK 3//pins definitions for TM1637 and can be changed to other ports
#define DIO 2

#define DHTTYPE DHT11   // DHT 11

TM1637 Display1(CLK,DIO);

const int DHTPin = 9;
DHT dht(DHTPin, DHTTYPE);

int8_t  Digits[] = {3,2,1,2} ;

int pulsador = 8;
bool state = true;   // t: temperature  .  f: humidity

int led = 13;

void setup() {
  
  Display1.set();
  Display1.init() ;

  dht.begin();

  pinMode(pulsador, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {

  if ( digitalRead(pulsador) ){
    state = !state;
  }
  
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  
  if (isnan(h) || isnan(t)) {
    return;
  }
  
  if (state) {
    CalculaDigitos(t);
    digitalWrite(led, LOW);
  } else {
    CalculaDigitos(h);
    digitalWrite(led, HIGH);
  }
  
  delay(1000);
}

void CalculaDigitos( int Num) {
  
  int8_t Digit0 = Num %10 ;
  int8_t Digit1 = (Num % 100) / 10 ;
  int8_t Digit2 = (Num % 1000) / 100 ;
  int8_t Digit3 = Num  / 1000  ;

  Digits[3] = Digit0 ;
  Digits[2] = Digit1 ;
  Digits[1] = Digit2 ;
  Digits[0] = Digit3 ;

  Display1.display(Digits);
}
