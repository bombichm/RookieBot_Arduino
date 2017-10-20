#include "Arduino.h"
#include "RookieBot.h"
#include "Encoder.h"


RookieBot::RookieBot()
{
  pinMode(_MOTORA_LPWM, OUTPUT);//Left motor speed (PWM)
  pinMode(_MOTORA_LFWD, OUTPUT);//HIGH = Left forward
  pinMode(_MOTORA_DIS,  OUTPUT);//A_DIS
  pinMode(_MOTORA_LREV, OUTPUT);//HIGH = Left reverse
  pinMode(_MOTORB_RPWM, OUTPUT);//right motor speed (PWM)
  pinMode(_MOTORB_RFWD, OUTPUT);//HIGH = right forward
  pinMode(_MOTORB_DIS,  OUTPUT);//B_DIS
  pinMode(_MOTORB_RREV, OUTPUT);//HIGH = right reverse
  byte speed = constrain(speed, 50, 200);

  pinMode(_trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(_echoPin, INPUT); // Sets the echoPin as an Input

  pinMode(_WAIT_BTN, INPUT_PULLUP);

  pinMode(_S0, OUTPUT);
  pinMode(_S1, OUTPUT);//PINS S0-S3 as OUTPUT
  pinMode(_S2, OUTPUT);
  pinMode(_S3, OUTPUT);
  pinMode(_OutPut, INPUT);//OUT PIN from sensor as input to DUE

  Serial.begin(112500);

  //Encoder leftMotor(A5,A4); //left motor encoder, chan A, chan B
  //Encoder rightMotor(5,6);  //right motor encoder,chan A, chan B
  //int leftEncoder = leftMotor.read();
  //int rightEncoder = rightMotor.read();
  
}

void RookieBot::forward(byte speed, int duration)
  {
    Serial.println("Forward");
    leftMotorF(speed);
    rightMotorF(speed);
    delay (duration);
    stop();
  }

void RookieBot::go(byte speed)
  {
    Serial.println("Go");
    leftMotorF(speed);
    rightMotorF(speed);
  }

void RookieBot::reverse(byte speed, int duration)
  {
    Serial.println ("Reverse");
    leftMotorR(speed);
    rightMotorR(speed);
    delay (duration);
    stop();
  }

void RookieBot::turnRight(byte speed, int duration)
  {
    Serial.println ("turnRight");
    leftMotorF (speed);
    rightMotorR (speed);
    delay(duration);
    stop();
  }
  
void RookieBot::turnLeft(byte speed, int duration)
  {
    Serial.println ("turnLeft");
    leftMotorR (speed);
    rightMotorF (speed);
    delay(duration);
    stop();
  }

void RookieBot::leftMotorF(byte speed)
  {
    Serial.println ("leftMotorF");
    digitalWrite(_MOTORA_LFWD, HIGH); //left motor forward
    digitalWrite(_MOTORA_LREV, LOW); 
    analogWrite(_MOTORA_LPWM, (speed));
  }
  
void RookieBot::rightMotorF (byte speed)
  {
    Serial.println ("rightMotorF");
    digitalWrite(_MOTORB_RFWD, HIGH);  //right motor forward
    digitalWrite(_MOTORB_RREV, LOW); 
    analogWrite(_MOTORB_RPWM, (speed));
  }
  
void RookieBot::leftMotorR(byte speed)
  {
    Serial.println ("leftMotorR");
    digitalWrite(_MOTORA_LFWD, LOW); //left motor reverse
    digitalWrite(_MOTORA_LREV, HIGH); 
    analogWrite(_MOTORA_LPWM, (speed));

  }
  
void RookieBot::rightMotorR(byte speed)
  {
    Serial.println ("rightMotorR");
    digitalWrite(_MOTORB_RFWD, LOW);  //right motor reverse
    digitalWrite(_MOTORB_RREV, HIGH); 
    analogWrite(_MOTORB_RPWM, (speed));

  }

void RookieBot::stop()
  {
    Serial.println ("Stop");
    digitalWrite(_MOTORA_LPWM, HIGH); //engage the brakes
    digitalWrite(_MOTORB_RPWM, HIGH); //engage the brakes
    digitalWrite(_MOTORA_LFWD, HIGH);
    digitalWrite(_MOTORA_LREV, HIGH);
    digitalWrite(_MOTORB_RFWD, HIGH);
    digitalWrite(_MOTORB_RREV, HIGH);
    delay(100); //slow down a little with inertia
   }

void RookieBot::wait()
  {
    while  (digitalRead(_WAIT_BTN) == HIGH);
    {
      stop();
    }
  }

int RookieBot::sonar() 
{
  int oldDistance = _distance;
  long duration;
  digitalWrite(_trigPin, LOW);  // Clears the trigPin
  delayMicroseconds(2);
  digitalWrite(_trigPin, HIGH);  // Sets the trigPin on HIGH state for 10 micro seconds
  delayMicroseconds(10);
  digitalWrite(_trigPin, LOW);
  duration = pulseIn(_echoPin, HIGH, 20000);  // Reads the echoPin, returns the sound wave travel time in microseconds with a timeout of                                                   20ms, which corresponds approximately to 3m
  if(duration == 0) // If we timed out
    {
    duration = 20000;
    pinMode(_echoPin, OUTPUT); // Then we set echo pin to output mode
    digitalWrite(_echoPin, LOW); // We send a LOW pulse to the echo pin
    //Serial.print("oor");
    delayMicroseconds(100);
    pinMode(_echoPin, INPUT); // And finaly we come back to input mode
    }
  _distance= duration/148;  // Calculating the distance
  delay(50);
  if (_distance != 0 | _distance != 500) 
    { 
      _distance = (oldDistance + _distance)/2; //averaging to smooth values
      return _distance;
    }
  else
    {
      _distance = oldDistance;
      return _distance;
      Serial.print("Distance = ");
      Serial.println(_distance);
    }
}
  
void RookieBot::sonarSerial()
{
    int counter = 0;
    while (counter < 10000)
      {
      sonar();
      Serial.println(_distance);
      counter++;
      delay(50);
      }
}

void RookieBot::colorRead()
  {
  digitalWrite(_S0,HIGH);
  digitalWrite(_S1,LOW); //setting frequency selection to 20%
  
  Serial.print("R=");//printing name
  digitalWrite(_S2,LOW);
  digitalWrite(_S3,LOW);//setting for RED color sensor
  frequency = pulseIn(_OutPut, LOW);//reading frequency
  Serial.print(frequency);//printing RED color frequency
  Serial.print("  ");
  delay(50);
  red = frequency;
 
  Serial.print("B=");// printing name
  digitalWrite(_S2,LOW);
  digitalWrite(_S3,HIGH);// setting for BLUE color sensor
  frequency = pulseIn(_OutPut, LOW);// reading frequency
  Serial.print(frequency);// printing BLUE color frequency
  Serial.print("  ");
  delay(50);
  blue = frequency;
 
  Serial.print("G=");// printing name
  digitalWrite(_S2,HIGH);
  digitalWrite(_S3,HIGH);// setting for GREEN color sensor
  frequency = pulseIn(_OutPut, LOW);// reading frequency
  Serial.println(frequency);// printing GREEN color frequency
  delay(50);   
  green = frequency;     
}  

void readEncoders()
{

}