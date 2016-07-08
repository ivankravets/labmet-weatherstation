/* DHT 22 sensor
    __ _       _      ___   ___  _  _    __
  / / | | __ _| |__  ( _ ) / _ \| || |   \ \
/ /   | |/ _` | '_ \ / _ \| | | | || |_   \ \
\ \   | | (_| | |_) | (_) | |_| |__   _|  / /
 \_\  |_|\__,_|_.__/ \___/ \___/   |_|   /_/

Implementation of the climate datalogger object

*/

#include "ClimateDataLogger.hpp"

ClimateDataLogger::ClimateDataLogger(const int pinSaving, const int pinBlocked, DHT& dht22, LiquidCrystal_I2C& lcdS):
  ledPins{pinSaving, pinBlocked},
  saving(false),
  dht(dht22),
  lcd(lcdS)
{

  for (size_t i = 0; i < N_LEDS; i++)pinMode(ledPins[i], OUTPUT);
  // dhtSetter(pinSensor);
}

// -----------------------------------------------//

void ClimateDataLogger::savingLed()
{
  if (!this->saving)
    this->saving = true;

  digitalWrite(ledPins[0], HIGH);
  digitalWrite(ledPins[1], LOW);
}

// -----------------------------------------------//

void ClimateDataLogger::blockedLed()
{
  if (this->saving)
    this->saving = false;
  digitalWrite(ledPins[0], LOW);
  digitalWrite(ledPins[1], HIGH);
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
  lcd.setCursor(0, 0);
  if (this->lastTemp > temp)
  {
    for (size_t i = 0; i < 16; i++)
    {
      lcd.print(" ");
    }
    lcd.setCursor(0, 0);
  }
  lcd.print(temp);
  lcd.print(" *C");
  this->lastTemp = temp;
  return temp;
}

// -----------------------------------------------//

float ClimateDataLogger::readHum()
{
  return this->dht.readHumidity();
}
