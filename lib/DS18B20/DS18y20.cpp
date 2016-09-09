/*Pressure Sensor
    __  _       _      ___   ___  _  _    __
  / / | | __ _| |__  ( _ ) / _ \| || |   \ \
/ /   | |/ _` | '_ \ / _ \| | | | || |_   \ \
\ \   | | (_| | |_) | (_) | |_| |__   _|  / /
 \_\  |_|\__,_|_.__/ \___/ \___/   |_|   /_/

Implementation of the Pressure Sensor object

Created by: Barbara Panosso
*/

#include "DS18y20.hpp"

// ---------------------Init method--------------------------- //

DS18y20:: DS18y20(uint8_t one_wire_bus,  uint32_t updateInterval,
  int oversampling, bool errorPrinting):
oneWire(one_wire_bus)
{
  DallasTemperature sensor(&oneWire);
  sensors = &sensor;
  this->one_wire_b = one_wire_bus;
  this->errorPrinting = errorPrinting;
  this->previousUpdate = 0;
  this->updateInterval = updateInterval;
  this->oversampling = oversampling;
  this->temp = NAN;
}

// ---------------------Public mtd--------------------------- //
void DS18y20::begin()
{
  sensors->begin();
}
// --------------------------------------------------------- //

void DS18y20::printAddress(DeviceAddress insideThermometer)
{
  for (uint8_t i = 0; i < 8; i++)
  {
    if (insideThermometer[i] < 16) Serial.print("0");
    Serial.print(insideThermometer[i], HEX);
  }
}
// --------------------------------------------------------- //
bool DS18y20::checkoutSensor()
{
    if (!sensors->getAddress(insideThermometer, this->one_wire_b))
    {
      this->printErrors(ERROR_DS18B20_SENSOR);
      // erro.log_errors(ERROR_DS18B20_SENSOR_CODE, "DS18B20", "checkoutSensor", ERROR_DS18B20_SENSOR);
      this->begin();
      return false;
    }
    else
      {
        Serial.println("Localizando sensores DS18B20...");
        Serial.print("Foi (foram) encontrado(s) ");
        Serial.print(sensors->getDeviceCount(), DEC);
        Serial.println(" sensore(s)");

          Serial.print("Endereco sensor: ");
          this->printAddress(insideThermometer);
          Serial.println();
          Serial.println();
          return true;
        }
}
// ---------------------Private mtd-------------------------- //
inline void DS18y20::printErrors(const char *msg)
{
  Serial.println(msg);
}
// --------------------------------------------------------- /
bool DS18y20::setTemperature()
{
  if(!checkoutSensor())
  {
    if(this->errorPrinting)
      this->printErrors(ERROR_DS18B20_START);
    return false;
  }
  else
  this->getTemperature();
  return true;
}
// --------------------------------------------------------- //
bool DS18y20::update()
{
  if (millis() - this->oversampling > updateInterval)
  {
    this->previousUpdate = millis();
    float ret = this->setTemperature();
    return ret;
  }
}

// --------------------------------------------------------- //
bool DS18y20::getTemperature()
{
    sensors->requestTemperatures();
    this->temp = sensors->getTempC(insideThermometer);

        if(temp >= 0)
          {
                this->printErrors(ERROR_DS18B20_NEGATIVE_TEMP);
            // erro.log_errors(ERROR_DS18B20_NEGATIVE_TEMP_CODE, "DS18B20", "getTemperature", ERROR_DS18B20_NEGATIVE_TEMP);
            }
            else
            {
                Serial.print(" Temperature: ");
                Serial.print(temp);
                return this->temp;

                String ds18b20Print = "Temperature: ";
                ds18b20Print += temp;
                Serial.println(ds18b20Print);
                }
}

// --------------------------------------------------------- //
