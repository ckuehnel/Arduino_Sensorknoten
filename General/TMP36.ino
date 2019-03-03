/*
   TMP36.ino

   Measuring temperature by TMP36 sensor @ Arduino Uno
    
   created 2018-12-20 by Claus Kuehnel (info@ckuehnel.ch  
*/
int raw;
float temp, volt;

const int pTMP36 = A0;
const float Vs = 5.0;     // VCC,  5 V for Arduino Uno 

void setup()
{
  Serial.begin(9600);
  delay(2500);  // wait for serial monitor
  Serial.println("Measuring temperature by TMP36");
}

void loop()
{
  raw = analogRead(pTMP36);
  volt = raw * Vs/1024;
  Serial.print("Voltage = "); Serial.print(volt, 3); Serial.print(" V\t");
  temp = (volt - 0.5) * 100; 
  Serial.print("Temperature =  ");
  Serial.print(temp, 1);
  Serial.println(" °C");
  delay(1000);
}
