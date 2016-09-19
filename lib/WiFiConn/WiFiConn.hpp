#ifndef WIFICONN_HPP
#define  WIFICONN_HPP

#include <ESP8266WiFi.h>
#include <Errors.hpp>


class WiFiConn: public Errors
{
public:
  WiFiConn(const char* SSID, const char* Password);
  void begin();
  void checkWiFi();
  void reconect();

private:  
char* ssid;
char* password;
};



#endif
