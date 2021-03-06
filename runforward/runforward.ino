
/*
 Stepper Motor Control - one revolution

 This program drives a unipolar or bipolar stepper motor.
 The motor is attached to digital pins 8 - 11 of the Arduino.

 The motor should revolve one revolution in one direction, then
 one revolution in the other direction.


 Created 11 Mar. 2007
 Modified 30 Nov. 2009
 by Tom Igoe

 */

#include <Stepper.h>

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
const int speedDelay = 1;
boolean buttonState = LOW;

const int buttonPinPositive = 2;    
const int buttonPinNegative =  3;      
// for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 4, 5, 6, 7);

void setup() {
  // set the speed at 60 rpm:
  myStepper.setSpeed(60);
  // initialize the serial port:
  Serial.begin(9600);
  pinMode(buttonPinPositive , OUTPUT);
  pinMode(buttonPinNegative , INPUT);
runMotorForward();
}

void loop() {

}
boolean readButtonState () {
  digitalWrite(buttonPinPositive, HIGH);
  return digitalRead(buttonPinNegative);
  }
void runMotorBackward() {
  for (int stepCount=0;stepCount <= 44 ;stepCount++ ) {
        // step one step:
  myStepper.step(750);
  Serial.print("steps:");
  Serial.println(stepCount);
  delay(speedDelay);
    }
  }
void runMotorForward () {
  for (int stepCount=0;stepCount <= 44 ;stepCount++ ) {
        // step one step:
  myStepper.step(-750);
  Serial.print("steps:");
  Serial.println(stepCount);
  delay(speedDelay);
    }
  }
