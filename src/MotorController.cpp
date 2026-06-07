#include "MotorController.h"

void MotorController::init() {
  pinMode(Left, OUTPUT);
  pinMode(Right, OUTPUT);
  pinMode(Forward, OUTPUT);
  pinMode(Backward, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  
  stop();
}

void MotorController::update() {
}

void MotorController::moveForward(int speed) {
  currentSpeed = speed;
  currentDirection = 'F';
  
  digitalWrite(Forward, HIGH);
  digitalWrite(Backward, LOW);
  
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
}

void MotorController::moveBackward(int speed) {
  currentSpeed = speed;
  currentDirection = 'B';
  
  digitalWrite(Forward, LOW);
  digitalWrite(Backward, HIGH);
  
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
}

void MotorController::turnLeft(int speed) {
  currentSpeed = speed;
  currentDirection = 'L';
  
  digitalWrite(Left, HIGH);
  digitalWrite(Right, LOW);

  
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
}

void MotorController::turnRight(int speed) {
  currentSpeed = speed;
  currentDirection = 'R';
  
  digitalWrite(Left, LOW);
  digitalWrite(Right, HIGH);
  
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
}

void MotorController::stop() {
  currentSpeed = 0;
  currentDirection = 'S';
  
  digitalWrite(Left, LOW);
  digitalWrite(Right, LOW);
  digitalWrite(Forward, LOW);
  digitalWrite(Backward, LOW);
  
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}