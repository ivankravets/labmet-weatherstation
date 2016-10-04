#include "SoilHumidity.hpp"


SoilHumidity::SoilHumidity()
{
  sensorValue = 0;
}

bool SoilHumidity::getSoilHumidity()
{
  // Make measurement
sensorValue = analogRead(analogPin);
delay(100);
Serial.println(sensorValue);
sensorValue = map(sensorValue, 943, 506, 0, 10000);
float moisture = static_cast<float>(sensorValue)/100.0;
Serial.println(moisture);
return moisture;
}

//
// leitura	interpretação
// 1000 <= s	Desconectado, ou não no solo
// 600 <= S <1000	seca
// 370 <= s <600	úmido
// s <370	na água
