/*
  Heltec_LoRa32_I2C_Scan
  (c) Claus Kuehnel 2018-09-24 info@ckuehnel.ch

  The Heltec WiFi LoRa 32 uses the 1st I2C Bus to control the OLED.
  To connect further I2C devices you can use the 2nd I2C bus.
  This program scans the 2nd I2C bus for connected I2C devices
*/

// OLED Library https://github.com/ThingPulse/esp8266-oled-ssd1306
#include <SSD1306.h>

//OLED pins to ESP32 GPIOs on Heltec LoRa32:
//OLED_SDA -- GPIO4
//OLED_SCL -- GPIO15
//OLED_RST -- GPIO16

SSD1306  display(0x3c, 4, 15);

const int pLED = 25;
const int pResetOLED = 16;

/* I2C */
#include <Wire.h>
//SDA -- GPIO21
//SCL -- GPIO22

// Use second I2C bus for sensors
TwoWire SensorWire = TwoWire(1);

void setup()
{
  // Bringup sensor I2C bus BEFORE OLED.
  SensorWire.begin(21, 22);
  
  initOLED();
  
  Serial.begin(115200);
  delay(1000); // give me time to bring up serial monitor
  Serial.println(F("\nScanning 2nd I2C Bus...\n"));
  display.drawStringMaxWidth(0, 0, 128, "Scanning 2nd I2C Bus..." );
  display.display();
  delay(1000);
}

void loop()
{
  byte error, address;
  int nDevices;
 
  Serial.println("Scanning...");
 
  nDevices = 0;
  for(address = 1; address < 127; address++ )
  {
    // The i2c_scanner uses the return value of
    // the Write.endTransmisstion to see if
    // a device did acknowledge to the address.
    SensorWire.beginTransmission(address);
    error = SensorWire.endTransmission();
 
    if (error == 0)
    {
      Serial.print("I2C device found at address 0x");
      if (address<16)
        Serial.print("0");
      Serial.print(address,HEX);
      Serial.println("  !");
 
      nDevices++;
    }
    else if (error==4)
    {
      Serial.print("Unknown error at address 0x");
      if (address<16)
        Serial.print("0");
      Serial.println(address,HEX);
    }    
  }
  if (nDevices == 0)
    Serial.println("No I2C devices found\n");
  else
    Serial.println("done\n");
 
  delay(5000);           // wait 5 seconds for next scan

}

// Initialize OLED
void initOLED()
{
  pinMode(pResetOLED, OUTPUT);
  digitalWrite(pResetOLED, LOW);         // set GPIO16 low to reset OLED
  delay(50); 
  digitalWrite(pResetOLED, HIGH);        // while OLED is running, must set GPIO16 in high
  
  display.init(); // Initialising the UI will init the display too.
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_16);
  display.setTextAlignment(TEXT_ALIGN_LEFT);
}


