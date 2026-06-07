#ifndef MOTOR_CONTROLLER_H
#define MOTOR_CONTROLLER_H

#include <Arduino.h>
#define PIN_L 2
#define PIN_R 4
#define PIN_F 15
#define PIN_B 5

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
  const int Left = PIN_L;
  const int Right = PIN_R;  
  const int Forward = PIN_F;
  const int Backward = PIN_B;
  const int ENA = 16;
  const int ENB = 17;

  
  int currentSpeed = 0;
  char currentDirection = 'S';
};

#endif