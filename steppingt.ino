#include <Stepper.h>
#include <Servo.h>

#define STEPS1_PIN 5
#define DIR1_PIN 6
#define MS1_1_PIN 8
#define MS2_1_PIN 9
#define MS3_1_PIN 10

#define STEPS2_PIN 23
#define DIR2_PIN 22
#define MS1_2_PIN 24
#define MS2_2_PIN 25
#define MS3_2_PIN 26

#define GRIPPER_PIN 2

unsigned int steps1 = 6400;
unsigned int speed1 = 50;
unsigned int direction1 = 1;

unsigned int steps2 = 6400;
unsigned int speed2 = 50;
unsigned int direction2 = 0;

Servo gripper;

void setup() {
  Serial.begin(9600);
  
  pinMode(STEPS1_PIN, OUTPUT);
  pinMode(DIR1_PIN, OUTPUT);
  pinMode(MS1_1_PIN, OUTPUT);
  pinMode(MS2_1_PIN, OUTPUT);
  pinMode(MS3_1_PIN, OUTPUT);
  
  digitalWrite(MS1_1_PIN, HIGH);
  digitalWrite(MS2_1_PIN, HIGH);
  digitalWrite(MS3_1_PIN, HIGH);

  pinMode(STEPS2_PIN, OUTPUT);
  pinMode(DIR2_PIN, OUTPUT);
  pinMode(MS1_2_PIN, OUTPUT);
  pinMode(MS2_2_PIN, OUTPUT);
  pinMode(MS3_2_PIN, OUTPUT);
  
  digitalWrite(MS1_2_PIN, HIGH);
  digitalWrite(MS2_2_PIN, HIGH);
  digitalWrite(MS3_2_PIN, HIGH);

  gripper.attach(GRIPPER_PIN);
}

void loop() {
  gripper.write(0); // Adjust angle as needed to close the gripper
  delay(1000); // Wait for gripper to close

  moveMotor(STEPS1_PIN, DIR1_PIN, steps1, speed1, direction1);
  moveMotor(STEPS2_PIN, DIR2_PIN, steps2, speed2, direction2);

  gripper.write(90); // Adjust angle as needed to open the gripper
  delay(1000); // Wait for gripper to open

  moveMotor(STEPS1_PIN, DIR1_PIN, steps1, speed1, !direction1);
  moveMotor(STEPS2_PIN, DIR2_PIN, steps2, speed2, !direction2);
}

void moveMotor(int stepsPin, int dirPin, unsigned int steps, unsigned int speed, unsigned int direction) {
  digitalWrite(dirPin, direction);
  for (unsigned int i = 0; i < steps; i++) {
    digitalWrite(stepsPin, HIGH);
    delayMicroseconds(speed);
    digitalWrite(stepsPin, LOW);
    delayMicroseconds(speed);
  }
}
