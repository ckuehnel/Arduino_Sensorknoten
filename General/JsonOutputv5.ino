/*  
   JsonOutputv5.ino
   Preparing sensor data for output in Json format
   (c) Claus Kuehnel 2018-11-26 info@ckuehnel.ch
*/

#include <ArduinoJson.h>

// helper macro
#define LINE(name,val) Serial.print(name); Serial.print(" "); Serial.println(val);

#define SENSOR1 "BME280"
#define SENSOR2 "DHT11"
#define SENSOR3 "NEO6M_GPS"

#define Serial SerialUSB // for Arduino M0

void setup() 
{
  // Initialize Serial port
  Serial.begin(115200);
  while(!Serial); // wait for serial port to connect. Needed for native USB.
  
  LINE("File", __FILE__);
  
  String s1 = __DATE__;
  String s2 = __TIME__;
  
  // Date of compilation
  LINE("Compilation @", s1 + " " + s2);
  
  // Arduino IDE SW version
  LINE("ARDUINO IDE", ARDUINO);

  Serial.print("Test JSON output using ArduinoJson v.");
  Serial.println(ARDUINOJSON_VERSION);

  //https://arduinojson.org/v5/assistant/ used for configuration
  const size_t bufferSize = JSON_ARRAY_SIZE(2) + JSON_OBJECT_SIZE(1) + JSON_OBJECT_SIZE(2) + 2*JSON_OBJECT_SIZE(3);
  DynamicJsonBuffer jsonBuffer(bufferSize);

  JsonObject& root = jsonBuffer.createObject();

  JsonObject& sensor1 = root.createNestedObject(SENSOR1);
  sensor1["temperature"] = 22.2;
  sensor1["humdity"] = 66;
  sensor1["pressure"] = 999;

  JsonObject& sensor2 = root.createNestedObject(SENSOR2);
  sensor2["temperature"] = 22.2;
  sensor2["humdity"] = 66;

  JsonObject& sensor3 = root.createNestedObject(SENSOR3);

  JsonArray& sensor3_position = sensor3.createNestedArray("position");
  sensor3_position.add(8.8172433);
  sensor3_position.add(47.1979687);

  Serial.println("\nOutput minified JSON...");
  root.printTo(Serial);

  Serial.println("\n\nOutput prettified JSON...");
  root.prettyPrintTo(Serial);
}

void loop() {};
