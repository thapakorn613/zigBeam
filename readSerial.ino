#include <Wire.h>
#include <HardwareSerial.h>
#include <StackArray.h>


#define RXD2 16
#define TXD2 17

const int ledPin = 13;
int incomingByte = 0;


HardwareSerial mySerial(2); // use UART 2 ( RX = RXD2, TX = TXD2 )

void ledStatus(const int ledPin){
    digitalWrite (ledPin, HIGH);  // turn on the LED
    delay(500);
    digitalWrite (ledPin, LOW); // turn off the LED
    delay(500);
}
void setup() {
  // Note the format for setting a serial port is as follows: Serial2.begin(baud-rate, protocol, RX pin, TX pin);
  Serial.begin(115200);
  mySerial.begin(115200);
  Serial.println("Serial Txd is on pin: "+String(TXD2));
  Serial.println("Serial Rxd is on pin: "+String(RXD2));
  sendContact();
}

void loop() { //Choose Serial1 or Serial2 as required
  while (mySerial.available()) {
    Serial.write(mySerial.read());
  }
  while (Serial.available()) {
    mySerial.write(Serial.read());
  }
}
void sendContact() {
  mySerial.write("PREMITJOIN 255");
  mySerial.write("\n");
}
