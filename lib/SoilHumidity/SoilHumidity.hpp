#ifndef SOILHUMIDITY_HPP
#define  SOILHUMIDITY_HPP


#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

class SoilHumidity
{
public:
  SoilHumidity();
  bool getSoilHumidity();

private:
  const int analogPin = A0;
  int sensorValue;




};

   #endif
