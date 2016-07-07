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
LiquidCrystal_I2C lcd(0x3f,2,1,0,4,5,6,7,3, POSITIVE);


ClimateDataLogger climate(13, 12, dht22, lcd);

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

  Serial.print("Temeperatura: ");
  Serial.print(climate.readTemp());
  Serial.print(" Umidade: ");
  Serial.println(climate.readHum());

}

// -----------------------------------------------//
