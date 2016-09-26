/* Labmet datalogger main
  __  _       _      ___   ___  _  _    __
 / / | | __ _| |__  ( _ ) / _ \| || |   \ \
/ /  | |/ _` | '_ \ / _ \| | | | || |_   \ \
\ \  | | (_| | |_) | (_) | |_| |__   _|  / /
 \_\ |_|\__,_|_.__/ \___/ \___/   |_|   /_/

Created by: the <lab804> Team
*/
#include <Arduino.h>
#include "ClimateDataLogger.hpp"
#include "StationRTC.hpp"
#include "PressureSensor.hpp"
#include "JsonGenerator.hpp"
#include "DS18b20.hpp"
#include "WiFiConn.hpp"
#include "BrokerClient.hpp"
#include "BH1750.hpp"
#include "SoilHumidity.hpp"

// -------------------------defines------------------------------------------ //

#define LCD_ADDR 0X27
#define DHT_PIN D4
#define CHP_CLK_PIN D6
#define GREEN_LED D7
#define RED_LED D8
#define ONE_WIRE_BUS D3

// -------------------------consts------------------------------------------- //

const char* ssid = "LAB804";
const char* password = "l4b804!@";

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

WiFiConn wifi(ssid, password);

WiFiClient wifiClient;
PubSubClient net(wifiClient);
BrokerClient mqtt(net, "192.168.1.125", 1883, 1);

SoilHumidity sh;
// -------------------------setup-------------------------------------------- //

 void setup()
 {
   Serial.begin(115200);
   delay(500);
  //  pressureSensor.begin();
  //  climate.begin();
   delay(500);
   wifi.begin();
   delay (500);
   mqtt.begin();
  //  ds18b20.begin();

 }

// -------------------------loop--------------------------------------------- //

 void loop()
 {
  // Serial.println(bh1750.readIlluminanceLevel())

  // climate_data_t collectedData;

  // rtc.dateTimeNow().toCharArray(collectedData.date, 20);
  // collectedData.bmp180Temp = 12;
  // collectedData.bmp180Alt =34;
  // collectedData.bmp180Press =56;
  // collectedData.ds18b20Temp =78;
  // collectedData.dht22Temp =91;
  // collectedData.dht22Humid =11;
  //
  // rtc.dateTimeNow().toCharArray(collectedData.date, 20);
  // collectedData.bmp180Temp = pressureSensor.getTemperature();
  // collectedData.bmp180Alt = pressureSensor.getAltitude();
  // collectedData.bmp180Press = pressureSensor.getPressure();
  // collectedData.ds18b20Temp = ds18b20.getTemperature();
  // collectedData.dht22Temp = climate.readTemp();
  // collectedData.dht22Humid = climate.readHum();
  //
  // JsonGenerator *json = new JsonGenerator(collectedData);
  // //String payload = "hauhuhauahuahuahauhauhauhahaauh";
  // String payload = json->writeResponseToSerial();
  // Serial.println(payload);
  // delete json;
  // climate.save();
  // net.loop();
  // mqtt.sendMsg("msg", payload);
  //  delay(1000);
  sh.getSoilHumidity();
  // wifi.checkWiFi();
  delay(500);

  }

// -------------------------end of main-------------------------------------- //
