#include <RookieBot.h>

RookieBot pablo;

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
//pablo.forward(1000,250);
//pablo.reverse(1000, 250);
//pablo.turnLeft(1000, 250);
//pablo.sonarSerial();
pablo.colorRead();
}
