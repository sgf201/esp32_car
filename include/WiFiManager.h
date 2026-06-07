#ifndef WIFI_MANAGER_H
#define WIFI_MANAGER_H

#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClient.h>

class WiFiManager {
public:
  WiFiManager();
  void init();
  void handleClient();
  
private:
  WiFiServer server;
  WiFiClient client;
  
  void processCommand(char cmd);
  void sendResponse(const String& response);
};

#endif