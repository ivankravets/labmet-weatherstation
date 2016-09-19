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


void WiFiConn::checkWiFi()
{

}

// -------------------------------------------------------------------------- //


void WiFiConn::reconect()
{

}

// -------------------------Private methods---------------------------------- //

void WiFiConn::connect()
{
  if(debuging)
  {
    printformat("Trying to connect to %s, status: %d\n",
    this->ssid, WiFi.status());
  }
  if (WiFi.status() == WL_CONNECTED)
      return;

  WiFi.begin(this->ssid, this->password);
  delay(500);

  Serial.println("WiFi connected");
  Serial.println("Node local IP: ");
  Serial.println(WiFi.localIP());

}

// -------------------------End of class implementation---------------------- //
