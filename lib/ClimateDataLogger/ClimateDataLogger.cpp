/* DHT 22 sensor
    __ _       _      ___   ___  _  _    __
  / / | | __ _| |__  ( _ ) / _ \| || |   \ \
/ /   | |/ _` | '_ \ / _ \| | | | || |_   \ \
\ \   | | (_| | |_) | (_) | |_| |__   _|  / /
 \_\  |_|\__,_|_.__/ \___/ \___/   |_|   /_/

Implementation of the climate datalogger object

*/

#include "ClimateDataLogger.hpp"

ClimateDataLogger::ClimateDataLogger(DHT& dht22, LiquidCrystal_I2C& lcdS):
  dht(dht22),
  lcd(lcdS)
{

}

// -----------------------------------------------//

void ClimateDataLogger::begin()
{
  this->dht.begin();
  this->lcd.begin(16, 2);
  this->lcd.clear();
}

// -----------------------------------------------//

float ClimateDataLogger::readTemp()
{
  float temp = this->dht.readTemperature();
  this->lcd.setCursor(0, 0);
  if (this->lastTemp > temp)
  {
    for (size_t i = 0; i < 16; i++)
    {
      this->lcd.print(" ");
    }
    this->lcd.setCursor(0, 0);
  }
  this->lcd.print(temp);
  this->lcd.print(" *C");
  this->lastTemp = temp;
  return temp;
}

// -----------------------------------------------//

float ClimateDataLogger::readHum()
{
  float humid = this->dht.readHumidity();
  this->lcd.setCursor(0, 1);
  if (this->lastHumid > humid)
  {
    for (size_t i = 0; i < 16; i++)
    {
      lcd.print(" ");
    }
    lcd.setCursor(0, 1);
  }
  this->lcd.print(humid);
  this->lcd.print(" %");
  this->lastHumid = humid;
  return humid;
}
