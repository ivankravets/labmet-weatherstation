/*BrokerClient
    __  _       _      ___   ___  _  _    __
  / / | | __ _| |__  ( _ ) / _ \| || |   \ \
/ /   | |/ _` | '_ \ / _ \| | | | || |_   \ \
\ \   | | (_| | |_) | (_) | |_| |__   _|  / /
 \_\  |_|\__,_|_.__/ \___/ \___/   |_|   /_/

Interface of the MQTT broker client

Created by: Barbara Panosso and João Trevizoli Esteves
*/

#ifndef BROKERCLIENT_HPP
#define  BROKERCLIENT_HPP

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <PubSubClient.h>
#include "WiFiConn.hpp"
#include "Format.h"

// -------------------------Debug Directives--------------------------------- //

#define BROKER_CLIENT_DEBUG 1

// -------------------------Defines------------------------------------------ //

#define ID_NODEMCU  "NodeMCU02"

// -------------------------Callback functions interface--------------------- //

void mqtt_callback(char* topic, byte* payload, unsigned int length);

// -------------------------Class Interface---------------------------------- //

class BrokerClient
{
public:
  BrokerClient(PubSubClient broker, const char* HOST, int port,
    const char* brokerSsid, const char* brokerPassword);
  void begin();
  bool checkBroker();
  void connectBroker(uint16_t delayTime = 5000);
  String getMACAddr();
  String macToStr(const uint8_t* mac);
  void sendMsg(String topic, String str);

private:
  PubSubClient BrokerCl;
  const char* ssidBroker;
  const char* passwordBroker;
  const char* brokermqtt;
  int brokerport;
};

#endif
