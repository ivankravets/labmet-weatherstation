/*WiFiConn
    __  _       _      ___   ___  _  _    __
  / / | | __ _| |__  ( _ ) / _ \| || |   \ \
/ /   | |/ _` | '_ \ / _ \| | | | || |_   \ \
\ \   | | (_| | |_) | (_) | |_| |__   _|  / /
 \_\  |_|\__,_|_.__/ \___/ \___/   |_|   /_/

Interface of the WiFiConn Sensor object

This object is responsable for facilitating the management
of the the wifi connection.

Created by: Joao Trevizoli Esteves
*/

#ifndef WIFICONN_HPP
#define  WIFICONN_HPP

#include <ESP8266WiFi.h>
#include <Errors.hpp>
#include "Format.h"

class WiFiConn: public Errors
{
public:
  IPAddress clientLocalIp;
  WiFiConn(const char* SSID, const char* Password, bool debuging=true);
  void begin();
  bool checkWiFi();
  void localIpChange();

private:
  void connect();
  const uint32_t ipChangeUpdateInterval = 5000;
  uint32_t previousUpdate = 0;
  const char* ssid;
  const char* password;
  bool debuging;


};



#endif
