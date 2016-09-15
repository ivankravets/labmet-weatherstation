#ifndef MQTTCLIENT_HPP
#define  MQTTCLIENT_HPP

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <PubSubClient.h>
#include "ConnectServer.hpp"

#define CONNECT_BROKER "Tentando se conectar ao Broker MQTT: "
#define CONNECT_BROKER_START "Conectado com sucesso ao broker MQTT!"
#define CONNECT_BROKER_FOUND "Falha ao reconectar no broker."
#define CONNECT_BROKER_FOUND2 "Havera nova tentatica de conexao em 2s"
#define TOPICO_SUBSCRIBE "MQTT envia"
#define TOPICO_PUBLISH   "MQTT recebe"
#define ID_MQTT  "NodeMCU01"

void mqtt_callback(char* topic, byte* payload, unsigned int length);

class MQTTClient
{
public:
  MQTTClient(const char* broker_mqtt, int broker_port);
  void initMQTT();
  void checkingWiFIeMQTT();
  void reconnectMQTT();

private:
  PubSubClient MQTTLocal;
  char exit;
  const char* brokermqtt;
  int brokerport;

};

#endif
