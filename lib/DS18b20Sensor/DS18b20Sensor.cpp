/*DS18b20Sensor
    __  _       _      ___   ___  _  _    __
  / / | | __ _| |__  ( _ ) / _ \| || |   \ \
/ /   | |/ _` | '_ \ / _ \| | | | || |_   \ \
\ \   | | (_| | |_) | (_) | |_| |__   _|  / /
 \_\  |_|\__,_|_.__/ \___/ \___/   |_|   /_/

Implementation of the DS18b20Sensor Sensor object

Created by: Barbara Panosso
*/

#include "DS18b20Sensor.hpp"

// -------------------------Init method-------------------------------------- //

DS18b20Sensor::DS18b20Sensor(uint8_t one_wire_bus,  uint32_t updateInterval,
  bool debuging):
oneWire(one_wire_bus)
{
  DallasTemperature sensor(&oneWire);
  sensors = &sensor;
  this->one_wire_b = one_wire_bus;
  this->debuging = debuging;
  this->previousUpdate = 0;
  this->updateInterval = updateInterval;
  this->temperature = NAN;
}

// -------------------------Public methods----------------------------------- //
void DS18b20Sensor::begin()
{
  sensors->begin();
  delay(150);
  this->checkSensor();
  if (debuging)
    this->searchForSensors();
}

// -------------------------------------------------------------------------- //

float DS18b20Sensor::getTemperature()
{
  this->update();
  return  this->temperature;
}

// -------------------------Private methods---------------------------------- //

void DS18b20Sensor::searchForSensors()
{
  Serial.println("Searching for One Wire sensors...");
  if (this->checkSensor())
  {
    uint8_t numberOfSensors = sensors->getDeviceCount();
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

void DS18b20Sensor::printAddress(DeviceAddress insideThermometer)
{
  for (uint8_t i = 0; i < 8; i++)
  {
    if (insideThermometer[i] < 16) Serial.print("0");
    Serial.print(insideThermometer[i], HEX);
  }
}

// -------------------------------------------------------------------------- //

bool DS18b20Sensor::checkSensor()
{
    if (!sensors->getAddress(this->thermometerAddr, this->one_wire_b))
    {
      if (this->debuging)
        this->printErrors(ERROR_DS18B20_NOT_FOUND);
      // this->begin();

      return false;
    }
    return true;
}

// -------------------------------------------------------------------------- //

bool DS18b20Sensor::setTemperature()
{
  if(!checkSensor())
  {
    if(this->debuging)
      this->printErrors(ERROR_DS18B20_START);
    return false;
  }
  sensors->requestTemperatures();
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
bool DS18b20Sensor::update()
{
  if ((millis() - this->oversampling > updateInterval) || \
  this->temperature == NAN)
  {
    this->previousUpdate = millis();
    this->setTemperature();
  }
}

// -------------------------------------------------------------------------- //
