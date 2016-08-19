int sensorPin = 10;
 
void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);  //definir pin como entrada
}
 
void loop(){

  if (digitalRead(sensorPin) == HIGH) {
    Serial.println("Detectado obstaculo");
  }

  if (digitalRead(sensorPin) == LOW) {
    Serial.println("Nada");
  }
  
  delay(500);
}
