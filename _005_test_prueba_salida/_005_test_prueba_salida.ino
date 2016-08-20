int pin_s = 12;

void setup() {
  pinMode(pin_s);
}

void loop() {

  digitalWrite(pin_s, HIGH);
  delay(1000);

  digitalWrite(pin_s, LOW);
  delay(1000);
  
}
