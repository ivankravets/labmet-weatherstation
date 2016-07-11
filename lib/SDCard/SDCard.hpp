#ifndef SDCARD_HPP
#define SDCARD_HPP

#include <SPI.h>
#include <SdFat.h>
// #include <SD.h>

// -----------------------------------------------//
#define error(msg) sd.errorHalt(F(msg))
#define FILE_BASE_NAME "Data"

const size_t N_LEDS = 2;

// -----------------------------------------------//

class SDCard
{
public:
  SDCard(const uint8_t pinSaving, const uint8_t pinBlocked, uint8_t chipSelectPin);
  void begin();
  void stop();
  void logData(String date, float temp, float humid);
  void blockedLed();
  void savingLed();

private:
  uint8_t ledPins[N_LEDS];
  bool saving;
  uint8_t chipPin;
  SdFat sd;
  SdFile logFile;
  void openFile();
  void csvHeader();

};

#endif
