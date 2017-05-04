int pin = 8;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pin, OUTPUT);

  digitalWrite(pin, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println("Pin LOW");
  digitalWrite(pin, LOW);
  delay(10000);

  Serial.println("Pin HIGH");
  digitalWrite(pin, HIGH);
  delay(10000);
}
