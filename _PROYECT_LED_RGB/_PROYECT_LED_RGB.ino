// Daniel Seijas Iglesias <seijasdeveloper@gmail.com>

int red = 11;
int green = 10;
int blue = 9;

void setup() {
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);

}

void loop() {

  color(255, 0, 0);  // red one second
  delay(1000);

  color(0, 255, 0);  // green one second
  delay(1000);

  color(0, 0, 255);  // blue one second
  delay(1000);

  color(255, 255, 255);    // nothing one second
  delay(1000);
}

void color(int r, int g, int b) {
  analogWrite(red, r);
  analogWrite(green, g);
  analogWrite(blue, b);
}

