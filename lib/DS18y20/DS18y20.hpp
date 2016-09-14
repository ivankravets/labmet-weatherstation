/*DS18b20
    __  _       _      ___   ___  _  _    __
  / / | | __ _| |__  ( _ ) / _ \| || |   \ \
/ /   | |/ _` | '_ \ / _ \| | | | || |_   \ \
\ \   | | (_| | |_) | (_) | |_| |__   _|  / /
 \_\  |_|\__,_|_.__/ \___/ \___/   |_|   /_/

Interface of the DS18b20 Sensor object

Created by: Barbara Panosso
*/

#ifndef DS18Y20_HPP
#define DS18Y20_HPP

// -------------------------Errors------------------------------------------- //
#define ERROR_DS18B20_NOT_FOUND "DS18B20 sensor not found"
#define ERROR_DS18B20_START "Can't begin the ds18b20 sensor"
#define ERROR_DS18B20_ABSOLUTE_NEGATIVE_TEMP "The sensor is reading -127 *C,\
which indicates an mal function or an error"

// -------------------------Error codes-------------------------------------- //

#define ERROR_DS18B20_SENSOR_CODE 91
#define ERROR_DS18B20_START_CODE 92
#define ERROR_DS18B20_ABSOLUTE_NEGATIVE_TEMP_CODE 93

// -------------------------------------------------------------------------- //

#include <DallasTemperature.h>
#include "Errors.hpp"
#include "Format.h"

class DS18y20: public Errors
{
public:
  DS18y20(uint8_t one_wire_bus,  uint32_t updateInterval, bool debuging = true);
  // ~DS18y20();
  void begin();
  float getTemperature();

private:
  void searchForSensors();
  void printAddress(DeviceAddress deviceAddress);
  bool checkSensor();
  bool setTemperature();
  bool update();

  bool debuging;
  uint8_t one_wire_b;
  uint32_t updateInterval;
  uint32_t previousUpdate;
  float temperature;

  // OneWire oneWire;
  DallasTemperature *sensors;
  DeviceAddress thermometerAddr;

};

#endif
