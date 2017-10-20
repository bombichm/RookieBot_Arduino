//https://arduino.stackexchange.com/questions/1216/how-do-i-initialize-a-servo-object-in-my-own-library

#include <Servo.h>
#include "MyNewLib.h"

// use your custom lib here
MyServoLib myServo;
int MyServoPin = 5;

void setup(){

  pinMode(MyServoPin, OUTPUT);
  myServo.setPin(MyServoPin);  
  myServo.attach();

  // your additional setup code here
}

void loop(){

  // your main code here

}