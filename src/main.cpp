/* Labmet datalogger main
  __  _       _      ___   ___  _  _    __
 / / | | __ _| |__  ( _ ) / _ \| || |   \ \
/ /  | |/ _` | '_ \ / _ \| | | | || |_   \ \
\ \  | | (_| | |_) | (_) | |_| |__   _|  / /
 \_\ |_|\__,_|_.__/ \___/ \___/   |_|   /_/

Created by: the <lab804> Team
*/

// -------------------------unit test----------------------------------------- //

#ifndef UNIT_TEST

// -------------------------end of unit test---------------------------------- //

#include <Arduino.h>
#include "ClimateDataLogger.hpp"
#include "StationRTC.hpp"
#include "PressureSensor.hpp"
#include "JsonGenerator.hpp"
#include "DS18b20.hpp"
#include "WiFiConn.hpp"
#include "BrokerClient.hpp"
#include "BH1750.hpp"
#include "SoilMoisture.hpp"

// -------------------------defines------------------------------------------ //

#define LCD_ADDR 0X27
#define DHT_PIN D4
#define CHP_CLK_PIN D6
#define GREEN_LED D7
#define RED_LED D8
#define ONE_WIRE_BUS D3
#define MOISTURE_PIN A0

// -------------------------Debug Directives--------------------------------- //

#define MAIN_DEBUG 1

// -------------------------consts------------------------------------------- //

const char* ssid = "Pi3-AP";
const char* password = "raspberry";
const char* ssidBroker= "NodeMCU";
const char* passwordBroker = "123456";
const char* stationName = "weatherstation";
const uint8_t nodeId = 2;
// -------------------------Object Instatiating------------------------------ //

DHT dht22(DHT_PIN, DHT22);
LiquidCrystal_I2C lcd(LCD_ADDR, 16, 2);

StationRtc rtc;
SFE_BMP180 bmp180;

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature ds18b20Sensor(&oneWire);

ClimateDataLogger climate(dht22, lcd, rtc,
   CHP_CLK_PIN, GREEN_LED, RED_LED);


PressureSensor pressureSensor(bmp180, 1000);

DS18b20 ds18b20(ds18b20Sensor, 500);

BH1750 bh1750;

SoilMoisture sh(MOISTURE_PIN);

WiFiConn wifi(ssid, password);
WiFiClient wifiClient;

PubSubClient net(wifiClient);
BrokerClient mqtt(net, stationName, 1883, ssidBroker, passwordBroker);

// -------------------------setup-------------------------------------------- //

 void setup()
 {
   Serial.begin(115200);
   delay(500);
   pressureSensor.begin();
   bh1750.begin();
   sh.begin();
   climate.begin();
   delay(500);
   wifi.begin();
   ds18b20.begin();
   delay(500);
   mqtt.begin();
 }

// -------------------------loop--------------------------------------------- //

 void loop()
 {
  climate_data_t collectedData;

  rtc.dateTimeNow().toCharArray(collectedData.date, 20);
  collectedData.bmp180Temp = pressureSensor.getTemperature();
  collectedData.bmp180Alt = pressureSensor.getAltitude();
  collectedData.bmp180Press = pressureSensor.getPressure();
  collectedData.ds18b20Temp = ds18b20.getTemperature();
  collectedData.dht22Temp = climate.readTemp();
  collectedData.dht22Humid = climate.readHum();
  collectedData.illuminance = bh1750.readIlluminanceLevel();
  collectedData.soilMoisture = sh.soilHumidityPercent(360, 981);
  collectedData.id = nodeId;

  JsonGenerator *json = new JsonGenerator(collectedData);
  String payload = json->writeResponseToSerial();
  #if MAIN_DEBUG == 1
    Serial.println(payload);
  #endif
  delete json;

  climate.save();
  net.loop();
  mqtt.sendMsg("weather_data", payload);

  wifi.checkWiFi();
  delay(100);

  }

// -------------------------end unit test------------------------------------ //

#endif

// -------------------------end of main-------------------------------------- //
