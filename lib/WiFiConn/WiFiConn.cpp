#include "WiFiConn.hpp"


// -------------------------Init method-------------------------------------- //

WiFiConn::WiFiConn(const char* SSID, const char* Password, bool debuging)
{
  this->ssid = SSID;
  this->password = Password;
  this->debuging = debuging;
  // this->reconnectTimeOut = reconnectTimeOut;
  // this->temporaryReconnectTimeOut = reconnectTimeOut;
  // this->previousUpdate = 0;

}

// -------------------------Public methods----------------------------------- //

void WiFiConn::begin()
{
  this->connect();
}

// -------------------------------------------------------------------------- //


bool WiFiConn::checkWiFi()
{
  if(WiFi.status() == WL_CONNECTED)
  {
    return true;
  }
  else
  {
    // if (millis() - this->previousUpdate > this->temporaryReconnectTimeOut)
    // {
    //   this->attempts++;
    //   this->previousUpdate = millis();
    //   temporaryReconnectTimeOut = this->reconnectTimeOut;
    //   this->reconect();
    // }
  }
}

// -------------------------------------------------------------------------- //


// void WiFiConn::reconect()
// {
//   if(debuging)
//   {
//     printformat("Trying to reconnect to %s\n", this->ssid);
//     if (WiFi.status() == WL_CONNECTED)
//     {
//       Serial.print("WiFi connected!\n IP: ");
//       Serial.println(WiFi.localIP());
//       return;
//     }
//   }
//   WiFi.begin(this->ssid, this->password);
//   delay(500);
//   if (WiFi.status() == WL_CONNECTED)
//   {
//     this->attempts = 0;
//     if (debuging)
//       printformat("Reconnected to %s\n", this->ssid);
//   }
//   else if(this->attempts == 3)
//   {
//
//     uint32_t maximumAttempsTime = 5 * this->reconnectTimeOut;
//
//     this->attempts = 0;
//
//     this->temporaryReconnectTimeOut = maximumAttempsTime;
//     if (debuging)
//       printformat("Reached maximum attempts when trying to connect to the wifi,\
// trying again in %d seconds", maximumAttempsTime/1000);
//   }
//
// }

// -------------------------Private methods---------------------------------- //

void WiFiConn::connect()
{
  if(debuging)
  {
    printformat("Trying to connect to %s\n", this->ssid);
    if (WiFi.status() == WL_CONNECTED)
    {
      Serial.print("WiFi connected!\n IP: ");
      Serial.println(WiFi.localIP());
      return;
    }
  }

  if (WiFi.status() == WL_CONNECTED)
      return;

  WiFi.begin(this->ssid, this->password);
  delay(1000);

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
