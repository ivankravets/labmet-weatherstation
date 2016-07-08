
#include "SDCard.hpp"


// -----------------------------------------------//

SDcard::SDcard(const uint8_t pinSaving, const uint8_t pinBlocked, uint8_t chipSelectPin = 4):
ledPins{pinSaving, pinBlocked},
saving(false)
{
  for (size_t i = 0; i < N_LEDS; i++)pinMode(ledPins[i], OUTPUT);

}

// -----------------------------------------------//

void SDcard::begin()
{

}
// -----------------------------------------------//

void SDcard::blockedLed()
{
  if (this->saving)
    this->saving = false;
  digitalWrite(ledPins[0], LOW);
  digitalWrite(ledPins[1], HIGH);
}
// -----------------------------------------------//

void SDcard::savingLed()
{
  if (!this->saving)
    this->saving = true;

  digitalWrite(ledPins[0], HIGH);
  digitalWrite(ledPins[1], LOW);
}
// -----------------------------------------------//
