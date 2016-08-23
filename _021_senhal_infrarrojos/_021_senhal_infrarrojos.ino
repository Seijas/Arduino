int pin_e = 11;
int pin_l = 10;

int i;
int a;
int e;

int readed;

void setup(){
  Serial.begin(9600);
  pinMode(pin_e, INPUT);
  pinMode(pin_l, OUTPUT);
  digitalWrite(pin_l, LOW);
  e = 0;
}

void loop(){
  if(digitalRead(pin_e) == LOW) {
    a = 0;
    for(i=0; i<50; i++){
      readed = digitalRead(pin_e);
      Serial.print(readed);
      if(readed == HIGH){
        a = 1;
      }
    }
    Serial.println("");
    if (a == 0){
      if (e == 0) {
        digitalWrite(pin_l, HIGH);
        e = 1;
      }
      if (e == 1) {
        digitalWrite(pin_l, LOW);
        e = 0;
      }
    }
  }
}
