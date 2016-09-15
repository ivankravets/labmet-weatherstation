#include <Arduino.h>
#include "ConnectServer.hpp"
#include <ESP8266WiFi.h>
//#include "Errors.hpp"

// ---------------------Init method--------------------------- //

 ConnectServer::ConnectServer(const char* SSID, const char* PASSWORD,
   const char* HOST, int httpport)
 {
   this->ssid = SSID;
   this->password = PASSWORD;
   this->host = HOST;
   this->httpPort = httpport;
}
// ---------------------Public mtd--------------------------- //

void ConnectServer::begin()
{
  Serial.println(CONN_WIFI);
  Serial.println(WiFi.status());

  if (WiFi.status() == WL_CONNECTED)
      return;

  WiFi.begin(this->ssid, this->password);
  delay(500);

  Serial.print(WiFi.status());
  Serial.println(CHECK_WIFI);
  Serial.println("WiFi connected");
  Serial.println("IP obtido: ");
  Serial.println(WiFi.localIP());
}
// --------------------------------------------------------- //
bool ConnectServer::postPage(String dados, String endpoint) {

  uint8_t statusCodePost = 0, sendCode;
  uint8_t contentLength =  dados.length();

  String header = String("POST ") + endpoint +  " HTTP/1.1\r\n" +
                  "Host: 192.168.1.157\r\n" +
                  "Content-Type: application/x-www-form-urlencoded\r\n" +
                  "Content-Length: "+  contentLength + "\r\n\r\n" +
                   dados +"\r\nConnection: close\r\n";
  cliente.println(header);

  sendCode = cliente.read();
  checkingSend(sendCode, dados);

  // Read all the lines of the reply from server and print them to Serial
  while(cliente.available())
  {
      String line = cliente.readStringUntil('\r');
      Serial.println(line);
     }

  this->checkStatusCodePost(statusCodePost, dados);
  Serial.println(dados);
}
// --------------------------------------------------------- //
void ConnectServer::checkingSend(int comp, String post)
{
   Serial.println(comp);

    if (comp == 72){
      return;
    }
      else
      cliente.stop();
      this->save_errors(post);
      check_conn_server();

}
void ConnectServer::conn_node_server()
{
  cliente.connect(host, httpPort);
  Serial.println(CONN_SERVER);
  // salvar conexao sd
}
// --------------------------------------------------------- //
void ConnectServer::check_conn_wifi()
{
   if (WiFi.status() == WL_CONNECTED)
      return;

  Serial.println(ERROR_WIFI);
  // salvar erro sd

  begin();
}
// --------------------------------------------------------- //
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
