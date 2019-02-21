/*
   GSMSim_SMS.ino

   Sends SMS to PHONE_NUMBER stored in arduino_secrets.h
   Based on https://github.com/erdemarslan/GSMSim
 */
 
#include <GSMSim.h>
#include <SoftwareSerial.h>
#include "arduino_secrets.h"

#define RX 7
#define TX 8
#define RESET 2
#define BAUD 9600


GSMSim gsm(RX, TX);

void setup() 
{
  Serial.begin(9600);

  Serial.println("GSMSim Library - SMS Example\n");
  delay(1000);

  gsm.start(); // baud default 9600
  //gsm.start(BAUD);

  Serial.println("Changing to text mode.");
  gsm.smsTextMode(true); // TEXT or PDU mode. TEXT is readable :)

  char* MESSAGE = "SMS sent by SIM800L & Arduino Uno."; // message lenght must be <= 160. Only english characters.

  Serial.println("Sending Message --->");
  if (gsm.smsSend(PHONE_NUMBER, MESSAGE))  // if success it returns true (1) else false (0)
    Serial.println("SMS sent successfully.");
  else
    Serial.println("SMS not sent.");
  delay(2000);

  Serial.println("Listing unread message(s).");
  Serial.println(gsm.smsListUnread()); // if not unread messages have it returns "NO_SMS"

  Serial.println("Read SMS on index no = 1");
  Serial.println(gsm.smsRead(1)); // if no message in that index, it returns IXDEX_NO_ERROR
 
}

void loop() {}
