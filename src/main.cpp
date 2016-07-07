/* Joaquim controler
  __  _       _      ___   ___  _  _    __
 / / | | __ _| |__  ( _ ) / _ \| || |   \ \
/ /  | |/ _` | '_ \ / _ \| | | | || |_   \ \
\ \  | | (_| | |_) | (_) | |_| |__   _|  / /
 \_\ |_|\__,_|_.__/ \___/ \___/   |_|   /_/

*/

#include <Arduino.h>
#include "ClimateDataLogger.hpp"
// -----------------------------------------------//

DHT dht22(10, DHT22);

ClimateDataLogger climate(13, 12, dht22);

void setup()
{
Serial.begin(9600);
climate.begin();
}
// -----------------------------------------------//

void loop()
{
  climate.savingLed();
  delay(500);
  climate.blockedLed();
  delay(500);
  Serial.println(climate.readTemp());
  Serial.println(climate.readHum());
}

// -----------------------------------------------//
