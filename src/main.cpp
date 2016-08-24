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
#include "PressureSensor.hpp"
#include <ESP8266WiFi.h>
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

PressureSensor pressureSensor(bmp180, 5);
void setup()
{

Serial.begin(115200);
climate.begin();
pressureSensor.begin();

}
// -----------------------------------------------//

void loop()
{
  delay(100);
  climate.save();
  pressureSensor.getTemperature();
  pressureSensor.getPressure(2);
  pressureSensor.getAltitude();
}

// -----------------------------------------------//
