#include <Arduino.h>
#include "ConnectServer.hpp"
#include <ESP8266WiFi.h>
#include "Errors.hpp"


 ConnectServer::ConnectServer()
 {

 }

void ConnectServer::begin()
{
  Serial.print(CONN_WIFI);
  // salvar conexao sd
  Serial.println(WiFi.status());

  if (WiFi.status() == WL_CONNECTED)
      return;

  WiFi.begin(this->ssid, this->password);
  delay(5000);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(WiFi.status());
    Serial.print(CHECK_WIFI);
  }

  Serial.println("WiFi connected");
  Serial.println("IP obtido: ");
  Serial.println(WiFi.localIP());

}

    Errors error;

bool ConnectServer::postPage(String dados, String endpoints) {

  int statusCodePost=0;

  String ContentLength = "Content-Length: ";

  String envia = "Name=";
  envia += dados;

  // envia += endpoints;

  uint8_t cont =  envia.length();

  ContentLength += cont;

  cliente.println("POST / HTTP/1.1");
  cliente.println("Host: 192.168.1.123" + endpoints);
  cliente.println("Content-Type: application/x-www-form-urlencoded");
  cliente.println(ContentLength);
  cliente.println("");
  cliente.println(envia);

  int c = cliente.read();
  checkingSend(c, envia);

  // Read all the lines of the reply from server and print them to Serial
  while(cliente.available()){
      String line = cliente.readStringUntil('\r');
      Serial.println(line);
     }

  error.checkStatusCodePost(statusCodePost, envia);

  Serial.println(envia);
  cliente.stop();
}

void ConnectServer::checkingSend(int comp, String post)
{

   Serial.println(comp);

    if (comp == 72){
      return;
    }
      else
      error.save(post);
      check_conn_server();

}
void ConnectServer::conn_node_server()
{
  cliente.connect(host, httpPort);
  Serial.println(CONN_SERVER);
  // salvar conexao sd
}

void ConnectServer::check_conn_wifi()
{
   if (WiFi.status() == WL_CONNECTED)
      return;

  Serial.println(ERROR_WIFI);
  // salvar erro sd

  begin();
}

void ConnectServer::check_conn_server()
{
  if (cliente.available()) {
    return;
  }

  if (!cliente.connect(host, httpPort)){
    Serial.println(ERROR_SERVER);
    // salvar erro sd
    cliente.stop();
    delay(5000);
    conn_node_server();
      }
}
