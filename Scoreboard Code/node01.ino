#include <RF24Network.h>
#include <RF24.h>
#include <SPI.h>
 
const int jackpot = 4; 
const int medium1 = 5;
const int medium2 = 6;

RF24 radio(7, 8);               // nRF24L01 (CE,CSN)
RF24Network network(radio);      // Include the radio in the network
const uint16_t this_node = 01;   // Address of this node
const uint16_t node00 = 00;      // Address of base node

void setup() {
  Serial.begin(9600);
  pinMode(jackpot, INPUT);
  pinMode(medium1, INPUT);
  pinMode(medium2, INPUT);
  SPI.begin();
  radio.begin();
  network.begin(90, this_node);  //(channel, node address)
  radio.setDataRate(RF24_2MBPS);
}

void loop() {
  int jackpotpt = digitalRead(jackpot);
  int medium1pt = digitalRead(medium1);
  int medium2pt = digitalRead(medium2);

  if(jackpotpt == HIGH) {
      send_message();
      send_message();
      send_message();
      delay(1000);

  }
  if(medium1pt == HIGH) {
      send_message();
      delay(1000);
  }
  if(medium2pt == HIGH) {
      send_message();
      delay(1000);
  }
}

void send_message() {
  RF24NetworkHeader header(node00); // Set the header to the address of the base node
  unsigned long message = 123; // Dummy message, the base node increments the score when any message sends
  bool ok = network.write(header, &message, sizeof(message)); // Send the message over the network
  if (ok) {
    Serial.println("Message sent successfully");
  } else {
    Serial.println("Message send failed");
  }
}
