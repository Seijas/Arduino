#include <SoftwareSerial.h>

int led = 4;
int est;

SoftwareSerial mySerial(10, 11); //RX, TX

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
  if (mySerial.available()) {
    est = mySerial.read();
    Serial.print(est);
    if(est == 'H'){
      digitalWrite(led, HIGH);
    }
    if(est == 'L'){
      digitalWrite(led, LOW);
    }
  }
  
}
