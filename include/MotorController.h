#ifndef MOTOR_CONTROLLER_H
#define MOTOR_CONTROLLER_H

#include <Arduino.h>

class MotorController {
public:
  void init();
  void update();
  void moveForward(int speed = 255);
  void moveBackward(int speed = 255);
  void turnLeft(int speed = 200);
  void turnRight(int speed = 200);
  void stop();
  
private:
  const int IN1 = 14;
  const int IN2 = 12;
  const int IN3 = 13;
  const int IN4 = 15;
  const int ENA = 16;
  const int ENB = 17;
  
  int currentSpeed = 0;
  char currentDirection = 'S';
};

#endif