#include <SPI.h>
#include <LoRa.h>

int counter = 0;
struct data_ {
  String name = "sender";
  int id = 0123;
} data ;
void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("LoRa Sender");
  LoRa.setPins(D8, D0, D2); // nss rst dio0
  if (!LoRa.begin(915E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}

void loop() {
  Serial.print("Sending packet: ");
  Serial.println(counter);

  // send packet
  LoRa.beginPacket();
  LoRa.print("SENDER : ");
  LoRa.print(counter);
  //  LoRa.print(data_,size(data_);
  LoRa.endPacket();
  counter++;

  delay(2000);
}
