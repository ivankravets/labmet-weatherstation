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
#include "SDCard.hpp"
#include "StationRTC.hpp"
// -----------------------------------------------//

const uint32_t SAMPLE_INTERVAL_MS = 300;

// -----------------------------------------------//

class ClimateDataLogger
{
public:
  ClimateDataLogger(DHT &dht22, LiquidCrystal_I2C &lcd, SDCard &sd, StationRtc &rtc);
  void begin();
  float readTemp();
  float readHum();
  void save();

private:
  float lastTemp;
  float lastHumid;
  uint32_t logTime;
  DHT dht;
  LiquidCrystal_I2C lcd;
  SDCard sdcard;
  StationRtc Srtc;

};

#endif
