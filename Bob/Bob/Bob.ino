/* This sketch uses the RookieBot library to control custom 
 * robots for the Vicksburg Middle School Robotics Club
 * Created 10-5-2017 
 */
#include "RookieBot.h" // This is the library for our robot functions
#include "Encoder.h"  //This library will help us with motor encoder functions

//#define oldMotorController  //Uncomment this line if you have the old (blue) motor controller
#define newMotorController  //Uncomment this line if you have the new (green) motor controller

RookieBot Bob;  //This creates an instance of the RookieBot, 
                  //class, calling the fuctions from the 
                  //RookieBot library. You can name your 
                  //instance of the class whatever you like
//Encoder leftMotor(5,6);
//Encoder rightMotor(58,59);

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  Serial.begin(115200);
 Instructor.sonarSerial();
  
  // put your main code here, to run repeatedly:
//Bob.forward(250);
//Bob.reverse(250, 1000);
//Bob.turnLeft(250);
//Bob.testMotors(100);

//while (Bob.sonar() > 12)
//{
//  Bob.go(100);
//  Serial.print(Bob.sonar());
//}
//Bob.stop();
//delay(2000);
}





/* Functions:
 * wait(); looks for a button push before putting the bot into motion
 * forward(duration, speed); drive both motors forward for "duration" in ms, at speed (0-255)
 * reverse(duration, speed); drive both motors in reverse for "duration" in ms, at speed (0-255)
 * turnLeft(duration, speed); drive the left motor in reverse, right motor forward for "duration" in ms, and speed (0-255)
 * turnRight(duration, speed); drive the left motor forward, right motor in reverse for "duration" in ms, and speed (0-255)
 * stop(); stops the robot and applies the brakes.  For functions with a duration, this is already applied
 * sonarTurnRight (distance, duration of turn, speed, number of turns) drive forward until the bot reaches distance (inches) 
 * from obstacle, turn right for duration, repeat for indicated number of turns

 *************The following functions should be used for testing and debugging **********************************************
 * leftMotorF(speed); drive the left motor forward at speed (0-255); you'll have to implement a stop() function
 * rightMotorF(speed); drive the right motor forward at speed (0-255); you'll have to implement a stop() function
 * leftMotorR(speed); drive the left motor in reverse at speed (0-255); you'll have to implement a stop() function
 * rightMotorR(speed); drive the right motor in reverse at speed (0-255); you'll have to implement a stop() function
 * sonarSerial(); prints the sonar readings on the serial monitor
 * colorRead(); reads color from TCS230 color sensor and prints the results on the serial monitor
 * /
  */
