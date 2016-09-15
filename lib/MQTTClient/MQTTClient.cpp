#include "MQTTClient.hpp"

MQTTClient::MQTTClient(const char* broker_mqtt, int broker_port)
{
  brokermqtt = broker_mqtt;
  brokerport = broker_port;
}

void MQTTClient::initMQTT()
{
    MQTTLocal.setServer(brokermqtt, brokerport);   //informa qual broker e porta deve ser conectado
    MQTTLocal.setCallback(mqtt_callback);            //atribui função de callback (função chamada quando qualquer informação de um dos tópicos subescritos chega)
}

void mqtt_callback(char* topic, byte* payload, unsigned int length)
{
    String msg;
    //obtem a string do payload recebido
    for(int i = 0; i < length; i++)
    {
       char c = (char)payload[i];
       msg += c;
    }
}

void MQTTClient::reconnectMQTT()
{
    while (!MQTTLocal.connected())
    {
        Serial.println(CONNECT_BROKER);
        Serial.println(brokermqtt);
        // conn.ne
        if (MQTTLocal.connect(ID_MQTT))
        {
            Serial.println(CONNECT_BROKER_START);
            MQTTLocal.subscribe(TOPICO_SUBSCRIBE);
        }
        else
        {
            Serial.println(CONNECT_BROKER_FOUND);
            Serial.println(CONNECT_BROKER_FOUND2);
            }
    }
}


void MQTTClient::checkingWiFIeMQTT()
{
    if (MQTTLocal.connected())
      return;

      else
        this->reconnectMQTT();
}
