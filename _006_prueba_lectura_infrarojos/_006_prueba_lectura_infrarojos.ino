/*
int pin_e = 11;
int lec[100];
int i;

void setup() {
  Serial.begin(9600);
  pinMode(pin_e, INPUT);
}

void loop() {
  if(digitalRead(pin_e) == LOW) {
    for(i=0; i<100; i++){
      lec[i] = digitalRead(pin_e);
    }
  }
  
  for(i=0; i<100; i++){
    Serial.print(lec[i]);
  }
  Serial.println("");
}
*/

int pin_e = 11;

int i;

void setup(){
  Serial.begin(9600);
  pinMode(pin_e, INPUT);
}

void loop(){
  if(digitalRead(pin_e) == LOW) {
    for(i=0; i<1000; i++){
      // lec[i] = digitalRead(pin_e);
      Serial.print(digitalRead(pin_e));
    }
    Serial.println(" ");
  }
}
