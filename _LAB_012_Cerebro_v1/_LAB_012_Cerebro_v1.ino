
su-f_t = 12;
su-f_e = 11;

su-d_t = 10;
su-d_e = 9;

su-i_t = 7;
su-i_e = 8;

sigue_lineas = 6;

void setup() {
  Serial.begin(9600);
}

void loop() {

  Serial.write('D');
  delay(6000);

  Serial.write('A');
  delay(8000);

  Serial.write('A');
  delay(8000);

  Serial.write('I');
  delay(6000);

}

