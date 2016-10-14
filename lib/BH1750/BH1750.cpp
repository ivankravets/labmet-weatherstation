/*BH1750
    __  _       _      ___   ___  _  _    __
  / / | | __ _| |__  ( _ ) / _ \| || |   \ \
/ /   | |/ _` | '_ \ / _ \| | | | || |_   \ \
\ \   | | (_| | |_) | (_) | |_| |__   _|  / /
 \_\  |_|\__,_|_.__/ \___/ \___/   |_|   /_/

Interface of the BH1750 Illuminace Sensor object

Created by: João Trevizoli Esteves
*/

#include "BH1750.hpp"

// -------------------------Defines------------------------------------------ //

#define BH1750_ADDR 0x23

// -------------------------Macro functions---------------------------------- //

#if defined(ESP8266)
  #include <pgmspace.h>
  #define _delay_ms(ms) delayMicroseconds((ms) * 1000)
#endif

#ifdef __avr__
  #include <util/delay.h>
#endif

#define _intensity_lvl(rawMeasure) rawMeasure/1.2

// -------------------------Init method-------------------------------------- //

BH1750::BH1750(uint8_t mode):
 mode(mode)
{

}

// -------------------------Public methods----------------------------------- //

void BH1750::begin()
{
  Wire.begin();
  setMode(mode);
}

// -------------------------------------------------------------------------- //

uint16_t BH1750::readIlluminanceLevel()
{
  this->readBytes();
  uint16_t actualReading = _intensity_lvl(rawReading);

  #if BH1750_DEBUG == 1
    if (rawReading == NAN || rawReading == 65535)
      Serial.println("The BH1750 Illuminance sensor were not found!");
  #endif
  return actualReading;
}

// -------------------------------------------------------------------------- //

uint16_t BH1750::readRawValue()
{
  this->readBytes();
  #if BH1750_DEBUG == 1
    if (rawReading == NAN || rawReading == 65535)
      Serial.println("The BH1750 Illuminance sensor were not found!");
  #endif
  return rawReading;
}

// -------------------------Private methods---------------------------------- //

void BH1750::writeBytes(uint8_t data)
{
  Wire.beginTransmission(BH1750_ADDR);
  #if (ARDUINO >= 100)
    Wire.write(data);
  #else
    Wire.send(data);
  #endif
  Wire.endTransmission();
}

// -------------------------------------------------------------------------- //

void BH1750::readBytes()
{
  Wire.beginTransmission(BH1750_ADDR);
  Wire.requestFrom(BH1750_ADDR, 0x02);
  #if (ARDUINO >= 100)
    rawReading = Wire.read();
    rawReading <<= 8;
    rawReading |= Wire.read();
  #else
    rawReading = Wire.receive();
    rawReading <<= 8;
    rawReading |= Wire.receive();
  #endif
  Wire.endTransmission();

}

// -------------------------------------------------------------------------- //

void BH1750::setMode(uint8_t mode)
{
  switch (mode)
  {
    case BH1750_CONTINUOUS_H_RESOLUTION_MODE:
    case BH1750_CONTINUOUS_H_RESOLUTION_MODE_2:
    case BH1750_CONTINUOUS_L_RESOLUTION_MODE:
    case BH1750_ONE_TIME_H_RESOLUTION_MODE:
    case BH1750_ONE_TIME_H_RESOLUTION_MODE_2:
    case BH1750_ONE_TIME_L_RESOLUTION_MODE:
      writeBytes(mode);
      _delay_ms(10);
      break;
    default:
      #if BH1750_DEBUG == 1
        Serial.println("The sensor doesn't recognize this measurement mode!");
        Serial.println("Please read sensor class interface to \
see what are the accepted measurement modes!");
      #endif
      break;
  }
}
// -------------------------------------------------------------------------- //
