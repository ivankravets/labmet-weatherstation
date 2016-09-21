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

// -------------------------Macro functions---------------------------------- //

#if defined(ESP8266)
  #include <pgmspace.h>
  #define _delay_ms(ms) delayMicroseconds((ms) * 1000)
#endif

// -------------------------Init method-------------------------------------- //

BH1750::BH1750(uint8_t BH1750Addr, uint8_t mode):
bh1750Addr(BH1750Addr), mode(mode)
{


}

// -------------------------Public methods----------------------------------- //

void BH1750::begin()
{
  switch (this->mode)
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
        Serial.println("Invalid measurement mode");
      #endif
      break;

  }
}

// -------------------------------------------------------------------------- //

uint16_t BH1750::readIlluminanceLevel()
{

}

// -------------------------Private methods---------------------------------- //

void BH1750::writeBytes(uint8_t data)
{

}

// -------------------------------------------------------------------------- //
