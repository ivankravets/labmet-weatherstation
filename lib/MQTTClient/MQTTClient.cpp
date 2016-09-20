#include "MQTTClient.hpp"

MQTTClient::MQTTClient(const char* HOST, int httpport)
{
  this->ssid = "NodeMCU01";
  this->password = "123456";
  this->brokermqtt = HOST;
  this->brokerport = httpport;
}
// -------------------------------------------------------------------------- //

void MQTTClient::initMQTT()
{
    MQTTLocal.setServer(brokermqtt, brokerport);
    MQTTLocal.setCallback(mqtt_callback);
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

void MQTTClient::connectMQTT()
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

void MQTTClient::sendMsg(){

  long now = millis();
  if (now - lastMsg > 2000) {
    lastMsg = now;
    ++value;
    snprintf (msg, 75, "%ld", value);
    Serial.print("Publish message: ");
    Serial.println(msg);
    MQTTLocal.publish("msg", msg);
  }
}
// -------------------------------------------------------------------------- //

void MQTTClient::checkWiFIeMQTT()
{
    if (MQTTLocal.connected())
      return;

      else
        Serial.println(CONNECT_BROKER_FOUND);
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
