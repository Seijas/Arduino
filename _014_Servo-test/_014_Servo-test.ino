#include <Servo.h>
 
Servo miServo;
int pin = 9;
int angulo = 90;

int posicion = 0;
int result;
int flag = 1;

void setup(){
  Serial.begin(9600);
  miServo.attach(pin);
}
 
void loop(){
  unsigned char comando = 0;

  if(Serial.available()){
    comando = Serial.read();
    if(comando == 'a') {
      angulo+=10;
    } else if(comando == 'z') {
      angulo-=10;
    }
    angulo = constrain(angulo, 0, 180);
    
    miServo.write(angulo);
    Serial.print("Angulo: ");
    Serial.println(angulo);
  }
  
  delay(100);
}
