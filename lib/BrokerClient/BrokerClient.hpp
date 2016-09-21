#ifndef BROKERCLIENT_HPP
#define  BROKERCLIENT_HPP

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <PubSubClient.h>
#include "WiFiConn.hpp"

#define CONNECT_BROKER "Tentando se conectar ao Broker MQTT: "
#define CONNECT_BROKER_START "Conectado com sucesso ao broker MQTT!"
#define CONNECT_BROKER_FOUND "Falha ao reconectar no broker."
#define CONNECT_BROKER_FOUND2 "Havera nova tentatica de conexao em 2s"
#define TOPICO_SUBSCRIBE "Broker envia"
#define TOPICO_PUBLISH   "Broker recebe"
#define ID_NODEMCU  "NodeMCU01"

void mqtt_callback(char* topic, byte* payload, unsigned int length);

class BrokerClient
{
public:
  BrokerClient(PubSubClient broker, const char* HOST, int httpport,
    bool debuging);
  void begin();
  bool checkBroker();
  void connectBroker();
  String printMAC();
  String macToStr(const uint8_t* mac);
  void sendMsg(char* topic, int length, char* str);

private:
  PubSubClient BrokerCl;
  const char* ssidBroker;
  const char* passwordBroker;
  const char* brokermqtt;
  int brokerport;
  int value = 0;
  bool debuging;
};

#endif
