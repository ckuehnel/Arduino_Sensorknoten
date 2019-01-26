/*
   ESP32_WiFi_Dweetio.ino

   Connecting ESP32 to WiFi and POST data to Dweet.io
   based on https://github.com/openhomeautomation/esp8266-cloud
   createtd 2098-01-25 by Claus Kühnel (info@ckuehnel.ch) 
*/

#include <WiFi.h>
#include <HTTPClient.h>
#include "arduino_secrets.h"

// Host
const char* host = "dweet.io";
 
void setup() 
{
  Serial.begin(115200);
  delay(2000);          // wait for serial monitor
  
  Serial.print("Connecting to ");
  Serial.println(mySSID);

  WiFi.begin(mySSID, myPW);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}
 
void loop() 
{
  Serial.print("connecting to ");
  Serial.println(host);

  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  
  const int httpPort = 80;
  
  if (!client.connect(host, httpPort)) 
  {
    Serial.println("connection failed");
    return;
  }

  Serial.print("Requesting URL: ");
  Serial.println(host);

  float t = (float) random(-20, 60);  // simulated by pseudo-random value
  float h = (float) random(0,100);    // simulated by pseudo-random value

  Serial.print("t: "); Serial.println(t);
  Serial.print("h: "); Serial.println(h);

  // This will send the request to the server
  client.print(String("GET /dweet/for/myDHT?temperature=") + String(t) + "&humidity=" + String(h) + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
  delay(10);
  
  // Read all the lines of the reply from server and print them to Serial
  while(client.available())
  {
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }
  
  Serial.println();
  Serial.println("closing connection");

  delay(10000);  //Send a request every 10 seconds
}
