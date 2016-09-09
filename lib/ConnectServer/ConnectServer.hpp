
#include <ESP8266WiFi.h>
#include <Format.h>
#include <Errors.hpp>

#ifndef CONNECTSERVER_HPP
#define CONNECTSERVER_HPP

#define CONN_SERVER  "Connecting Server"
#define CONN_WIFI "Connecting WiFi"
#define ERROR_WIFI "Error: Connecting to WiFi Failed"
#define ERROR_SERVER "Error: Connection to Server Failed"
#define CHECK_WIFI "Connection Checking"


#define ERROR_STRING "Error: String type"
#define ERROR_POST "Error: POST Failed"

class ConnectServer: public Errors
{
public:
  ConnectServer(const char* SSID, const char* PASSWORD, const char* HOST,
    const int httpport,uint32_t updateInterval, int oversampling,
    bool errorPrinting);
  void begin();
  void check_conn_wifi();
  void conn_node_server();
  void check_conn_server();
  void checkingSend(int retorn, String post);
  bool postPage(String dados, String endpoint);


private:
  const char* ssid = "LAB804";
  const char* password = "l4b804!@";
  const char* host = "192.168.1.168";
  const int httpPort = 5000;
  WiFiClient cliente;
  uint32_t updateInterval;
  uint32_t previousUpdate;
  int oversampling;
  bool errorPrinting;
};

#endif
