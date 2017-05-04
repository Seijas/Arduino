#include <SoftwareSerial.h>

SoftwareSerial BT(10,11); //10 RX, 11 TX.

int m1_up = 3;
int m2_up = 4;
int m1_back = 5;
int m2_back = 6;

char cadena[255]; //Creamos un array de caracteres de 256 cposiciones
int i=0; //Tamaño actual del array
 
void setup(){
  BT.begin(9600);
  Serial.begin(9600);
  pinMode(m1_up, OUTPUT);
  pinMode(m2_up, OUTPUT);
  pinMode(m1_back, OUTPUT);
  pinMode(m1_back, OUTPUT);
}
 
void loop(){
  
  if(BT.available()) {
    char dato = BT.read();
 
    cadena[i++] = dato;
    if(dato == '\n') {
      Serial.print(cadena);
      
      if (strstr(cadena,"a") != 0) {
        digitalWrite(m1_back, LOW);
        digitalWrite(m2_back, LOW);
        digitalWrite(m1_up, HIGH);
        digitalWrite(m2_up, HIGH);
      }
      if (strstr(cadena,"r") != 0) {
        digitalWrite(m1_up, LOW);
        digitalWrite(m2_up, LOW);
        digitalWrite(m1_back, HIGH);
        digitalWrite(m2_back, HIGH);
      } 
      if (strstr(cadena,"s") != 0) {
        digitalWrite(m1_up, LOW);
        digitalWrite(m2_up, LOW);
        digitalWrite(m1_back, LOW);
        digitalWrite(m2_back, LOW);
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
