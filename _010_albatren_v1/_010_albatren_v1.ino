int sigPinI = 1;
int sigPinC = 2;
int sigPinD = 3;

int valueI = 0;
int valueC = 0;
int valueD = 0;

int motorI = 4;
int motorD = 5;

void setup(){
  pinMode(sigPinI, INPUT);
  pinMode(sigPinC, INPUT);
  pinMode(sigPinD, INPUT);

  pinMode(motorI, OUTPUT);
  pinMode(motorD, OUTPUT);
}
  
void loop(){
  valueI = digitalRead(sigPinI);
  valueC = digitalRead(sigPinC);
  valueD = digitalRead(sigPinD); // Read the sensor
 
  if (valueC == HIGH && valueI == LOW && valueD == LOW) {
    digitalWrite(motorI, HIGH);
    digitalWrite(motorD, HIGH);
  } else if (valueC == LOW && valueI == LOW && valueD == HIGH) {
    digitalWrite(motorI, HIGH);
    digitalWrite(motorD, LOW);
  } else if (valueC == LOW && valueI == HIGH && valueD == LOW) {
    digitalWrite(motorI, LOW);
    digitalWrite(motorD, HIGH);
  } else { 
    Serial.println("blanco"); // Write on console
  }
}
