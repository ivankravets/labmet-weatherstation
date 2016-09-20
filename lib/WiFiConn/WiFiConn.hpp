#ifndef WIFICONN_HPP
#define  WIFICONN_HPP

#include <ESP8266WiFi.h>
#include <Errors.hpp>
#include "Format.h"

class WiFiConn: public Errors
{
public:
  WiFiConn(const char* SSID, const char* Password, bool debuging=true);
  void begin();
  bool checkWiFi();
  // void reconect();

private:
  void connect();
  const char* ssid;
  const char* password;
  bool debuging;
  // uint32_t temporaryReconnectTimeOut;
  // uint32_t reconnectTimeOut;
  // uint32_t previousUpdate;
  // uint8_t attempts = 0;

};



#endif
