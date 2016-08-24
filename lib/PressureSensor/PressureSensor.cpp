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

// ---------------------Init method---------------------------//

PressureSensor::PressureSensor(SFE_BMP180 &bmp180Ptr, uint32_t updateInterval):
bmp180(bmp180Ptr)
{
  this->previousMillis = 0;
  this->temperature = NAN;
  this->pressure = NAN;
  this->altitude  = NAN;
  this->updateInterval = updateInterval;

}

// ---------------------Public mtd---------------------------//
void PressureSensor::begin()
{
  while (!this->bmp180.begin())
  {
    Serial.println("can't begin the bmp180 sensor");
    delay(100);
  }
  delay(100);
}
// ---------------------------------------------------------//
float PressureSensor::getTemperature()
{
  this->setTemperature();
  Serial.println(this->temperature);
  return this->temperature;
}
// ---------------------------------------------------------//
float  PressureSensor::getPressure(int oversampling)
{
  if (0 > oversampling || oversampling > 3)
  {
    this->printErrors("The parameter oversampling must\
be with a integer between 0 and 3");
    return false;
  }

  this->setPressure(oversampling);
  Serial.println(this->pressure);
  return this->pressure;
}
// ---------------------------------------------------------//
float  PressureSensor::getAltitude(float seaPressure)
{
  this->setAltitude(seaPressure);
  Serial.println(this->altitude);
  return this->altitude;
}
// ---------------------Private mtd--------------------------//
void  PressureSensor::printErrors(const char *msg)
{
  Serial.println(msg);
}
// ---------------------------------------------------------//
bool PressureSensor::setTemperature()
{
    status = this->bmp180.startTemperature();
    if (status == 0)
    {
      this->printErrors("Error while starting the\
temperature sensor of the bmp180 module");
      return false;
    }
    delay(status);

    status = this->bmp180.getTemperature(this->temperature);
    return true;
  }
// ---------------------------------------------------------//
bool PressureSensor::setPressure(int oversampling)
{
  status = this->bmp180.startPressure(oversampling);
  if (status == 0)
  {
    this->printErrors("Error while starting the\
pressure sensor of the bmp180 module");
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

// ---------------------------------------------------------//
bool PressureSensor::setAltitude(float seaPressure)
{
  if(this->pressure == NAN)
  {
    this->setPressure(2);
  }
  this->altitude = this->bmp180.altitude(this->pressure, seaPressure);
}


// if ((millis() - this->previousMillis) > updateInterval > updateInterval)
// {
//
// }
