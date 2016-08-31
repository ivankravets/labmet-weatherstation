/*Pressure Sensor
    __  _       _      ___   ___  _  _    __
  / / | | __ _| |__  ( _ ) / _ \| || |   \ \
/ /   | |/ _` | '_ \ / _ \| | | | || |_   \ \
\ \   | | (_| | |_) | (_) | |_| |__   _|  / /
 \_\  |_|\__,_|_.__/ \___/ \___/   |_|   /_/

Implementation of the Pressure Sensor object

Created by: Joao Trevizoli Esteves
*/

#include "PressureSensor.hpp"

// ---------------------Init method--------------------------- //

PressureSensor::PressureSensor(SFE_BMP180 &bmp180Ptr, uint32_t updateInterval,
  int oversampling, double seaPressure, bool errorPrinting):
bmp180(bmp180Ptr)
{

  this->previousUpdate = 0;
  this->temperature = NAN;
  this->pressure = NAN;
  this->altitude  = NAN;
  this->updateInterval = updateInterval;
  this->oversampling = oversampling;
  this->seaPressure = seaPressure;
  this->errorPrinting = errorPrinting;
}

// ---------------------Public mtd--------------------------- //
void PressureSensor::begin()
{
  while (!this->bmp180.begin())
  {
    if(this->errorPrinting)
      Serial.println(format(ERROR_BMP180_START));


    delay(100);
  }
  delay(100);
  this->setTemperature();
  this->setPressure();
  this->setAltitude();
}
// --------------------------------------------------------- //
float PressureSensor::getTemperature()
{
  this->update();
  return this->temperature;
}
// --------------------------------------------------------- //
float  PressureSensor::getPressure()
{
    if (0 > this->oversampling || this->oversampling > 3)
    {
      if(this->errorPrinting)
        this->printErrors(ERROR_OVERSAMPLIMP);
      return false;
    }

    this->update();
    return this->pressure;
}
// --------------------------------------------------------- //
float  PressureSensor::getAltitude()
{
  this->update();
  return this->altitude;
}
// --------------------------------------------------------- //
void PressureSensor::printAll()
{
  if((millis() - this->previousUpdate) > updateInterval)
  {
  String bmpPrintData = "Pressure: ";
  bmpPrintData += this->pressure;
  bmpPrintData += " Temperature: ";
  bmpPrintData += this->temperature;
  bmpPrintData += " Altitude: ";
  bmpPrintData += this->altitude;

  Serial.println(bmpPrintData);
  this->update();
  }
}
// ---------------------Private mtd-------------------------- //
inline void  PressureSensor::printErrors(const char *msg)
{
  Serial.println(msg);
}
// --------------------------------------------------------- //
bool PressureSensor::setTemperature()
{
    status = this->bmp180.startTemperature();
    if (status == 0)
    {
      if(this->errorPrinting)
        this->printErrors(ERROR_BMP180_TEMP_START);
      return false;
    }
    delay(status);

    status = this->bmp180.getTemperature(this->temperature);
    return true;
  }
// --------------------------------------------------------- //
bool PressureSensor::setPressure()
{
  status = this->bmp180.startPressure(this->oversampling);
  if (status == 0)
  {
    if(this->errorPrinting)
      this->printErrors(ERROR_BMP180_PRESSURE_START);
    return false;
  }

  delay(status);

  if (this->temperature != NAN)
  {
    status = this->bmp180.getPressure(this->pressure, this->temperature);
  }
  else
  {
    this->setTemperature();
    status = this->bmp180.getPressure(this->pressure, this->temperature);
  }
  return true;
}

// --------------------------------------------------------- //
bool PressureSensor::setAltitude()
{
  if(this->pressure == NAN)
  {
    this->setPressure();
  }
  this->altitude = this->bmp180.altitude(this->pressure, this->seaPressure);
  return true;
}
// --------------------------------------------------------- //
void PressureSensor::update()
{
    if((millis() - this->previousUpdate) > updateInterval)
    {
      this->previousUpdate = millis();
      this->setTemperature();
      this->setPressure();
      this->setAltitude();
    }
}
// --------------------------------------------------------- //
