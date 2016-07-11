/* DHT 22 sensor
    __ _       _      ___   ___  _  _    __
  / / | | __ _| |__  ( _ ) / _ \| || |   \ \
/ /   | |/ _` | '_ \ / _ \| | | | || |_   \ \
\ \   | | (_| | |_) | (_) | |_| |__   _|  / /
 \_\  |_|\__,_|_.__/ \___/ \___/   |_|   /_/

Implementation of the climate datalogger object

*/

#include "ClimateDataLogger.hpp"

ClimateDataLogger::ClimateDataLogger(DHT& dht22,
  LiquidCrystal_I2C& lcdS, SDCard &sd, StationRtc &rtc):
  dht(dht22),
  lcd(lcdS),
  sdcard(sd),
  Srtc(rtc)
{

}

// -----------------------------------------------//

void ClimateDataLogger::begin()
{
  this->dht.begin();
  // this->sdcard.begin();
  this->Srtc.begin();
  this->lcd.begin(16, 2);
  this->lcd.clear();
  this->logTime = micros()/(1000UL * SAMPLE_INTERVAL_MS) + 1;
  this->logTime *= 1000UL * SAMPLE_INTERVAL_MS;
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

// -----------------------------------------------//

void ClimateDataLogger::save()
{
  this->logTime += 1000UL * SAMPLE_INTERVAL_MS;
  if((micros() - this->logTime) < 0)
  {
    this->sdcard.logData(this->Srtc.dateTimeNow(),
    this->readTemp(), this->readHum());
    Serial.println("aqui");
  }

}

// -----------------------------------------------//
