/*BH1750
    __  _       _      ___   ___  _  _    __
  / / | | __ _| |__  ( _ ) / _ \| || |   \ \
/ /   | |/ _` | '_ \ / _ \| | | | || |_   \ \
\ \   | | (_| | |_) | (_) | |_| |__   _|  / /
 \_\  |_|\__,_|_.__/ \___/ \___/   |_|   /_/

Interface of the BH1750 Illuminace Sensor object

Created by: João Trevizoli Esteves
*/
#ifndef BH1750_HPP
#define  BH1750_HPP

#if (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif
#include "Wire.h"

// -------------------------Debug Directives--------------------------------- //

#define BH1750_DEBUG 0

// -------------------------Instructionset----------------------------------- //

// The complete instructionset is avalible at the
// sensor datasheet, of which this driver were basedn

// No active state
#define BH1750_POWER_DOWN 0x00

// Wating for measurment command
#define BH1750_POWER_ON 0x01

// Reset Data register value. Reset command is not acceptable in
// Power Down mode.
#define BH1750_RESET 0x07

// Start measurement at 1lx resolution.
// Measurement Time is typically 120ms.
#define BH1750_CONTINUOUS_H_RESOLUTION_MODE  0x10

// Start measurement at 0.5lx resolution.
// Measurement Time is typically 120ms.
#define BH1750_CONTINUOUS_H_RESOLUTION_MODE_2  0x11

// Start measurement at 4lx resolution.
// Measurement Time is typically 16ms
#define BH1750_CONTINUOUS_L_RESOLUTION_MODE  0x13

// Start measurement at 1lx resolution.
// Measurement Time is typically 120ms.
// It is automatically set to Power Down mode after measurement.
#define BH1750_ONE_TIME_H_RESOLUTION_MODE  0x20

// Start measurement at 0.5lx resolution.
// Measurement Time is typically 120ms.
// It is automatically set to Power Down mode after measurement.
#define BH1750_ONE_TIME_H_RESOLUTION_MODE_2  0x21

// Start measurement at 4lx resolution.
// Measurement Time is typically 16ms.
// It is automatically set to Power Down mode after measurement.
#define BH1750_ONE_TIME_L_RESOLUTION_MODE  0x23

// -------------------------Class Interface---------------------------------- //

class BH1750
{
public:
  BH1750(uint8_t BH1750Addr,
    uint8_t mode=BH1750_CONTINUOUS_H_RESOLUTION_MODE);
  void begin();
  uint16_t readIlluminanceLevel();

private:
  uint8_t bh1750Addr;
  uint8_t mode;
  void writeBytes(uint8_t data);
};

#endif
