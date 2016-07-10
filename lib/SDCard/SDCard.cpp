
#include "SDCard.hpp"


// -----------------------------------------------//

SDCard::SDCard(const uint8_t pinSaving, const uint8_t pinBlocked, uint8_t chipSelectPin):
ledPins{pinSaving, pinBlocked},
saving(false)
{
  for (size_t i = 0; i < N_LEDS; i++)pinMode(ledPins[i], OUTPUT);
  chipPin = chipSelectPin;
}

// -----------------------------------------------//

void SDCard::begin()
{
  pinMode(this->chipPin, OUTPUT);
  SD.begin(this->chipPin);
  this->saving = false;
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
