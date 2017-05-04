int sigPin = 12; 
int value = 0;   
  
void setup(){
  Serial.begin(9600);
  pinMode(sigPin, INPUT);
}
  
void loop(){
  value = digitalRead(sigPin); // Read the sensor
 
  if (value == HIGH) { 
    Serial.println("negro");
  } else {
    Serial.println("blanco");
  }

  delay (100);
}
