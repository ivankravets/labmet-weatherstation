
#include <ESP8266WiFi.h>

#ifndef CONNECTSERVER_HPP
#define CONNECTSERVER_HPP

class ConnectServer
{
public:
  ConnectServer();
  void begin();
  void check_conn_wifi();
  void conn_node_server();
  void check_conn_server();
  void postPage(String dados, String endpoint);


private:
  const char* ssid = "LAB804";
  const char* password = "l4b804!@";
  const char* host = "192.168.1.123";
  const int httpPort = 5000;
  WiFiClient cliente;
};

#endif
