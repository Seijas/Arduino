int ledPin = 13; // Arduino' inner led
int sigPin = 2; // For sensor signal
int value = 0; // Holds the returned value
  
void setup(){
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT); // Arduino's led as output
  pinMode(sigPin, INPUT); // signal pin as input
}
  
void loop(){
  value = digitalRead(sigPin); // Read the sensor
 
  if (value == HIGH) { // iF HIGH, black area
    // digitalWrite(ledPin, HIGH); // Turn on the LED
    Serial.println("negro"); // Write on console
  } else { // Else, white area
    // digitalWrite(ledPin, LOW); // Turn off the LED
    Serial.println("blanco"); // Write on console
  }
}
