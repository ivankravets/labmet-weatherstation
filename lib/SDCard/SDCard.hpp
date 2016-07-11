#ifndef SDCARD_HPP
#define SDCARD_HPP

#include <SPI.h>
#include <SdFat.h>

// -----------------------------------------------//
#define FILE_BASE_NAME "Data"

// -----------------------------------------------//

class SDCard
{
public:
  SDCard(const uint8_t chipSelectPin);
  void begin();
  void stop();
  void logData(String date, float temp, float humid);

private:
  uint8_t chipPin;
  #define error(msg) sd.errorHalt(F(msg))
  SdFat sd;
  SdFile logFile;
  void openFile();
  void csvHeader();

};

#endif
