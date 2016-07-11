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
  LiquidCrystal_I2C& lcdS, StationRtc &rtc,
  uint8_t csPin, uint8_t greenLed, uint8_t redLed):
  dht(dht22),
  lcd(lcdS),
  r(rtc),
  card(4),
  ledPins{greenLed, redLed}
{

}

// -----------------------------------------------//

void ClimateDataLogger::begin()
{
  for (size_t i = 0; i < N_LEDS; i++)pinMode(ledPins[i], OUTPUT);
  this->dht.begin();
  this->lcd.begin(16, 2);
  this->lcd.clear();
  this->r.begin();
  this->card.begin();
  this->logTime = SAMPLE_INTERVAL_MS;
}

// -----------------------------------------------//

void ClimateDataLogger::stop(uint8_t resetPin, uint8_t resetButton)
{
  uint8_t buttonReading = digitalRead(resetButton);
  uint8_t turnOffArduino = 0;
  if (buttonReading)
  {
    this->blockedLed();
    this->lcd.clear();
    this->card.stop();

    lcd.setCursor(0, 0);
    lcd.print("Remova o cartao");
    lcd.setCursor(0, 1);
    lcd.print("e aperte o botao");
    while (!turnOffArduino)
    {
      delay(1000);
      turnOffArduino = digitalRead(resetButton);
    }

    for (size_t i = 0; i < 5; i++)
    {
      this->savingLed();
      delay(100);
      this->blockedLed();
      delay(100);
    }
    this->lcd.clear();
    this->lcd.setCursor(0, 0);
    this->lcd.print("Reiniciando!");
    delay(150);
    pinMode(resetPin, OUTPUT);
    digitalWrite(resetPin, LOW);
  }
}


// -----------------------------------------------//

void ClimateDataLogger::save()
{
  uint32_t currentMillis = millis();
  if(currentMillis - this->logTime > SAMPLE_INTERVAL_MS)
  {
    digitalWrite(this->ledPins[0], HIGH);
    this->logTime = currentMillis - 1;
    this->card.logData(this->r.dateTimeNow(),
    this->readTemp(), this->readHum());
  }
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

void ClimateDataLogger::blockedLed()
{
  digitalWrite(ledPins[0], LOW);
  digitalWrite(ledPins[1], HIGH);
}
// -----------------------------------------------//

void ClimateDataLogger::savingLed()
{
  digitalWrite(ledPins[0], HIGH);
  digitalWrite(ledPins[1], LOW);
}

// -----------------------------------------------//
