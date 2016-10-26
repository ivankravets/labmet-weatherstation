/*WiFiConn
    __  _       _      ___   ___  _  _    __
  / / | | __ _| |__  ( _ ) / _ \| || |   \ \
/ /   | |/ _` | '_ \ / _ \| | | | || |_   \ \
\ \   | | (_| | |_) | (_) | |_| |__   _|  / /
 \_\  |_|\__,_|_.__/ \___/ \___/   |_|   /_/

Implementation of the WiFiConn Sensor object

This object is responsable for facilitating the management
of the the wifi connection.

Created by: Joao Trevizoli Esteves
*/

#include "WiFiConn.hpp"

// -------------------------Init method-------------------------------------- //

WiFiConn::WiFiConn(const char* SSID, const char* Password, bool debuging)
{
  this->ssid = SSID;
  this->password = Password;
  this->debuging = debuging;
}

// -------------------------Public methods----------------------------------- //

void WiFiConn::begin()
{
  this->connect();
}

// -------------------------------------------------------------------------- //


bool WiFiConn::checkWiFi()
{
  if (millis() - this->previousUpdate > this->ipChangeUpdateInterval)
  {
    this->previousUpdate = millis();
    this->localIpChange();
  }
  if(WiFi.status() == WL_CONNECTED)
  {
    return true;
  }
  else
  {
    return false;
  }
}

// -------------------------------------------------------------------------- //

void WiFiConn::localIpChange()
{
  if (clientLocalIp != WiFi.localIP())
  {
    clientLocalIp = WiFi.localIP();
    if (debuging)
    {
      Serial.print("The local IP has changed to ");
      Serial.println(clientLocalIp);
    }
  }
}

// -------------------------Private methods---------------------------------- //

void WiFiConn::connect()
{
  WiFi.begin(this->ssid, this->password);
  delay(1000);
  if(debuging)
  {
    printformat("Trying to connect to %s\n", this->ssid);
    if (WiFi.status() == WL_CONNECTED)
    {
      clientLocalIp = WiFi.localIP();
      Serial.print("WiFi connected!\n IP: ");
      Serial.println(clientLocalIp);
      return;
    }
  }

  if (WiFi.status() == WL_CONNECTED)
      clientLocalIp = WiFi.localIP();
      return;

  if (WiFi.status() == WL_CONNECTED && this->debuging)
  {
    Serial.print("WiFi connected!\n IP: ");
    Serial.println(WiFi.localIP());
  }
  else if (WiFi.status() != WL_CONNECTED)
  {
    printformat("Can't connect to %s\n", this->ssid);
  }
}

// -------------------------End of class implementation---------------------- //
