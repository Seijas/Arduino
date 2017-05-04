int m1_up = 3;
int m2_up = 4;
int m1_back = 5;
int m2_back = 6;

int choice;

void setup(){
  Serial.begin(9600);
  pinMode(m1_up, OUTPUT);
  pinMode(m2_up, OUTPUT);
  pinMode(m1_back, OUTPUT);
  pinMode(m1_back, OUTPUT);
}
 
void loop(){
  choice = Serial.parseInt();
      Serial.print(choice);
      
      if (choice == 1) {
        digitalWrite(m1_back, LOW);
        digitalWrite(m2_back, LOW);
        digitalWrite(m1_up, HIGH);
        digitalWrite(m2_up, HIGH);
      }
      if (choice == 0) {
        digitalWrite(m1_up, LOW);
        digitalWrite(m2_up, LOW);
        digitalWrite(m1_back, HIGH);
        digitalWrite(m2_back, HIGH);
      } 
      if (choice == 2) {
        digitalWrite(m1_up, LOW);
        digitalWrite(m2_up, LOW);
        digitalWrite(m1_back, LOW);
        digitalWrite(m2_back, LOW);
      }
    
}

