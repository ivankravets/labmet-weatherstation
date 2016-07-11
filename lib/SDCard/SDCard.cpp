
#include "SDCard.hpp"


// -----------------------------------------------//

SDCard::SDCard(const uint8_t pinSaving, const uint8_t pinBlocked, uint8_t chipSelectPin):
ledPins{pinSaving, pinBlocked},
saving(false),
sd(),
logFile()
{
  for (size_t i = 0; i < N_LEDS; i++)pinMode(ledPins[i], OUTPUT);
  chipPin = chipSelectPin;
}
// -----------------------------------------------//
void SDCard::begin()
{
  pinMode(this->chipPin, OUTPUT);
  // SD.begin(this->chipPin);
  if(!this->sd.begin(this->chipPin, SPI_HALF_SPEED))
  {
    sd.initErrorHalt();
  }
  this->saving = false;
  this->openFile();
  this->csvHeader();
}
// -----------------------------------------------//
void SDCard::stop()
{
  this->logFile.sync();
  this->logFile.close();
}
// -----------------------------------------------//

void SDCard::openFile()
{
  const uint8_t BASE_NAME_SIZE = sizeof(FILE_BASE_NAME) - 1;
  char fileName[13] = FILE_BASE_NAME "00.csv";

  if (BASE_NAME_SIZE > 6) {
    error("FILE_BASE_NAME too long");
  }
  while (this->sd.exists(fileName))
  {
    Serial.println(this->sd.exists(fileName));
    if (fileName[BASE_NAME_SIZE + 1] != '9')
    {
      fileName[BASE_NAME_SIZE + 1]++;
    }
    else if (fileName[BASE_NAME_SIZE] != '9')
    {
      fileName[BASE_NAME_SIZE + 1] = '0';
      fileName[BASE_NAME_SIZE]++;
    }
    else
    {
      error("Can't create file name");
    }
  }
  Serial.println(fileName);
  if (!this->logFile.open(fileName, O_CREAT | O_WRITE | O_EXCL))
  {
    error("file.open");
  }

}
// -----------------------------------------------//
void SDCard::csvHeader()
{
  this->logFile.println(F("Data, Temperatura, Umidade"));
}
// -----------------------------------------------//
void SDCard::logData(String date, float temp, float humid)
{
    this->logFile.print(date);
    this->logFile.write(',');
    this->logFile.print(temp);
    this->logFile.write(',');
    this->logFile.print(humid);
    this->logFile.println();

    if (!logFile.sync() || logFile.getWriteError())
    {
      error("write error");
    }
}
// -----------------------------------------------//
void SDCard::blockedLed()
{
  if (this->saving)
    this->saving = false;
  digitalWrite(ledPins[0], LOW);
  digitalWrite(ledPins[1], HIGH);
}
// -----------------------------------------------//

void SDCard::savingLed()
{
  if (!this->saving)
    this->saving = true;

  digitalWrite(ledPins[0], HIGH);
  digitalWrite(ledPins[1], LOW);
}
// -----------------------------------------------//
