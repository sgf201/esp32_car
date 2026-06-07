#include <Arduino.h>
#include "MotorController.h"

#define PROTOCOL_START "@#"
#define PROTOCOL_END "#@"

MotorController motorController;
String serialBuffer = "";

void setup() {
  Serial.begin(115200);
  motorController.init();
  Serial.println("ESP32 Car initialized");
  Serial.println("Waiting for gesture commands...");
}

void processGesture(const String& gesture) {
  if (gesture.equalsIgnoreCase("gun")) {
    motorController.moveForward();
    Serial.println("[CMD] Forward");
  } else if (gesture.equalsIgnoreCase("five")) {
    motorController.stop();
    Serial.println("[CMD] Stop");
  } else if (gesture.equalsIgnoreCase("six")) {
    motorController.moveBackward();
    Serial.println("[CMD] Backward");
  } else {
    Serial.print("[CMD] Unknown gesture: ");
    Serial.println(gesture);
  }
}

void loop() {
  while (Serial.available() > 0) {
    char c = Serial.read();
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