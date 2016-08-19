int pin_e = 11;

void setup(){
  Serial.begin(9600);
  pinMode(pin_e, INPUT);
}

void loop(){
  Serial.print(digitalRead(pin_e));
  delay(10);
}
