int motorPin1 = 4;    // Azul   - 28BYJ48 pin 1 motor
int motorPin2 = 5;    // Rosa   - 28BYJ48 pin 2 motor
int motorPin3 = 6;    // Amarillo - 28BYJ48 pin 3 motor
int motorPin4 = 7;    // Naranja - 28BYJ48 pin 4 motor
                      // Rojo   - 28BYJ48 pin 5 (VCC) motor

int motorSpeed = 1200;  //variable para fijar la velocidad del motor (el retraso entre cada secuencia)
int count = 0;          // cuenta de los pasos dados
int countsperrev = 512; // número de pasos por vuelta completa 
int lookup[8] = {B01000, B01100, B00100, B00110, B00010, B00011, B00001, B01001};

void setup() {
  //declare the motor pins as outputs
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  Serial.begin(9600);
  Serial.println("fin setup");
}

void loop(){
  Serial.println("loop");
  if(count < countsperrev ){
    clockwise(); //sentido agujas del reloj
    Serial.println("clock no se que");
  } else if (count == countsperrev * 2) {
    count = 0;
    Serial.println("supongo que cero");
  } else {
    anticlockwise(); //sentido antihorario
    Serial.println("pa tra");
  }
  count++;
}


//creación funciones giro horario y antihorario
void anticlockwise() 
{
  for(int i = 0; i < 8; i++)
  {
    setOutput(i);
    delayMicroseconds(motorSpeed);
  }
}

void clockwise()
{
  for(int i = 7; i >= 0; i--)
  {
    setOutput(i);
    delayMicroseconds(motorSpeed);
  }
}

void setOutput(int out) //función secuencia giro
{
  digitalWrite(motorPin1, bitRead(lookup[out], 0));
  digitalWrite(motorPin2, bitRead(lookup[out], 1));
  digitalWrite(motorPin3, bitRead(lookup[out], 2));
  digitalWrite(motorPin4, bitRead(lookup[out], 3));
}
