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


ClimateDataLogger climate(dht22, lcd);
StationRtc rtc;
SDCard sd(6, 7, 4);

void setup()
{

Serial.begin(9600);
climate.begin();
rtc.begin();
sd.begin();
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
  delay(500);
}

// -----------------------------------------------//
