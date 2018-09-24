The *Heltec WiFi LoRa 32* microcontroller is used for this kind of sensor node including an OLED display.
As communication interface WiFi, LoRaWAN and BLE are available.

The following sensors are used for measuring environmental data:
* DHT11 for temperature & humidity
* waterproof DS18B20 1-Wire temperature sensor for outdoor measurements
* Si7021 for humidity & temperature 
* GY-30/BH1750FVI for light
* BMP085 for barometric pressure, Temperature & Altitude 
* Sparkfun weather shield utilizing Si7021 humidity/temperature sensor, MPL3115A2 barometric pressure sensor and ALS-PT19 light sensor 

The measured data will be sent by WiFi connection as Dweets (dweet.io), by LoRaWAN to the TTN server available there for subscription by a MQTT client and as BLE data. 
