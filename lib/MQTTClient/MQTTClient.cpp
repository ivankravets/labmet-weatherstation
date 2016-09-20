#include "MQTTClient.hpp"

MQTTClient::MQTTClient(const char* HOST, int httpport)
{
  this->brokermqtt = HOST;
  this->brokerport = httpport;

  // ConnectServer wifi(ssid, password, brokermqtt, brokerport);
}
// -------------------------------------------------------------------------- //

void MQTTClient::initMQTT()
{
    MQTTLocal.setServer(brokermqtt, brokerport);   //informa qual broker e porta deve ser conectado
    MQTTLocal.setCallback(mqtt_callback);            //atribui função de callback (função chamada quando qualquer informação de um dos tópicos subescritos chega)
}
// -------------------------------------------------------------------------- //

void mqtt_callback(char* topic, byte* payload, unsigned int length)
{
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");

  String msg;
    //obtem a string do payload recebido
    for(int i = 0; i < length; i++)
    {
       char c = (char)payload[i];
       msg += c;
    }
}
// -------------------------------------------------------------------------- //

void MQTTClient::reconnectMQTT()
{
    while (!MQTTLocal.connected())
    {
        Serial.println(CONNECT_BROKER);
        Serial.println(brokermqtt);
        // wifi.begin();
        if (MQTTLocal.connect(ID_MQTT, ssid , password))
        {
            Serial.println(CONNECT_BROKER_START);
            MQTTLocal.subscribe(TOPICO_SUBSCRIBE);
        }
        else{
            Serial.println(CONNECT_BROKER_FOUND);
            Serial.println(CONNECT_BROKER_FOUND2);
            }
    }
}
// -------------------------------------------------------------------------- //

void MQTTClient::checkingWiFIeMQTT()
{
    if (MQTTLocal.connected())
      return;

      else
        this->reconnectMQTT();
}
// -------------------------------------------------------------------------- //

String MQTTClient::printMAC() {

   String clientMac = "";
   unsigned char mac[6];

   // print your MAC address:
   WiFi.macAddress(mac);
       delay(10000);
   clientMac += macToStr(mac);
   Serial.print("MAC address: ");
     Serial.print(clientMac);
     return clientMac;
  }
// -------------------------------------------------------------------------- //

String MQTTClient::macToStr(const uint8_t* mac){

  String strmac;
  for (int i = 0; i < 6; ++i) {
    strmac += String(mac[i], 16);
                  if (i < 5){
                    strmac += ':';
                  }
      }
    return strmac;
  }
