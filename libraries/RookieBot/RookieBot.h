#ifndef RookieBot_h
#define RookieBot_h

#include "Arduino.h"
#include "Encoder.h"

class RookieBot
{
  public:
    RookieBot();
    void forward(byte speed, int duration = 10000);
    void reverse(byte speed, int duration = 10000);
    void turnLeft(byte speed, int duration = 10000);
    void turnRight(byte speed, int duration = 10000);
    void go(byte speed);
    void stop();
    void wait();
    void sonarSerial();
    int sonar();
    void colorRead(); 
    int red;
    int blue;
    int green;
    int leftEncoder();
    int rightEncoder();
      
 
  private:
//********************* Motors *************************
  const byte _MOTORA_LPWM = 2;    //left speed  ENA  8
  const byte _MOTORA_LFWD = 3;    //(forward)   IN3  3
  const byte _MOTORA_DIS = 4;     //              4
  const byte _MOTORA_LREV = 11;   //(reverse)   IN4  11
  
  const byte _MOTORB_RPWM = 8;    //right speed ENB  l2
  const byte _MOTORB_RFWD = 10;    //(forward)  IN2   9
  const byte _MOTORB_DIS = 7;     //not on board     12
  const byte _MOTORB_RREV = 9;   //(reverse)    IN1  10

#define newMotorController
#ifdef newMotorController
  byte speed = 255-speed;

#endif

//****************** Color Sensor **********************
  unsigned int frequency = 0;
  const byte _S0 = 15;
  const byte _S1 = 16;
  const byte _S2 = 17;
  const byte _S3 = 18;
  const byte _OutPut = 19;

//********************* Sonar *************************
  const byte _trigPin = 5;  // Arduino pin tied to trigger pin on the ultrasonic sensor.
  const byte _echoPin = 6;  // Arduino pin tied to echo pin on the ultrasonic sensor.
  int _distance;

//******************* Encoders *************************
//VCC (yellow)
//GND (white)
//Chan A (red)
//Chan B (black)
  

  const byte _WAIT_BTN = 21;

  void leftMotorF(byte speed);
  void rightMotorF (byte speed);
  void leftMotorR(byte speed);
  void rightMotorR(byte speed);

};

#endif