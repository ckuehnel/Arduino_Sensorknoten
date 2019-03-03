/*
   GY-30.ino
   
   Sample code for the BH1750 Light sensor resp. GY-30 breakout board
 
   Connection:
   VCC-5v
   GND-GND
   SCL-SCL(analog pin-5)
   SDA-SDA(analog pin-4)
   ADD-NC <-- to asign a different I2C address to the sensor

   based on http://qqtrading.com.my/digital-light-intensity-sensor-module-gy-30-bh1750fvi
   adaptions 2018-12-29 by Claus Kuehnel (info@ckuehnel.ch)
*/
 
#include <Wire.h> //BH1750 IIC Mode
#include <math.h> 

#define Serial SerialUSB // Arduino M0

int BH1750address = 0x23; //setting i2c address
 
byte buff[2];

void setup()
{
   Wire.begin();
   Serial.begin(115200); 
   delay(2000);   // wait for serial monitor
   Serial.println("Measure ambient light by BH1750 light sensor");
}
 
void loop()
{
   int i;
   uint16_t val=0;
   
   BH1750_Init(BH1750address);
   delay(200);
 
   if(2==BH1750_Read(BH1750address))
   {
     val=((buff[0]<<8)|buff[1])/1.2;
     Serial.print(val,DEC);     
     Serial.println(" lx"); 
   }
   delay(5000);
}
 
int BH1750_Read(int address)
{
   int i=0;
   Wire.beginTransmission(address);
   Wire.requestFrom(address, 2);
   while(Wire.available()) 
   {
      buff[i] = Wire.read();  // receive one byte
      i++;
   }
   Wire.endTransmission();  
   return i;
}
 
void BH1750_Init(int address) 
{
   Wire.beginTransmission(address);
   Wire.write(0x10);          //1lx reolution 120ms
   Wire.endTransmission();
}
