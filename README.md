# Arduino_Sensorknoten


Hier sind die Programmbeispiele des Beitrags "Sensorknoten" veröffentlicht im Sammelwerk "Messen, Steuern, Regeln mit IBM-kompatiblen PCs" des Weka-Verlags abgelegt.

Die folgenden Sensoren werden zum Messen von Umweltdaten eingesetzt:
* Temperatursensor TMP36
* DHT11 für Temperatur und rel. Feuchte
* Si7021 für Temperatur und rel. Feuchte
* wasserdichter DS18B20 1-Wire Temperatursensor für Messungen aussen
* barometrischer Drucksensor BMP180/280
* Luftqualitätssensor MQ135
* Grove Feinstaubsensor PPD42NS 
* Lichtstärkesensor GY-30/BH1750FVI

Die gemessenen Daten werden über WiFi an einen Server, über LoRaWAN zum TTN Server, wo sie von einem MQTT Client aus bezogen werden können, oder als BT/BLE Data an ein Smartphone o.ä. gesendet. 

