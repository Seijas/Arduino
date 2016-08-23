int pin_a = 5;
int pin_b = 6;

int e;

void setup() {
  Serial.begin(9600);
  pinMode(pin_a, OUTPUT);
  pinMode(pin_b, OUTPUT);
}

void loop() {
  e = Serial.read();
  Serial.print(e);
  if (e == 0) {
    digitalWrite(pin_a, LOW);
    digitalWrite(pin_b, LOW);
    Serial.println("Pines apagados");
  }
  if (e == 1) {
    digitalWrite(pin_a, LOW);
    digitalWrite(pin_b, HIGH);
    Serial.println("Pin 5 apagado, Pin 6 encendido");
  }
  if (e == 2) {
    digitalWrite(pin_a, HIGH);
    digitalWrite(pin_b, HIGH);
    Serial.println("Pines ENCENDIDOS");
  }
}
