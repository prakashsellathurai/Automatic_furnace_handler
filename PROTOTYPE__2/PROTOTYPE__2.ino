
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
boolean buttonState;

const int LED_PIN = 0;    
const int buttonPinNegative =  3;      
// for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 4, 5, 6, 7);

void setup() {
  // set the speed at 60 rpm:
  myStepper.setSpeed(60);
  // initialize the serial port:
  Serial.begin(9600);
  pinMode(LED_PIN , OUTPUT);
  pinMode(buttonPinNegative , INPUT);
    digitalWrite(LED_PIN, HIGH);
    delay(10000);
}

void loop() {
  delay(1000);
doAction();
delay(500);
}
void doAction () {
  
  runMotorForward ();
  runMotorBackward();
  }
  void pingPong()
{
 int delayTime = 35;
    digitalWrite(LED_PIN, HIGH);
    delay(delayTime);
    digitalWrite(LED_PIN, LOW);
     delay(delayTime);
}
boolean readButtonState () {

  return (digitalRead(buttonPinNegative) == LOW) ? 0 : 1;
  }
void runMotorBackward() {
  for (int stepCount=0;stepCount <= 44 ;stepCount++ ) {
        // step one step:
          pingPong();
  myStepper.step(750);
  Serial.print("steps:");
  Serial.println(stepCount);
  delay(speedDelay);

    }
  }
void runMotorForward () {
  for (int stepCount=0;stepCount <= 44 ;stepCount++ ) {
        // step one step:
         pingPong();
  myStepper.step(-750);
  Serial.print("steps:");
  Serial.println(stepCount);
  delay(speedDelay);
 
    }
  }
