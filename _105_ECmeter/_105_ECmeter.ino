#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 4

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

float CalibrationEC = 1.38;    //EC value of Calibration solution is s/cm
 
int R1 = 1000;
int Ra = 25;                   //Resistance of powering Pins
int ECPin    = A0;
int ECGround = A1;
int ECPower  = A4;
 
 
//*************Compensating for temperature ************************************//
//The value below will change depending on what chemical solution we are measuring
//0.019 is generaly considered the standard for plant nutrients [google "Temperature compensation EC" for more info
float TemperatureCoef = 0.019; //this changes depending on what chemical we are measuring


float TemperatureFinish = 0;
float TemperatureStart  = 0;
float EC  = 0;
int   ppm = 0;
 
 
float raw= 0;
float Vin= 5;
float Vdrop= 0;
float Rc= 0;
float K=0;
 

int i=0;
float buffer=0;
 
void setup() {
  Serial.begin(9600);

  pinMode(ECPin, INPUT);
  pinMode(ECPower, OUTPUT);     //Setting pin for sourcing current
  pinMode(ECGround, OUTPUT);    //setting pin for sinking current
  digitalWrite(ECGround, LOW);  //We can leave the ground connected permanantly
 
  delay(100);// gives sensor time to settle
  sensors.begin();
  delay(100);
  //** Adding Digital Pin Resistance to [25 ohm] to the static Resistor *********//
  // Consule Read-Me for Why, or just accept it as true
  R1=(R1+Ra);
 
};
 

void loop() {
  i=1;
  buffer=0;
  sensors.requestTemperatures();                    // Send the command to get temperatures
  TemperatureStart = sensors.getTempCByIndex(0);    //Stores Value in Variable
 
 
//************Estimates Resistance of Liquid ****************//
  while(i<=10){
    digitalWrite(ECPower,HIGH);
    raw = analogRead(ECPin);
    raw = analogRead(ECPin);    // This is not a mistake, First reading will be low
    digitalWrite(ECPower,LOW);
    buffer = buffer+raw;
    i++;
    delay(5000);
  };
  raw=(buffer/10);
 

  sensors.requestTemperatures();                       // Send the command to get temperatures
  TemperatureFinish = sensors.getTempCByIndex(0);      //Stores Value in Variable
 
 
  //*************Compensating For Temperaure********************//
  EC =CalibrationEC*(1+(TemperatureCoef*(TemperatureFinish-25.0))) ;
 
  //***************** Calculates R relating to Calibration fluid **************************//
  Vdrop= (((Vin)*(raw))/1024.0);
  Rc=(Vdrop*R1)/(Vin-Vdrop);
  Rc=Rc-Ra;
  K= 1000/(Rc*EC);
 

  Serial.print("Calibration Fluid EC: ");
  Serial.print(CalibrationEC);
  Serial.print(" S  ");  //add units here
  Serial.print("Cell Constant K");
  Serial.print(K);
 
 
  if (TemperatureStart==TemperatureFinish) {
    Serial.println("  Results are Trustworthy");
    Serial.println("  Safe To Use Above Cell Constant in Main EC code");
  } else {
    Serial.println("  Error -Wait For Temperature To settle");
}
 
 
}
