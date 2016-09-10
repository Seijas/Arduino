#include <SoftwareSerial.h>
 
SoftwareSerial BT(10,11); //10 RX, 11 TX.
 
int green  = 4;
int yellow = 5;
int red    = 6;

char cadena[31]; 
int i = 0;
 
void setup(){
  BT.begin(9600);
  Serial.begin(9600);
  pinMode(green,  OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red,    OUTPUT);
}
 
void loop(){

  if ( BT.available() ) {
    char dato = BT.read();
    cadena[i++] = dato;
 
    if ( dato == '\n' ) {
      Serial.print(cadena);
 
      //GREEN LED
      if ( strstr(cadena,"go") != 0 ) {
        digitalWrite(green,HIGH);
      }
      if ( strstr(cadena,"gf") != 0 ) {
        digitalWrite(green,LOW);
      }
      //YELLOW LED
      if ( strstr(cadena,"yo") != 0 ) {
        digitalWrite(yellow,HIGH);
      }
      if ( strstr(cadena,"yf") != 0 ) {
        digitalWrite(yellow,LOW);
      }
      //RED LED
      if ( strstr(cadena,"ro") != 0 ) {
        digitalWrite(red,HIGH);
      }
      if ( strstr(cadena,"rf") != 0 ) {
        digitalWrite(red,LOW);
      }
      //ALL ON
      if(strstr(cadena,"on")!=0) {
        digitalWrite(green,  HIGH);
        digitalWrite(yellow, HIGH);
        digitalWrite(red,    HIGH);
      }
      //ALL OFF
      if(strstr(cadena,"off")!=0) {
        digitalWrite(green,  LOW);
        digitalWrite(yellow, LOW);
        digitalWrite(red,    LOW);
      }

      clean();
    }
  }
}
 
//Limpia el array
void clean(){
  for (int cl=0; cl<=i; cl++) {
    cadena[cl]=0;
  }
  i=0;
}
