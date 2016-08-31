/* Joaquim controler
  __  _       _      ___   ___  _  _    __
 / / | | __ _| |__  ( _ ) / _ \| || |   \ \
/ /  | |/ _` | '_ \ / _ \| | | | || |_   \ \
\ \  | | (_| | |_) | (_) | |_| |__   _|  / /
 \_\ |_|\__,_|_.__/ \___/ \___/   |_|   /_/

*/
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "ClimateDataLogger.hpp"
#include "StationRTC.hpp"
#include "PressureSensor.hpp"
#include "ConnectServer.hpp"
#include "Format.h"

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
SFE_BMP180 bmp180;

ClimateDataLogger climate(dht22, lcd, rtc,
   CHP_CLK_PIN, GREEN_LED, RED_LED);

// ConnectServer Conn;
String dados;

PressureSensor pressureSensor(bmp180, 1000);

void setup()
{
  Serial.begin(115200);
  pressureSensor.begin();
  // Conn.begin();
  // Conn.conn_node_server();
  climate.begin();
  delay(500);
}
// -----------------------------------------------//

void loop()
{
  climate.save();
  delay(100);
  pressureSensor.printAll();
  // Conn.check_conn_wifi();
  delay(500);
  // Conn.check_conn_server();
  delay(500);
  dados = "temperature=";
  dados += pressureSensor.getTemperature();
  dados += "&altitude=";
  dados.concat(pressureSensor.getAltitude());
  // Conn.postPage(dados, "/");
  Serial.println(format("teste %d, %f, %c, %s, %s", 10, 3.61, 'b', "Joao", "barbara"));
  delay(1000);
}


// -----------------------------------------------//
