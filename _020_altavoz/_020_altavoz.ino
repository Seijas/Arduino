/* Antonio Guillermo Pérez Coronilla */

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

int choice;

void setup(){
  Serial.begin(9600);
  Serial.println("Select song:");
  Serial.println("press: 1 to Harry Potter");
  Serial.println("press: 2 to Star Wars");
  Serial.println("press: 3 to Imperial March");
  Serial.println("press: 4 to make complete scale");
}

void nota(int frec, int t){
  tone(spk,frec);
  delay(t);
}


void loop(){
  choice = Serial.parseInt();

  if (choice == 1) {
    theme_harry_potter();
  } else if (choice == 2) {
    theme_star_wars();
  } else if (choice == 3) {
    theme_imperial_march();
  } else if (choice == 4) {
    test_escala();
  }
}

void test_escala(){
  for(int i=0; i<5; i++){
    nota(c[i+1],1000);noTone(spk);delay(100);
    nota(cs[i+1],1000);noTone(spk);delay(100);
    nota(d[i+1],1000);noTone(spk);delay(100);
    nota(ds[i+1],1000);noTone(spk);delay(100);
    nota(e[i+1],1000);noTone(spk);delay(100);
    nota(f[i+1],1000);noTone(spk);delay(100);
    nota(fs[i+1],1000);noTone(spk);delay(100);
    nota(g[i+1],1000);noTone(spk);delay(100);
    nota(gs[i+1],1000);noTone(spk);delay(100);
    nota(a[i+1],1000);noTone(spk);delay(100);
    nota(as[i+1],1000);noTone(spk);delay(100);
    nota(b[i+1],1000);noTone(spk);delay(100);
  }
}

void theme_harry_potter(){
  nota(b[2], 500);          
  nota(e[3],1000); 
  nota(g[3], 250);
  nota(fs[3],250);
  nota(e[3],1000);
  nota(b[3],500);
  nota(a[3],1250);
  nota(fs[3],1000);    
  nota(b[2], 500);
  nota(e[3],1000);
  nota(g[3],250);  
  nota(fs[3],250);
  nota(d[3],1000);
  nota(e[3],500 );
  nota(b[2],1000 );    
  noTone(spk); delay(1000);   
  nota(b[2], 500);
  nota(e[3],1000);
  nota(g[3], 250);
  nota(fs[3],250);
  nota(e[3],1000);
  nota(b[3],500);
  nota(d[4],1000);
  nota(cs[4],500);
  nota(c[4],1000);
  nota(a[3],500);
  nota(c[4],1000);
  nota(b[3],250);
  nota(as[3],250);
  nota(b[2],1000);
  nota(g[3],500);
  nota(e[3],1000);
  noTone(spk);
  delay(2000);
}

void theme_star_wars(){
  nota(d[1],150);noTone(spk);delay(50);
  nota(d[1],150);noTone(spk);delay(50);
  nota(d[1],150);noTone(spk);delay(50);
  nota(g[1],900);noTone(spk);delay(150);
  nota(d[2],900);noTone(spk);delay(50);
  nota(c[2],150);noTone(spk);delay(50);
  nota(b[1],150);noTone(spk);delay(50);
  nota(a[1],150);noTone(spk);delay(50);
  nota(g[2],900);noTone(spk);delay(150);
  nota(d[2],900);noTone(spk);delay(100);
  nota(c[2],150);noTone(spk);delay(50);
  nota(b[1],150);noTone(spk);delay(50);
  nota(a[1],150);noTone(spk);delay(50);
  nota(g[2],900);noTone(spk);delay(150);
  nota(d[2],900);noTone(spk);delay(100);
  nota(c[2],150);noTone(spk);delay(50);
  nota(b[1],150);noTone(spk);delay(50);
  nota(c[2],150);noTone(spk);delay(50);
  nota(a[1],1200);noTone(spk);delay(2000);
}

void theme_imperial_march(){
  nota(g[2],500);noTone(spk);delay(100);
  nota(g[2],500);noTone(spk);delay(100);
  nota(g[2],500);noTone(spk);delay(100);
  nota(ds[2],500);noTone(spk);delay(1);
  nota(as[2],125);noTone(spk);delay(25);
  nota(g[2],500);noTone(spk);delay(100);
  nota(ds[2],500);noTone(spk);delay(1);
  nota(as[2],125);noTone(spk);delay(25);
  nota(g[2],500);
  noTone(spk);delay(2000);
}

