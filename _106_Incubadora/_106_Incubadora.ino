

int pin_rele = 2;


void setup() {
  // Serial.begin(9600);
  pinMode(pin_rele, OUTPUT);  // Declaracion para usar el pin 2 como salida para la señal del relé
}

void loop() {
  digitalWrite(pin_rele, LOW);
  delay(10000);

  digitalWrite(pin_rele, HIGH);
  delay(10000);
}

