/*ClimateDataLogger
    __  _       _      ___   ___  _  _    __
  / / | | __ _| |__  ( _ ) / _ \| || |   \ \
/ /   | |/ _` | '_ \ / _ \| | | | || |_   \ \
\ \   | | (_| | |_) | (_) | |_| |__   _|  / /
 \_\  |_|\__,_|_.__/ \___/ \___/   |_|   /_/

Interface of the climate datalogger object

Created by: Joao Trevizoli Esteves
*/

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

// const size_t N_LEDS = 2;

// -----------------------------------------------//

class ClimateDataLogger
{
public:
  ClimateDataLogger(DHT& dht22, LiquidCrystal_I2C& lcd);
  float readTemp();
  float readHum();
  void begin();

private:
  float lastTemp;
  float lastHumid;
  DHT dht;
  LiquidCrystal_I2C lcd;
};

#endif
