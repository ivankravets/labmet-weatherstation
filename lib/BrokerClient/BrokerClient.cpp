/*BrokerClient
    __  _       _      ___   ___  _  _    __
  / / | | __ _| |__  ( _ ) / _ \| || |   \ \
/ /   | |/ _` | '_ \ / _ \| | | | || |_   \ \
\ \   | | (_| | |_) | (_) | |_| |__   _|  / /
 \_\  |_|\__,_|_.__/ \___/ \___/   |_|   /_/

Implementation of the MQTT broker client

Created by: Barbara Panosso and João Trevizoli Esteves
*/

#include "BrokerClient.hpp"


// -------------------------Callback functions------------------------------- //

void mqtt_callback(char* topic, byte* payload, unsigned int length)
{
  #if BROKER_CLIENT_DEBUG == 1
    Serial.print("Message arrived [");
    Serial.print(topic);
    Serial.print("] ");
  #endif

  String msg;

  for(int i = 0; i < length; i++)
  {
    char c = (char)payload[i];
    msg += c;
  }
}

// -------------------------Init method-------------------------------------- //

BrokerClient::BrokerClient(PubSubClient broker, const char* HOST,
  int port, const char* brokerSsid, const char* brokerPassword):
BrokerCl(broker)
{
  this->ssidBroker= brokerSsid;
  this->passwordBroker = brokerPassword;
  this->brokermqtt = HOST;
  this->brokerport = port;
}

// -------------------------Public methods----------------------------------- //

void BrokerClient::begin()
{
  delay(500);
  BrokerCl.setServer(brokermqtt, brokerport);
  BrokerCl.setCallback(mqtt_callback);
  this->connectBroker();
}
// -------------------------------------------------------------------------- //


void BrokerClient::connectBroker(uint16_t delayTime)
{
  if (!BrokerCl.connected())
  {
    #if BROKER_CLIENT_DEBUG == 1
      Serial.print("Trying to connect to MQTT Broker: ");
      Serial.println(brokermqtt);
    #endif
    if (BrokerCl.connect(ID_NODEMCU, ssidBroker , passwordBroker))
    {
      #if BROKER_CLIENT_DEBUG == 1
        Serial.println("Connected to Broker!");
      #endif

      BrokerCl.publish("conennected", "NodeMCU01 connected");
    }
    else
    {
      #if BROKER_CLIENT_DEBUG == 1
        printformat("trying again in %d seconds\n", delayTime);
      #endif
      BrokerCl.setServer(brokermqtt, brokerport);
      delay(delayTime);
    }
  }
}
// -------------------------------------------------------------------------- //

void BrokerClient::sendMsg(String topic,  String str)
{
 BrokerCl.loop();

if(checkBroker())
{
  #if BROKER_CLIENT_DEBUG == 1
    Serial.print("Publish message: ");
    Serial.println(str);
  #endif

  const char* json = str.c_str();
  const char* topicJson = topic.c_str();

  #if BROKER_CLIENT_DEBUG == 1
    Serial.print("data: ");
    Serial.println(json);
  #endif
  BrokerCl.publish(topicJson, json, topic.length());
  }
  else
  {
    #if BROKER_CLIENT_DEBUG == 1
      Serial.println("Failed while trying to reconnect to Broker.");
    #endif
    this->connectBroker();
  }
}

// -------------------------------------------------------------------------- //

bool BrokerClient::checkBroker()
{
  if (BrokerCl.connected())
  {
    return true;
  }
  return false;
}
// -------------------------------------------------------------------------- //

String BrokerClient::getMACAddr()
{

 String clientMac = "";
 unsigned char mac[6];
 WiFi.macAddress(mac);
 delay(1000);
 clientMac += macToStr(mac);

 #if BROKER_CLIENT_DEBUG == 1
  Serial.print("MAC address: ");
  Serial.print(clientMac);
 #endif

 return clientMac;
}
// -------------------------------------------------------------------------- //

String BrokerClient::macToStr(const uint8_t* mac)
{
  String strmac;
  for (int i = 0; i < 6; ++i)
  {
    strmac += String(mac[i], 16);
    if (i < 5)
      {
        strmac += ':';
      }
  }
  return strmac;
}
