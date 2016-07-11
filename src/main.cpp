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
#include "SDCard.hpp"
// -----------------------------------------------//

DHT dht22(5, DHT22);
LiquidCrystal_I2C lcd(0x3f,2,1,0,4,5,6,7,3, POSITIVE);
SDCard sd(6, 7, 4);
StationRtc rtc;

ClimateDataLogger climate(dht22, lcd, sd, rtc);


void setup()
{

Serial.begin(9600);
rtc.begin();
sd.begin();
climate.begin();
}
// -----------------------------------------------//

void loop()
{
  Serial.print("Temeperatura: ");
  Serial.print(climate.readTemp());
  Serial.print(" Umidade: ");
  Serial.print(climate.readHum());
  Serial.print(" data: ");
  Serial.println(rtc.dateTimeNow());
  sd.blockedLed();
  sd.logData(rtc.dateTimeNow(), climate.readHum(), climate.readTemp());
  delay(500);
}

// -----------------------------------------------//
