
int sigIzq = 5; 
int segMid = 4;
int segDer = 3;

int v_i = 0;
int v_m = 0;
int v_d = 0; 
  
void setup(){
  Serial.begin(9600);
  
  pinMode(sigIzq, INPUT);
  pinMode(segMid, INPUT);
  pinMode(segDer, INPUT);
}
  
void loop(){
  v_i = digitalRead(sigIzq);
  v_m = digitalRead(segMid);
  v_d = digitalRead(segDer);
 
  if (v_i == HIGH) { 
    Serial.print("Izquierda: Negro  -- ");
  } else {
    Serial.print("Izquierda: Blanco -- ");
  }
  
  if (v_m == HIGH) { 
    Serial.print("Medio: Negro  -- ");
  } else {
    Serial.print("Medio: Blanco -- ");
  }
  
  if (v_d == HIGH) { 
    Serial.println("Derecha: Negro");
  } else {
    Serial.println("Derecha: Blanco");
  }

  delay(1000); // Un segundo para leer algo en consola
}
