/*ClimateDataLogger
    __  _       _      ___   ___  _  _    __
  / / | | __ _| |__  ( _ ) / _ \| || |   \ \
/ /   | |/ _` | '_ \ / _ \| | | | || |_   \ \
\ \   | | (_| | |_) | (_) | |_| |__   _|  / /
 \_\  |_|\__,_|_.__/ \___/ \___/   |_|   /_/

Interface of the climate datalogger object

Created by: Joao Trevizoli Esteves
*/
// -----------------------------------------------//

#ifndef CLIMATEDATALOGGER_HPP
#define  CLIMATEDATALOGGER_HPP

// -----------------------------------------------//

#if ARDUINO >= 100
 #include "Arduino.h"
#endif
#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
// -----------------------------------------------//

const size_t N_LEDS = 2;

// -----------------------------------------------//

class ClimateDataLogger
{
public:
  ClimateDataLogger(const int pinSaving,
    const int pinBlocked, DHT& dht22, LiquidCrystal_I2C& lcd);
  void savingLed();
  void blockedLed();
  float readTemp();
  float readHum();
  void begin();

private:
  int ledPins[N_LEDS];
  bool saving;
  float lastTemp;
  float lastHumid;
  DHT dht;
  LiquidCrystal_I2C lcd;
};

#endif
