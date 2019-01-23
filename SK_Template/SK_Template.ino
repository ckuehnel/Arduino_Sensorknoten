/*
 SK_Templeate.ino
*/

#include "arduino_secrets.h" 

#define INFO 1
#define DEBUG 1
#define BAUDRATE 115200

float value;

void setup() 
{
  Serial.begin(BAUDRATE);
  delay(2000);              // wait for serial monitor
  if (INFO)  printInfo();
  if (DEBUG) Serial.println(F("Initializing..."));
  /*
   * Put your setup code here
   */

  if (DEBUG) Serial.println(F("Running...")); //last line in setup()
}

void loop() 
{
  /*
   * Put your loop code here
   */
   value = getValue();
   Serial.println(value);  // Sample code
   delay(2000);
}

/*--------------------------------------------------------------*/

void printInfo()
{
  // Compile file path (internal file of compilation proccess)
  Serial.print("File "); Serial.println(__FILE__);
  
  String s1 = __DATE__;
  String s2 = __TIME__;
  
  // Date of compilation
  Serial.print("Compilation @ "); Serial.println(s1 + " " + s2);
  
  // Arduino IDE SW version
  Serial.print("ARDUINO IDE v"); Serial.println(ARDUINO);
  
  // Oscillator frequency
  Serial.print("CPU Clock in MHz: "); Serial.println(F_CPU/1E6);
}
