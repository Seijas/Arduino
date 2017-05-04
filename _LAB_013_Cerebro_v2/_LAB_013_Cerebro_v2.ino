
int suf_t = 12;
int suf_e = 11;
int sud_t = 10;
int sud_e = 9;
int sui_t = 7;
int sui_e = 8;

int sigue_lineas = 6;
int led = 13;

int flag_sig = 0;
int flag_led = 0;

float distancia_frontal;
float distancia_derecha;
float distancia_izquierda;

int wait_time = 0;

void setup() {
  Serial.begin(9600);

  pinMode(suf_t, OUTPUT);
  pinMode(suf_e, INPUT);
  pinMode(sud_t, OUTPUT);
  pinMode(sud_e, INPUT);
  pinMode(sui_t, OUTPUT);
  pinMode(sui_e, INPUT);
  pinMode(sigue_lineas, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {

  // Sensor frontal
  digitalWrite(suf_t, LOW);
  delayMicroseconds(5);
  digitalWrite(suf_t, HIGH);
  delayMicroseconds(10);

  distancia_frontal = 0.017*pulseIn(suf_e, HIGH);
  digitalWrite(suf_t, LOW);

  // Sensor derecho
  digitalWrite(sud_t, LOW);
  delayMicroseconds(5);
  digitalWrite(sud_t, HIGH);
  delayMicroseconds(10);

  distancia_derecha = 0.017*pulseIn(sui_e, HIGH);
  digitalWrite(sud_t, LOW);

  // Sensor izquierdo
  digitalWrite(sui_t, LOW);
  delayMicroseconds(5);
  digitalWrite(sui_t, HIGH);
  delayMicroseconds(10);

  distancia_izquierda = 0.017*pulseIn(sui_e, HIGH);
  digitalWrite(sui_t, LOW);


  if (distancia_derecha > 150){
    distancia_derecha == 150;
  }
  if (distancia_izquierda > 150){
    distancia_izquierda == 150;
  }


  if ( distancia_derecha > distancia_frontal and distancia_derecha > distancia_izquierda ) {
    Serial.write('D');
    delay(5000);
  }

  if ( distancia_izquierda > distancia_frontal and distancia_izquierda > distancia_derecha ) {
    Serial.write('I');
    delay(5000);
  }
  
  Serial.write('A');
  wait_time = 7000;

  for (int i=0; i<wait_time; i++){
    flag_sig = digitalRead(sigue_lineas);

    if (flag_sig == HIGH) { 
      digitalWrite(led, HIGH);
    } else {
      digitalWrite(led, LOW);
    }
    delay(1);
  }
  wait_time = 0;

}

