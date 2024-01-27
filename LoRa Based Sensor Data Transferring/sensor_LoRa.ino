#include <LoRa_E22.h>
#include <stdio.h>

LoRa_E22 e22ttl(9, 8, 1, 6, 7);
String id="|U17019=";
const int channel=18; //the channel LoRa's are communicating on
#define SENSOR A0 // the number of the sensor pin
int value = 0;
int sc=0;

void setup() {
  
pinMode(SENSOR,INPUT);
e22ttl.begin();
ResponseStatus rs = e22ttl.sendBroadcastFixedMessage(channel, "connected");
Serial.println(rs.getResponseDescription());
Serial.begin(9600);
}

void loop() {
value=analogRead(SENSOR);
delay(2000);
sc=map(value,1023,512,0,100);  //hw-080 still needs to be scaled

// ResponseContainer rs = e22ttl.receiveMessage(); //not using this for end device
// String message = rs.data;
// Serial.println(message);

String dataToSend=String(sc);
e22ttl.sendBroadcastFixedMessage(channel, dataToSend);
Serial.println(dataToSend);
}//// loop