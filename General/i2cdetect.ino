/*  
   i2cdetect.ino
   Scanning I2C bus for connected devices.
   (c) Claus Kuehnel 2018-11-26 info@ckuehnel.ch

   based on: https://github.com/mcauser/i2cdetect
*/

#include <Wire.h>
#include <i2cdetect.h> 
//#define Serial SerialUSB // for Arduino M0

void setup() 
{
  Wire.begin();
  Serial.begin(115200);
  while(!Serial);       // wait for serial port to connect. Needed for native USB.
  Serial.println("i2cdetect");
  Serial.print("Scanning address range 0x03-0x77\n\n");
}

void loop() 
{
  i2cdetect();  // default range from 0x03 to 0x77
  delay(2000);
}
