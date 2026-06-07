#include <Arduino.h>
#include "MotorController.h"

#define PROTOCOL_START "@#"
#define PROTOCOL_END "#@"

MotorController motorController;
String serialBuffer = "";

HardwareSerial Serial0(0);

void setup() {
  Serial0.begin(115200, SERIAL_8N1, 3, 1);
  motorController.init();
  Serial0.println("ESP32 Car initialized");
  Serial0.println("Using UART0: TX=GPIO1, RX=GPIO3");
  Serial0.println("Waiting for gesture commands...");
}

void processGesture(const String& gesture) {
  if (gesture.equalsIgnoreCase("gun")) {
    motorController.moveForward();
    Serial0.println("[CMD] Forward");
  } else if (gesture.equalsIgnoreCase("five")) {
    motorController.stop();
    Serial0.println("[CMD] Stop");
  } else if (gesture.equalsIgnoreCase("six")) {
    motorController.moveBackward();
    Serial0.println("[CMD] Backward");
  } else if (gesture.equalsIgnoreCase("one")) {
    motorController.turnLeft();
    Serial0.println("[CMD] Backward");
  } else if (gesture.equalsIgnoreCase("fist")) {
    motorController.turnRight();
    Serial0.println("[CMD] Backward");
  } else {
    Serial0.print("[CMD] Unknown gesture: ");
    Serial0.println(gesture);
  }
}

void loop() {
  while (Serial0.available() > 0) {
    char c = Serial0.read();
    serialBuffer += c;
    
    int startIdx = serialBuffer.indexOf(PROTOCOL_START);
    if (startIdx >= 0) {
      int endIdx = serialBuffer.indexOf(PROTOCOL_END, startIdx + strlen(PROTOCOL_START));
      if (endIdx >= 0) {
        String cmd = serialBuffer.substring(startIdx + strlen(PROTOCOL_START), endIdx);
        cmd.trim();
        
        if (cmd.length() > 0) {
          processGesture(cmd);
        }
        
        serialBuffer = serialBuffer.substring(endIdx + strlen(PROTOCOL_END));
      }
    }
    
    if (serialBuffer.length() > 256) {
      serialBuffer = "";
    }
  }
  
  motorController.update();
  delay(10);
}