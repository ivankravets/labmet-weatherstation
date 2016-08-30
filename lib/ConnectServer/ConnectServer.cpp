#include <Arduino.h>
#include "ConnectServer.hpp"
#include <ESP8266WiFi.h>
#include <string.h>

 ConnectServer::ConnectServer()
 {

 }

void ConnectServer::begin()
{
  Serial.print("Connecting wifi..");
  Serial.println(WiFi.status());

  if (WiFi.status() == WL_CONNECTED)
      return;

  WiFi.begin(this->ssid, this->password);
  delay(5000);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(WiFi.status());
    Serial.print("Connection checking!");
  }

  Serial.println("WiFi connected");
  Serial.println("IP obtido: ");
  Serial.println(WiFi.localIP());

}

/*
Metodo mutcho loko
*/
void ConnectServer::postPage(String dados, String endpoints) {

  String ContentLength = "Content-Length: ";

  uint8_t cont =  dados.length();

  ContentLength += cont;

  cliente.println("POST / HTTP/1.1");
  cliente.println("Host: 192.168.1.158");
  cliente.println("Content-Type: application/x-www-form-urlencoded");
  cliente.println(ContentLength);
  cliente.println("");
  cliente.println(dados);
  cliente.println(endpoints);
  Serial.println(dados);
  cliente.stop();

}

void ConnectServer::conn_node_server()
{
  cliente.connect(host, httpPort);
  Serial.println("Connecting server");
}

void ConnectServer::check_conn_wifi()
{
   if (WiFi.status() == WL_CONNECTED)
      return;
   begin();
}

void ConnectServer::check_conn_server()
{
  if (cliente.available()) {
    return;
  }

  if (!cliente.connect(host, httpPort)){
    Serial.println("Disconnecting / Connection failed");
    cliente.stop();
    delay(5000);
    conn_node_server();
      }
}
