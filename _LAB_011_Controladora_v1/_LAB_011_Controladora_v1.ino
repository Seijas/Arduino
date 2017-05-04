
int md_1 = 6;
int md_2 = 7;
int md_3 = 8;
int md_4 = 9;

int mi_1 = 2;
int mi_2 = 3;
int mi_3 = 4;
int mi_4 = 5;

int pasos_azanzar = 4096;
int pasos_giro = 2048;

int Paso [ 8 ][ 4 ] =
   {  {1, 0, 0, 0},
      {1, 1, 0, 0},
      {0, 1, 0, 0},
      {0, 1, 1, 0},
      {0, 0, 1, 0},
      {0, 0, 1, 1},
      {0, 0, 0, 1},
      {1, 0, 0, 1}
   };

char choice[1];
int pasos_derecha = 0;
int pasos_izquierda = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(md_1, OUTPUT);
  pinMode(md_2, OUTPUT);
  pinMode(md_3, OUTPUT);
  pinMode(md_4, OUTPUT);
  
  pinMode(mi_1, OUTPUT);
  pinMode(mi_2, OUTPUT);
  pinMode(mi_3, OUTPUT);
  pinMode(mi_4, OUTPUT);
}

void loop() {

  if (Serial.available()){
    choice[0] = Serial.read();
    
    if (choice[0] == 'A'){
      avanzar();
    } else if (choice[0] == 'D') {
      derecha();
    } else if (choice[0] == 'I') {
      izquierda();
    }
  }

}

void avanzar() {
  
  for(int i=0; i<pasos_azanzar; i++){
    digitalWrite( md_1, Paso[pasos_derecha][ 0] );
    digitalWrite( md_2, Paso[pasos_derecha][ 1] );
    digitalWrite( md_3, Paso[pasos_derecha][ 2] );
    digitalWrite( md_4, Paso[pasos_derecha][ 3] );
    
    digitalWrite( mi_1, Paso[pasos_izquierda][ 0] );
    digitalWrite( mi_2, Paso[pasos_izquierda][ 1] );
    digitalWrite( mi_3, Paso[pasos_izquierda][ 2] );
    digitalWrite( mi_4, Paso[pasos_izquierda][ 3] );

    pasos_derecha++;
    pasos_izquierda--;
    pasos_derecha = (pasos_derecha + 8) % 8;
    pasos_izquierda = (pasos_izquierda + 8) % 8;
    
    delay (1) ;
  }
  
}

void derecha() {
  
  for(int i=0; i<pasos_giro; i++){
    digitalWrite( md_1, Paso[pasos_derecha][ 0] );
    digitalWrite( md_2, Paso[pasos_derecha][ 1] );
    digitalWrite( md_3, Paso[pasos_derecha][ 2] );
    digitalWrite( md_4, Paso[pasos_derecha][ 3] );
    
    digitalWrite( mi_1, Paso[pasos_izquierda][ 0] );
    digitalWrite( mi_2, Paso[pasos_izquierda][ 1] );
    digitalWrite( mi_3, Paso[pasos_izquierda][ 2] );
    digitalWrite( mi_4, Paso[pasos_izquierda][ 3] );

    pasos_derecha--;
    pasos_izquierda--;
    pasos_derecha = (pasos_derecha + 8) % 8;
    pasos_izquierda = (pasos_izquierda + 8) % 8;
    
    delay (1) ;
  }
  
}

void izquierda() {
  
  for(int i=0; i<pasos_giro; i++){
    digitalWrite( md_1, Paso[pasos_derecha][ 0] );
    digitalWrite( md_2, Paso[pasos_derecha][ 1] );
    digitalWrite( md_3, Paso[pasos_derecha][ 2] );
    digitalWrite( md_4, Paso[pasos_derecha][ 3] );
    
    digitalWrite( mi_1, Paso[pasos_izquierda][ 0] );
    digitalWrite( mi_2, Paso[pasos_izquierda][ 1] );
    digitalWrite( mi_3, Paso[pasos_izquierda][ 2] );
    digitalWrite( mi_4, Paso[pasos_izquierda][ 3] );

    pasos_derecha++;
    pasos_izquierda++;
    pasos_derecha = (pasos_derecha + 8) % 8;
    pasos_izquierda = (pasos_izquierda + 8) % 8;
    
    delay (1) ;
  }
  
}

