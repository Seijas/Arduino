#include <SoftwareSerial.h>

int pulsador = 4;

SoftwareSerial mySerial(10, 11); //RX, TX

void setup() {
  mySerial.begin(9600);
  pinMode(pulsador, INPUT);
}

void loop() {
  if (digitalRead(pulsador) == HIGH) {
    mySerial.write('H');
  } else {
    mySerial.write('L');
  }
}
