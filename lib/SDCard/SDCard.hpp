#ifndef SDCARD_HPP
#define SDCARD_HPP

#include <SD.h>

// -----------------------------------------------//

const size_t N_LEDS = 2;

// -----------------------------------------------//

class SDcard
{
public:
  SDcard(const uint8_t pinSaving, const uint8_t pinBlocked, uint8_t chipSelectPin);
  void blockedLed();
  void savingLed();
  void begin();

private:
  int ledPins[N_LEDS];
  bool saving;
  File logFile;
};

#endif
