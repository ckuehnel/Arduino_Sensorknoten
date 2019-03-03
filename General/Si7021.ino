/*  
   si7021.ino
   Reads measuring data from Si7021 Sensor.
   (c) Claus Kuehnel 2018-11-26 info@ckuehnel.ch

   based on: SparkFun Si7021 Breakout Example

   The library used in this example can be found here:
   https://github.com/sparkfun/Si7021_Breakout/tree/master/Libraries

   Hardware Connections:
      Si7021 ---------------- Arduino
      (-) ------------------- GND
      (+) ------------------- 3.3V (VCC)
       CL ------------------- SCL
       DA ------------------- SDA
*/

#include "SparkFun_Si7021_Breakout_Library.h"
#include <Wire.h>

float humi = 0;
float temp = 0;

//Create Instance of HTU21D or SI7021 temp and humidity sensor 
Weather sensor;

//#define Serial SerialUSB // for Arduino M0/ 

void setup()
{
  Serial.begin(115200);   // open serial over USB at 115200 baud
  delay(2000);
  Serial.println("Read Si7021 sensor...");

  sensor.begin(); //Initialize the I2C sensors and ping them
  Serial.println();
}

void loop()
{
  getWeather();
  printInfo();
  delay(2000);
}

void getWeather()
{
  // Measure Relative Humidity from the HTU21D or Si7021
  humi = sensor.getRH();

  // Measure Temperature from the HTU21D or Si7021
  temp = sensor.getTemp();
  // Temperature is measured every time RH is requested.
  // It is faster, therefore, to read it from previous RH
  // measurement with getTemp() instead with readTemp()
}

void printInfo()
{
  Serial.print("Temperature: "); Serial.print(temp); Serial.print(" °C, ");
  Serial.print("Humidity: "); Serial.print(humi, 1); Serial.println(" % rF");
}
