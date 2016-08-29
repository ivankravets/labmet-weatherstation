/* Joaquim controler
  __  _       _      ___   ___  _  _    __
 / / | | __ _| |__  ( _ ) / _ \| || |   \ \
/ /  | |/ _` | '_ \ / _ \| | | | || |_   \ \
\ \  | | (_| | |_) | (_) | |_| |__   _|  / /
 \_\ |_|\__,_|_.__/ \___/ \___/   |_|   /_/

*/
#include <Arduino.h>
#include "ClimateDataLogger.hpp"
#include "StationRTC.hpp"
#include <ESP8266WiFi.h>
#include "ConnectServer.hpp"
#include <string.h>


// -----------------------------------------------//

#define  LCD_ADDR 0X27
#define DHT_PIN D4
#define CHP_CLK_PIN D6
#define GREEN_LED D7
#define RED_LED D8

// -----------------------------------------------//

DHT dht22(DHT_PIN, DHT22);
LiquidCrystal_I2C lcd(LCD_ADDR, 16, 2);

StationRtc rtc;

ClimateDataLogger climate(dht22, lcd, rtc,
   CHP_CLK_PIN, GREEN_LED, RED_LED);


ConnectServer Conn;
String dados = "Name=19/08/2016 13:36:25,25.50,32.40";

void setup()
{
  Serial.begin(115200);
  delay(500);
  Serial.println("\nWiFi begin...");
  Conn.begin();
  delay(500);
  Serial.println("Server begin...");
  Conn.conn_node_server();
  delay(500);
  climate.begin();
  delay(500);
}
// -----------------------------------------------//

void loop()
{
  Serial.println("\nLoooooooooop");
  Conn.check_conn_wifi();
  delay(500);
  Conn.check_conn_server();
  delay(500);
  Conn.postPage(dados, "/");
  delay(10000);

}





// -----------------------------------------------//
