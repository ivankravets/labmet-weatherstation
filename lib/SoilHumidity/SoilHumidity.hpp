/*SoilHumidity
    __  _       _      ___   ___  _  _    __
  / / | | __ _| |__  ( _ ) / _ \| || |   \ \
/ /   | |/ _` | '_ \ / _ \| | | | || |_   \ \
\ \   | | (_| | |_) | (_) | |_| |__   _|  / /
 \_\  |_|\__,_|_.__/ \___/ \___/   |_|   /_/

Implementation of the Soil Humidity Sensor

Created by: Barbara Panosso
*/

#ifndef SOILHUMIDITY_HPP
#define  SOILHUMIDITY_HPP

// -------------------------------------------------------------------------- //

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

// -------------------------Debug Directives--------------------------------- //

#define SOIL_DEBUG 1

// -------------------------------------------------------------------------- //

class SoilHumidity
{
public:
  SoilHumidity();
  bool getSoilHumidity();

private:
  const int analogPin = A0;
  int sensorValue;
};

   #endif
