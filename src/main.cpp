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
StationRtc rtc;

ClimateDataLogger climate(dht22, lcd, rtc, 4, 6, 7);


void setup()
{

Serial.begin(9600);
climate.begin();
}
// -----------------------------------------------//

void loop()
{

  climate.save();
}

// -----------------------------------------------//
