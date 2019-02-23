#include <ClimaStick.h>
#include "arduino_secrets.h"

unsigned long now = millis();
unsigned long last = 0;
unsigned long interval = 15000;

ClimaStick thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);
  
void setup() 
{
  Serial.begin(115200);
  delay(2000);
  Serial.println("Initializing ClimaStick v1");
  Serial.print("Connecting to ");
  Serial.println(mySSID);
   
  thing.add_wifi(mySSID, myPW);
  thing.init_sensors();

  thing["environment"] >> [] (pson& out)
  {
    Environmental clima = thing.get_clima();
    out["temperature"]=clima.temperature; 
    out["humidity"]=clima.humidity;
    out["altitude"]=clima.altitude;
    out["pressure"]=clima.pressure;
    out["lux"]=clima.lux;
  };
  Serial.println("Initialization done.");
}
 
void loop() 
{
  thing.handle();

  now = millis();
  if (now - last > interval)
  {
    last = now; 

    Serial.print("\nTemperature = "); Serial.print(thing.get_temperature(),1); Serial.println(" °C");
    Serial.print("Humidity = "); Serial.print(thing.get_humidity(),0); Serial.println(" % r.H.");
  }
}
