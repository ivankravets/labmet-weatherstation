#include "SoilHumidity.hpp"

// -------------------------------------------------------------------------- //

SoilHumidity::SoilHumidity()
{
  sensorValue = 0;
}
// -------------------------------------------------------------------------- //

bool SoilHumidity::getSoilHumidity()
{
  // Make measurement
sensorValue = analogRead(analogPin);
delay(100);
#if SOIL_DEBUG == 1
Serial.println(sensorValue);
#endif
sensorValue = map(sensorValue, 943, 506, 0, 10000);
float moisture = static_cast<float>(sensorValue)/100.0;
#if SOIL_DEBUG == 1
Serial.println(moisture);
#endif
return moisture;
}
