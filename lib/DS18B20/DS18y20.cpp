#include "DS18y20.hpp"

DS18y20::DS18y20(uint8_t one_wire_bus):
oneWire(one_wire_bus)
{
  DallasTemperature sensor(&oneWire);
  sensors = &sensor;
  this->one_wire_b = one_wire_bus;
}

void DS18y20::begin()
{
  sensors->begin();

}

inline void DS18y20::printErrors(const char *msg)
{
  Serial.println(msg);
}

bool DS18y20::getTemperature()
{
  float temp;

  sensors->requestTemperatures();
  temp = sensors->getTempC(insideThermometer);

  if(temp >= 0)
  {
    Serial.println(ERROR_DS18B20_NEGATIVE_TEMP);
    // erro.log_errors(ERROR_DS18B20_NEGATIVE_TEMP_CODE, "DS18B20", "getTemperature", ERROR_DS18B20_NEGATIVE_TEMP);
  }
  else
  {
    Serial.print(" Temperature: ");
    Serial.print(temp);
    // return temp;

    String ds18b20Print = "Temperature: ";
        ds18b20Print += temp;
        Serial.println(ds18b20Print);
      }

}

bool DS18y20::update()
{
    float ret = this->getTemperature();
    // return ret;
}

// void DS18B20::setTemperature()
// {
//
// //  sendTeperatureTS(temp);
// // int count = myPeriodic;
// // while(count--)
// // delay(1000);
// }


void DS18y20::printAddress(DeviceAddress insideThermometer)
{
  for (uint8_t i = 0; i < 8; i++)
  {
    if (insideThermometer[i] < 16) Serial.print("0");
    Serial.print(insideThermometer[i], HEX);
  }
}

void DS18y20::checkoutSensor()
{
    if (!sensors->getAddress(insideThermometer, this->one_wire_b))
    {
      Serial.println(ERROR_DS18B20_SENSOR);
      printErrors(ERROR_DS18B20_SENSOR);
      // erro.log_errors(ERROR_DS18B20_SENSOR_CODE, "DS18B20", "checkoutSensor", ERROR_DS18B20_SENSOR);

    }
    else
      {
        Serial.println("Localizando sensores DS18B20...");
        Serial.print("Foi (foram) encontrado(s) ");
        Serial.print(sensors->getDeviceCount(), DEC);
        Serial.println(" sensore(s)");

          Serial.print("Endereco sensor: ");
          printAddress(insideThermometer);
          Serial.println();
          Serial.println();
        }
}
