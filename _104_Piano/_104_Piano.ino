int spk=13;                             // altavoz a GND y pin 13

// frecuencias 4 octavas de:
int c[5] ={131,262,523,1046,2093};      // Do
int cs[5]={139,277,554,1108,2217};      // Do#
int d[5] ={147,294,587,1175,2349};      // Re
int ds[5]={156,311,622,1244,2489};      // Re#
int e[5] ={165,330,659,1319,2637};      // Mi
int f[5] ={175,349,698,1397,2794};      // Fa
int fs[5]={185,370,740,1480,2960};      // Fa#
int g[5] ={196,392,784,1568,3136};      // Sol
int gs[5]={208,415,831,1661,3322};      // Sol#
int a[5] ={220,440,880,1760,3520};      // La
int as[5]={233,466,932,1866,3729};      // La#
int b[5] ={247,494,988,1976,3951};      // Si

int p_do = 7;
int p_re = 6;
int p_mi = 5;
int p_fa = 4;
int p_sol= 3;
int p_la = 2;

void setup(){
  Serial.begin(9600);
  pinMode(p_do, INPUT);
  pinMode(p_re, INPUT);
  pinMode(p_mi, INPUT);
  pinMode(p_fa, INPUT);
  pinMode(p_sol,INPUT);
  pinMode(p_la, INPUT);
}

void nota(int frec, int t){
  tone(spk,frec);
  delay(t);
}

void loop(){
  if ( digitalRead(p_do) == HIGH ) {
    nota(c[1],10);
  } else if ( digitalRead(p_re) == HIGH ) {
    nota(d[1],10);
  } else if ( digitalRead(p_mi) == HIGH ) {
    nota(e[1],10);
  } else if ( digitalRead(p_fa) == HIGH ) {
    nota(f[1],10);
  } else if ( digitalRead(p_sol)== HIGH ) {
    nota(g[1],10);
  } else if ( digitalRead(p_la) == HIGH ) {
    nota(a[1],10);
  } else {
    noTone(spk);
  }
}

