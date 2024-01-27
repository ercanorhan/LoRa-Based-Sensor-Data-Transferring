#include <LoRa_E22.h>
#include <stdio.h>

LoRa_E22 e22ttl(9, 8, 1, 6, 7);
String id="|U17019=";
const int channel=18;  //the channel LoRa's are communicating on
const int ledPin = 13; // the number of the LED pin
//const int potPin = A0;  // the number of the potentiometer pin


void setup() {
pinMode(ledPin, OUTPUT);
e22ttl.begin();
ResponseStatus rs = e22ttl.sendBroadcastFixedMessage(channel, "connected");
Serial.println(rs.getResponseDescription());
Serial.begin(9600); 
}

void loop() {
delay(2000);
ResponseContainer rs = e22ttl.receiveMessage();
String message = rs.data;
int receivedDataInt=message.substring(3).toInt();
Serial.println(receivedDataInt);
if (receivedDataInt < 10) {
    digitalWrite(ledPin, LOW);
  } 
else {
    digitalWrite(ledPin, HIGH);
  }

}//// loop