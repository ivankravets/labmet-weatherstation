/*DS18y20
    __  _       _      ___   ___  _  _    __
  / / | | __ _| |__  ( _ ) / _ \| || |   \ \
/ /   | |/ _` | '_ \ / _ \| | | | || |_   \ \
\ \   | | (_| | |_) | (_) | |_| |__   _|  / /
 \_\  |_|\__,_|_.__/ \___/ \___/   |_|   /_/

Implementation of the DS18y20 Sensor object

Created by: Barbara Panosso
*/

#include "DS18y20.hpp"

// -------------------------Init method-------------------------------------- //

DS18y20::DS18y20(uint8_t one_wire_bus,  uint32_t updateInterval, bool debuging)
// oneWire(one_wire_bus)
{
  OneWire oneWire(one_wire_bus);
  DallasTemperature sensor(&oneWire);
  this->sensors = &sensor;
  this->one_wire_b = one_wire_bus;
  this->debuging = debuging;
  this->previousUpdate = 0;
  this->updateInterval = updateInterval;
  this->temperature = NAN;
}

// -------------------------Public methods----------------------------------- //
void DS18y20::begin()
{
  this->sensors->begin();
  delay(5000);
  Serial.println(this->sensors->getDeviceCount());
  Serial.println(this->one_wire_b);
  delay(5000);
  this->checkSensor();
  if (debuging)
    this->searchForSensors();
}

// -------------------------------------------------------------------------- //

float DS18y20::getTemperature()
{
  this->update();
  return  this->temperature;
}

// -------------------------Private methods---------------------------------- //

void DS18y20::searchForSensors()
{
  Serial.println("Searching for One Wire sensors...");
  if (this->checkSensor())
  {
    uint8_t numberOfSensors = this->sensors->getDeviceCount();
    if (numberOfSensors > 1)
    {
      Serial.print(format("It were found %d One Wire sensors\n",
       numberOfSensors));
    }
    else
    {
      Serial.print("It were found 1 One Wire sensor\n");
    }
      Serial.print(format("Sensor: "));
      this->printAddress(this->thermometerAddr);
      Serial.print("\n\n");
  }
  else
  {
    Serial.println("It was't found any One Wire sensors");
  }
}

// -------------------------------------------------------------------------- //

void DS18y20::printAddress(DeviceAddress deviceAddress)
{
  for (uint8_t i = 0; i < 8; i++)
  {
    if (deviceAddress[i] < 16) Serial.print("0");
    Serial.print(deviceAddress[i], HEX);
  }
}

// -------------------------------------------------------------------------- //

bool DS18y20::checkSensor()
{
    if (!this->sensors->getAddress(this->thermometerAddr, this->one_wire_b))
    {
      if (this->debuging)
        this->printErrors(ERROR_DS18B20_NOT_FOUND);
      this->begin();

      return false;
    }
    return true;
}

// -------------------------------------------------------------------------- //

bool DS18y20::setTemperature()
{
  if(!checkSensor())
  {
    if(this->debuging)
      this->printErrors(ERROR_DS18B20_START);
    return false;
  }
  this->sensors->requestTemperatures();
  this->temperature = sensors->getTempC(this->thermometerAddr);

  if(this->temperature == -127)
  {
    if(debuging)
      this->printErrors(ERROR_DS18B20_ABSOLUTE_NEGATIVE_TEMP);
    return false;
  }

  return true;

}

// -------------------------------------------------------------------------- //
bool DS18y20::update()
{
  if ((millis() - this->previousUpdate > updateInterval) || this->temperature == NAN)
  {
    this->previousUpdate = millis();
    this->setTemperature();
  }
}

// -------------------------------------------------------------------------- //
