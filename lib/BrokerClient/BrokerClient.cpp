#include "BrokerClient.hpp"

BrokerClient::BrokerClient(PubSubClient broker, const char* HOST, int httpport,
  bool debuging):
BrokerCl(broker)
{
  this->ssidBroker= "NodeMCU";
  this->passwordBroker = "123456";
  this->brokermqtt = HOST;
  this->brokerport = httpport;
  this->debuging =  debuging;
}
// -------------------------------------------------------------------------- //

void BrokerClient::begin()
{
    delay(500);
    BrokerCl.setServer(brokermqtt, brokerport);
    BrokerCl.setCallback(mqtt_callback);
    this->connectBroker();
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

void BrokerClient::connectBroker()
{
    while (!BrokerCl.connected())
    {
      if (debuging){
        Serial.println(CONNECT_BROKER);
        Serial.println(brokermqtt);
        }

        if (BrokerCl.connect(ID_NODEMCU, ssidBroker , passwordBroker))
        {
          if (debuging){
            Serial.println(CONNECT_BROKER_START);
            }
            BrokerCl.publish("debug", TOPICO_PUBLISH);
            BrokerCl.subscribe(TOPICO_SUBSCRIBE);
        }else{
          if (debuging){
            Serial.println(CONNECT_BROKER_FOUND);
            Serial.println("failed, rc=");
            Serial.print(BrokerCl.state());
            Serial.println(CONNECT_BROKER_FOUND2);
            }
            delay(5000);
            }
    }
}
// -------------------------------------------------------------------------- //

void BrokerClient::sendMsg(String topic,  String str)
{
   BrokerCl.loop();

  if(checkBroker())
  {
    if (debuging){
        Serial.print("Publish message: ");
        Serial.println(str);
      }
      const char* json = str.c_str();
      const char* topicJson = topic.c_str();

    BrokerCl.publish(topicJson, json);
  }
  else {
    if (debuging){
      Serial.println(CONNECT_BROKER_FOUND);
      }
    this->connectBroker();
        }
}

// -------------------------------------------------------------------------- //

bool BrokerClient::checkBroker()
{
    if (BrokerCl.connected()){
      return true;
    }
      else{
        return false;
      }
}
// -------------------------------------------------------------------------- //

String BrokerClient::printMAC() {

   String clientMac = "";
   unsigned char mac[6];

   // print your MAC address:
   WiFi.macAddress(mac);
       delay(10000);
   clientMac += macToStr(mac);
   if (debuging){
   Serial.print("MAC address: ");
     Serial.print(clientMac);
   }
     return clientMac;
  }
// -------------------------------------------------------------------------- //

String BrokerClient::macToStr(const uint8_t* mac){

  String strmac;
  for (int i = 0; i < 6; ++i) {
    strmac += String(mac[i], 16);
                  if (i < 5){
                    strmac += ':';
                  }
      }
    return strmac;
  }
