#ifndef SDCARD_HPP
#define  SDCARD_HPP

#include "SdFat.h"
#include "ArduinoJson.h"

#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif


// ----------------configuration constants--------- //


class SDCard
{
public:
  SDCard();

private:
  SdFat sd;
  SdFile file;
};
#endif
