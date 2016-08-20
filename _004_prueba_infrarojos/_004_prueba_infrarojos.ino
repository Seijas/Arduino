int pin_e = 11;
int pin_s = 12;

int a;

void setup(){
  Serial.begin(9600);
  pinMode(pin_e, INPUT);
  pinMode(pin_s, OUTPUT);

  digitalWrite(pin_s, HIGH);
  Serial.print(digitalRead(pin_e));

  delay(10);

  digitalWrite(pin_s, LOW);
  Serial.print(digitalRead(pin_e));

  delay(10);

  digitalWrite(pin_s, HIGH);
  Serial.print(digitalRead(pin_e));

  delay(10);

  digitalWrite(pin_s, HIGH);
  Serial.print(digitalRead(pin_e));

  delay(10);
}

void loop(){

  digitalWrite(pin_s, HIGH);
  Serial.print("Alto: ");

  for (a = 0; a < 10; a++) {
    Serial.print(digitalRead(pin_e));
    delay(100);
  }
  Serial.println("");
  
  digitalWrite(pin_s, HIGH);
  Serial.print("Alto: ");

  for (a = 0; a < 10; a++) {
    Serial.print(digitalRead(pin_e));
    delay(100);
  }
  Serial.println("");
  
  digitalWrite(pin_s, LOW);
  Serial.print("Bajo: ");

  for (a = 0; a < 10; a++) {
    Serial.print(digitalRead(pin_e));
    delay(100);
  }
  Serial.println("");
  
}
