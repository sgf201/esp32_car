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
  
  //digitalWrite(Forward, HIGH);
  analogWrite(Backward, 0);
    // 使用PWM控制转向引脚的占空比
  analogWrite(Forward, 180);
}

void MotorController::moveBackward(int speed) {
  currentSpeed = speed;
  currentDirection = 'B';
  
  analogWrite(Forward, 0);
 
  // 使用PWM控制转向引脚的占空比
  analogWrite(Backward, 180);
}

void MotorController::turnLeft(int speed) {
  currentSpeed = speed;
  currentDirection = 'L';
  
  digitalWrite(Left, HIGH);
  digitalWrite(Right, LOW);
    //digitalWrite(Forward, HIGH);
  analogWrite(Backward, 0);
    // 使用PWM控制转向引脚的占空比
  analogWrite(Forward, 180);
  
}

void MotorController::turnRight(int speed) {
  currentSpeed = speed;
  currentDirection = 'R';
  digitalWrite(Left, LOW);
  digitalWrite(Right, HIGH);
    //digitalWrite(Forward, HIGH);
  analogWrite(Backward, 0);
    // 使用PWM控制转向引脚的占空比
  analogWrite(Forward, 180);

}

void MotorController::stop() {
  currentSpeed = 0;
  currentDirection = 'S';
  
  digitalWrite(Left, LOW);
  digitalWrite(Right, LOW);   
  analogWrite(Backward, 0);
  analogWrite(Forward, 0);
  
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}