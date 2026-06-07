#include "MotorController.h"

void MotorController::init() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  
  stop();
}

void MotorController::update() {
}

void MotorController::moveForward(int speed) {
  currentSpeed = speed;
  currentDirection = 'F';
  
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
}

void MotorController::moveBackward(int speed) {
  currentSpeed = speed;
  currentDirection = 'B';
  
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
}

void MotorController::turnLeft(int speed) {
  currentSpeed = speed;
  currentDirection = 'L';
  
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
}

void MotorController::turnRight(int speed) {
  currentSpeed = speed;
  currentDirection = 'R';
  
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
}

void MotorController::stop() {
  currentSpeed = 0;
  currentDirection = 'S';
  
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}