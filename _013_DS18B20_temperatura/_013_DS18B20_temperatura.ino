// Ejemplo Dallas Temperature

// Incluimos librerias necesarias
#include <OneWire.h>
#include <DallasTemperature.h>

// Datos del sensor por el pin digital 3
#define ONE_WIRE_BUS 3

// Instanciamos oneWire para comunicar con cualquier dispositivo OneWire (comunicacion bidirecional por un cable)
OneWire oneWire(ONE_WIRE_BUS);

// Pasamos nuestra referencia de "oneWire" a "Dallas Temperature".
DallasTemperature sensors(&oneWire);

void setup(void){
  Serial.begin(9600);
  Serial.println("Dallas Temperature IC Control Library Demo");

  // Inicio de la libreria
  sensors.begin();
}

void loop(void){ 
  // LLamamos sensors.requestTemperatures() para la temperatura global
  Serial.print("Requesting temperatures...");
  
  sensors.requestTemperatures();
  
  Serial.println("DONE");
  
  // Una vez tengamos la temperatura la imprimimos por pantalla
  Serial.print("La temperatura es de: ");
  Serial.println(sensors.getTempCByIndex(0));  
}
